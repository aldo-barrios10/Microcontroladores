#include<16f887.h>
#device ADC=10
#fuses INTRC_IO,NOWDT,PROTECT,NOLVP,MCLR,NOBROWNOUT
#use delay(INTERNAL=4000000)
#include<lcd.c>
#include <math.h>
#include <stdbool.h>
//Configuración para enviar y recibir mensaje en terminal serial
#use RS232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, timeout=100)



char automatico(int16 temp1, int16 temp2){

      bool x=true;
      char a;
      char m1='A';
      char m2='A';
      
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"MODO AUTOM.");
      delay_ms(1500);
      
      while(x){
      
         set_adc_channel(0);
         temp1=read_adc();
         set_adc_channel(1);
         temp2=read_adc();
         delay_ms(1000);
         printf(lcd_putc,"\f");
         
         if(temp1>512){   //Rango muesrto es de 513 a 510
            output_low(PIN_A4);
            output_high(PIN_A5);
            set_pwm1_duty(temp1);   
            
            lcd_gotoxy(1,1);
            printf(lcd_putc,"T1: %Lu V1: E", temp1);
            m1='E';
            
            
            
         }
         else if(temp1<512){
            output_low(PIN_A4);
            output_low(PIN_A5);
            set_pwm1_duty(0);    //Fijado de ciclo de trabajo en 0%
            lcd_gotoxy(1,1);
            printf(lcd_putc,"T1: %Lu V1: A", temp1);
            m1='A';
       
   
         }
         
         if(temp2>512){   //Rango muesrto es de 513 a 510
            output_low(PIN_A6);
            output_high(PIN_A7);
            set_pwm2_duty(temp2);
            
            lcd_gotoxy(1,2);
            printf(lcd_putc,"T2: %Lu V2: E", temp2);
            m2='E';
            
            
         }
         else if(temp2<512){
            output_low(PIN_A6);
            output_low(PIN_A7);       
            set_pwm2_duty(0);
            
            lcd_gotoxy(1,2);
            printf(lcd_putc,"T2: %Lu V2: A", temp2);
            
            m2='A';
   
         }
         
         a=getch();
         if(a=='M'){
            return a;
            x=false;                     
         }
         
         if(a=='5'){
            printf("T1: %Lu V1: %c M:A   \n\r", temp1, m1);
            printf("T2: %Lu V2: %c M:A\n\r", temp2, m2);
            delay_ms(1000);
         }
     }
}

char manual(int16 temp1, int16 temp2){
   bool x=true;
   char op;
   char m1='A';
   char m2='A';
   
   output_low(PIN_A4);
   output_low(PIN_A5); 
   
   output_low(PIN_A6);
   output_low(PIN_A7);
   printf(lcd_putc,"\f");
   lcd_gotoxy(1,1);
   printf(lcd_putc,"MODO MANUAL");
   delay_ms(1500);
   
   while(x){
   
      set_adc_channel(0);
      temp1=read_adc();
      set_adc_channel(1);
      temp2=read_adc();
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"T1: %Lu V1: %c", temp1, m1);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"T2: %Lu V2: %c", temp2, m2);
      
      
      delay_ms(1000);
   
      op=getch();
      
      switch(op){
      
      //Caso A imprime un mensaje en LCD
      case '1':
      
      output_low(PIN_A4);
      output_low(PIN_A5); 
      set_pwm1_duty(0);
      output_low(PIN_A6);
      output_low(PIN_A7);
      set_pwm2_duty(0);
      m1='A';
      m2='A';
 
   
      break;
      
       //Caso B imprime un mensaje en LCD
      case '2': 
      
      output_low(PIN_A4);
      output_high(PIN_A5); 
      set_pwm1_duty(1020);
      output_low(PIN_A6);
      output_low(PIN_A7);
      set_pwm2_duty(0);
      m1='E';
      m2='A';
      break;
      
      case '3':
      output_low(PIN_A4);
      output_low(PIN_A5); 
      set_pwm1_duty(0);
      output_low(PIN_A6);
      output_high(PIN_A7);
      set_pwm2_duty(1020);
      m1='A';
      m2='E';
      break;
      
       //Caso B imprime un mensaje en LCD
      case '4': 
      output_low(PIN_A4);
      output_high(PIN_A5); 
      set_pwm1_duty(1020);
      output_low(PIN_A6);
      output_high(PIN_A7);
      set_pwm2_duty(1020);
      m1='E';
      m2='E';
      break;
      
      case '5': 
      printf("T1: %Lu V1: %c M:M    \n\r", temp1, m1);
      printf("T2: %Lu V2: %c M:M\n\r", temp2, m2);
      delay_ms(1000);
      break;
      
      case 'A':
      op='A';
      return op;
      x=false;
      break;
      
      default:
      
      break;
            
      }
   }
}

void main()
{
   //Variable de ADC y caracter de protocolo
   int16 temp1, temp2;
   char modo = 'A';
   
   //char protocolo;
   lcd_init();
   
   setup_ccp1(CCP_PWM);    //Se configura ccp1 para usar pwm 
   setup_ccp2(CCP_PWM);
   
   setup_timer_2(T2_DIV_BY_16,1023,1);  // Timer a usar
   
   set_pwm1_duty(0);    //Fijado de ciclo de trabajo en 0%
   set_pwm2_duty(0);
   
   //Puerto analogico
   setup_adc_ports(sAN0, sAN1);
   setup_adc(ADC_CLOCK_INTERNAL);
   
   

   while(TRUE)
   {
      
    
      switch(modo){
       
         //Modo automatico
         case 'A':
         printf("--------MODO AUTOMATICO--------\n\r");
         modo=automatico(temp1,temp2);
         break;
         
         //Modo manual
         case 'M': 
         printf("--------MODO MANUAL--------\n\r");
         modo=manual(temp1, temp2);
         break;
         
         //Nunca entra aqui
         default:
            
         break;
      
      

   }
   
   }

}


