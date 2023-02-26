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
      //Variables de temperatura , modo y ciclo
      bool x=true;
      char a;
      float temperatura1, temperatura2;
      
      //Se limpia pantalla y se imprime el modo
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"MODO AUTOM.");
      delay_ms(1500);
      
      //Inicio de bucle autimatico
      while(x){
      
         //Lectura de los canales analogicos y almacenamiento
         set_adc_channel(0);
         temp1=read_adc();
         set_adc_channel(1);
         temp2=read_adc();
         delay_ms(1000);
         printf(lcd_putc,"\f");
         
         //Conversion de ADC a temperatura
         temperatura1=(((float)temp1)*5/1023)*100;
         temperatura2=(((float)temp2)*5/1023)*100;
         
         if(temperatura1>=30.0){   //Rango de encendido motor 1
            //Se activa el motor y se imprime el estado
            output_low(PIN_A4);
            output_high(PIN_A5);
            set_pwm1_duty(1000);   
            
            lcd_gotoxy(1,1);
            printf(lcd_putc,"T1:%fC V1:E", temperatura1);
            printf("T1:%fC  V1:E  M:A   \n\r", temperatura1);
            
         }
         else if(temperatura1<30.0){   //Rango de apagado motor 1
            //Se apaga el motor y se imprime el estado
            output_low(PIN_A4);
            output_low(PIN_A5);
            set_pwm1_duty(0);    //Fijado de ciclo de trabajo en 0%
            lcd_gotoxy(1,1);
            printf(lcd_putc,"T1:%fC V1:A", temperatura1);
            
            printf("T1:%fC  V1:A  M:A\n\r", temperatura1);
      
         }
         
         if(temperatura2>=30.0){   //Rango de encendido motor 2
            //Se activa el motor y se imprime el estado
            output_low(PIN_A6);
            output_high(PIN_A7);
            set_pwm2_duty(1000);
            
            lcd_gotoxy(1,2);
            printf(lcd_putc,"T2:%fC V2:E", temperatura2);
            printf("T2:%fC  V2:E  M:A\n\r", temperatura2);
                      
         }
         else if(temperatura2<30.0){    //Rango de apagado motor 2
            //Se apaga el motor y se imprime el estado
            output_low(PIN_A6);
            output_low(PIN_A7);       
            set_pwm2_duty(0);
            
            lcd_gotoxy(1,2);
            printf(lcd_putc,"T2:%fC V2:A", temperatura2);
            
            printf("T2:%fC  V2:A  M:A\n\r", temperatura2);
   
         }
         //Lectura de entrada para cambio de modo
         a=getch();
         //Caracter para cambio de modo a manual
         if(a=='M'){
            //Regresa caracter M
            return a;
            x=false;                     
         }
        
     }
}

char manual(int16 temp1, int16 temp2){
   //Variables de temperatura , modos y ciclo
   bool x=true;
   char op;
   char m1='A';
   char m2='A';
   float temperatura1, temperatura2;
   
   //Se apagan los motores por defecto
   output_low(PIN_A4);
   output_low(PIN_A5); 
   
   output_low(PIN_A6);
   output_low(PIN_A7);
   
   //Se imprime el modo actual
   printf(lcd_putc,"\f");
   lcd_gotoxy(1,1);
   printf(lcd_putc,"MODO MANUAL");
   delay_ms(1500);
   
   while(x){
      //Lectura de ADC de los dos sensores
      set_adc_channel(0);
      temp1=read_adc();
      set_adc_channel(1);
      temp2=read_adc();
      //Transformacion a temperatura
      temperatura1=(((float)temp1)*5/1023)*100;
      temperatura2=(((float)temp2)*5/1023)*100;
      
      //Se imprime en la terminal y en la LCD el estado de las variables
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"T1:%fC V1:%c", temperatura1, m1);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"T2:%fC V2:%c", temperatura2, m2);
      
      printf("T1:%fC  V1:%c  M:M    \n\r", temperatura1, m1);
      printf("T2:%fC  V2:%c  M:M\n\r", temperatura2, m2);
      
      delay_ms(1000);
      
      //Se lee caracter para poder saber que elementos encender o como operarlos
      op=getch();
      
      switch(op){
      
      //Caso 1 todo apagado
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
      
       //Caso 2 se enciende solamente el motor 1
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
      
      //Caso 3 se enciende solamente el motor 2
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
      
       //Caso 4 se encienden ambos motores
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
      
      //Caso A se encarga de cambiar al modo automatico
      case 'A':
      //Actualiza y retorna variables
      op='A';
      return op;
      x=false;
      break;
      //Si se da otro caso, no se hace nada
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
   setup_ccp2(CCP_PWM);    //Se configura ccp2 para usar pwm
   
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


