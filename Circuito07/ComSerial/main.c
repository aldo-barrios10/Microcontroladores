#include<16f887.h>
#device ADC=10
#fuses INTRC_IO,NOWDT,PROTECT,NOLVP,MCLR,NOBROWNOUT
#use delay(INTERNAL=4000000)
#include<lcd.c>

//Configuración para enviar y recibir mensaje en terminal serial
#use RS232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, timeout=100)



void main()
{
   //Variable de ADC y caracter de protocolo
   int16 iVolt;
   char protocolo;
   lcd_init();
   //Puerto analogico
   setup_adc_ports(sAN0);
   setup_adc(ADC_CLOCK_INTERNAL);

   

   while(TRUE)
   {
      //Lectura de ADC
      iVolt=read_adc();
      delay_ms(1000);
      //Imprime en terminal serial
      printf("El ADC es de: %Lu\n\r", iVolt);
      
      //Espera a obtener el caracter de la terminal serial
      protocolo=getch();
      
      //Seleccion de protocolo
      switch(protocolo){
         
         //Caso A imprime un mensaje en LCD
         case 'A':
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Prtocolo A:");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Buen dia");
         //Delay para poder ver claramente el mensaje
         delay_ms(2000);
         break;
         
          //Caso B imprime un mensaje en LCD
         case 'B': 
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Prtocolo B:");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Buenas noches");
         //Delay para poder ver claramente el mensaje
         delay_ms(2000);
         break;
         
         //En el caso de que no exista una entrada 
         default:
         //Imprime mensaje para indicarlo
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Sin protocolo");
         delay_ms(1000);
         break;
         
      }

   }

}


