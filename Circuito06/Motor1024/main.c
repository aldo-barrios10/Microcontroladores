#include<16f887.h>
#fuses INTRC_IO,NOWDT,PROTECT,NOLVP,MCLR,NOBROWNOUT
#device ADC=10
#use delay(INTERNAL=4000000)
#include<lcd.c>
#include <math.h>

void main()
{

   signed int16 transf, valor;
   
   lcd_init();
   setup_ccp1(CCP_PWM);    //Se configura ccp1 para usar pwm 
   
   setup_timer_2(T2_DIV_BY_16,1023,1);  // Timer a usar
   
   set_pwm1_duty(0);    //Fijado de ciclo de trabajo en 0%
   
   setup_adc_ports(sAN0);  //Puerto analogico para muestreo
   setup_adc(ADC_CLOCK_INTERNAL);   // Reloj interno
   
   while(TRUE)
   {
      set_adc_channel(0);
      valor=read_adc();
      
      if(valor<514 && valor>509){   //Rango muesrto es de 513 a 510
         output_low(PIN_C0);
         output_low(PIN_C1);
         
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Motor Apagado");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Velocidad: 0%%");
         delay_ms(1000);
         set_pwm1_duty(0);
      }
      
      else if(valor<510){
         output_high(PIN_C0);
         output_low(PIN_C1);
         
         transf=fabs((valor/2)-255);
         set_pwm1_duty(transf*4);        //Aqui transf tiene valor de 0 a 255
         transf = transf*100/255;
         
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Motor Derecha");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Velocidad: %lu %%", transf);
         delay_ms(1000);
         
      }
      
      else if(valor>513){
         output_high(PIN_C1);
         output_low(PIN_C0);
         
         transf=fabs((valor/2)-255);
         set_pwm1_duty(transf*4);          //Aqui transf tiene valor de 0 a 255
         transf = transf*100/255;
         
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Motor izquierda");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Velocidad: %lu %%",transf);

         delay_ms(1000);
      }
      

   }

}
