#include<16f887.h>
#device ADC=10
#fuses INTRC_IO,NOWDT,PROTECT,NOLVP,MCLR,NOBROWNOUT
#use delay(INTERNAL=4000000)
#include <lcd.c>

void main()
{
   int16 puerto1;
   int16 puerto2;
   lcd_init();
   
   setup_adc_ports(sAN0, sAN1);
   setup_adc(ADC_CLOCK_INTERNAL);
   lcd_init();

   while(TRUE)
   {
   
      set_adc_channel(0);
      puerto1=read_adc();

      set_adc_channel(1);
      puerto2=read_adc();
      //SE IMPRIMEN LOS VALORES EN LCD
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Sensor 1: %Lu",puerto1);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Sensor 2: %Lu",puerto2);
      delay_ms(1000);
   }

}
