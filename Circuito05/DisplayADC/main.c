#include<16f887.h>
//BITS PARA MUESTREOS
#device ADC=10
#fuses INTRC_IO,NOWDT,PROTECT,NOLVP,MCLR,NOBROWNOUT
//ESTABLECER PUERTO D PARA LCD
//#define LCD_DATA_PORT getenv("SFR:PORTD")
#use delay(INTERNAL=4000000)
#include <lcd.c>

void main(){
   //VARIABLES PARA OPERAR Y MOSTRAR (16b)
   int16 iVolt;
   int voltaje;
   int16 angulo;
   lcd_init();
   //ACTIVAR EL PUERTO PARA SE�AL ANALOGICA
   setup_adc_ports(sAN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   
   while(TRUE){
      //ASIGNAMOS A LAS VARIABLES EL VALOR DEL MUESTREO
      iVolt=read_adc();
      //OPERACI�N PARA MOSTRAR ANGULO Y VOLTAJE
      angulo = (iVolt*270)/1021;
      voltaje = (iVolt*5)/1021;
      
      //SE IMPRIMEN LOS VALORES EN LCD
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Voltaje: %i",voltaje);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Angulo: %Lu",angulo);
      delay_ms(1000);
      
   }

}






