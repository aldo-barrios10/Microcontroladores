//Ejercicio Pantalla LCD
#include<16f887.h>
#fuses INTRC_IO,NOWDT,PROTECT,NOLVP,MCLR,NOBROWNOUT
//Asignaci�n de puerto D para LCD
#define LCD_DATA_PORT getenv("SFR:PORTD")
#use delay(INTERNAL=4000000)

//Libreria para usar LCD
#include<lcd.c>

void main()
{
   //INICIALIZA LCD
   lcd_init();
   while(true)
   {  
      //LIMPIA LA PANTALLA
      printf(lcd_putc,"\f");
      //RENGLON 1 POSICI�N 3
      lcd_gotoxy(3,1);
      printf(lcd_putc,"Mexico pumas");
      //RENGLON 2 POSICI�N 3
      lcd_gotoxy(3,2);
      printf(lcd_putc,"Universidad!");
      delay_ms(1000);
      //LIMPIA PANTALLA
      printf(lcd_putc,"\f");
      //RENGLON 1 POSICI�N 3
      lcd_gotoxy(3,1);
      printf(lcd_putc,"Goyaaaaaaaa");
      //RENGLON 2 POSICI�N 3
      lcd_gotoxy(3,2);
      printf(lcd_putc,"Goyaaaaaaaa");
      delay_ms(1000);
   }
}


