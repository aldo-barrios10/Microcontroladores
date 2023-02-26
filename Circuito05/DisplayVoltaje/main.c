#include<16f887.h>
//BITS PARA MUESTREOS
#device ADC=10
#fuses INTRC_IO,NOWDT,PROTECT,NOLVP,MCLR,NOBROWNOUT
#use delay(INTERNAL=4000000)
#include <lcd.c>

void main(){
   //VARIABLES PARA OPERAR Y MOSTRAR (16b)
   int32 iAnalog;
   int voltaje;
   int32 angulo;
   lcd_init();
   
   //ACTIVAR EL PUERTO PARA SE�AL ANALOGICA
   setup_adc_ports(sAN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   
   while(TRUE){
      //ASIGNAMOS A LAS VARIABLES EL VALOR DEL MUESTREO
      iAnalog=read_adc();
      //OPERACI�N PARA MOSTRAR ANGULO Y VOLTAJE (1022 porque el potenciometro 
      //(1022 porque el potenciometro no llega a los 1023)
      angulo = (iAnalog*270)/1022;
      voltaje = (iAnalog*5)/1022;
      
      //SE IMPRIMEN LOS VALORES EN LCD
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Voltaje: %i",voltaje);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Angulo: %ld",angulo);
      delay_ms(1000);   
   }
}



