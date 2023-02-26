#include<16f887.h>
#device ADC=10
#fuses INTRC_IO,NOWDT,PROTECT,NOLVP,MCLR,NOBROWNOUT
#use delay(INTERNAL=4000000)
#include<lcd.c>
#use RS232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, timeout=100)

void main()
{

   int16 iVolt;

   lcd_init();
   setup_adc_ports(sAN0);
   setup_adc(ADC_CLOCK_INTERNAL);

   

   while(TRUE)
   {
      iVolt=read_adc();
      delay_ms(1000);
      printf("El ADC es de: %Lu\n\r", iVolt);
      
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"El ADC es: %Lu", iVolt);
      delay_ms(1000);
      
      

   }

}

