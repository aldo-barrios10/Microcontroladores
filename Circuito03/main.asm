; * * * * * * * * * * * * * * * * * * * * * * * * * * * *
; *                                                     *
; *     Universidad  Nacional  Autonoma  de  Mexico     *
; *      Facultad de Estudios  Superiores Aragon        *
; *                                                     *
; *       Microprocesadores y Microcontroladores        *
; *                                                     *
; *         Práctica 1 Ver 				*
; *         Replica de puertos                   	*
; *                                                     *
; * 	 TEMAS:                                         *
; *             Manejo del juego de instruciones        *
; *             Configuracion de Puertos como E/S       *
; *             Manipulacion de datos                   *
; *                                                     *
; *             Microcontrolador: PIC16F887             *
; *             Oscilador: 8 MHz interno                *
; *                                                     *
; * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; * * * * * * * * * * * * * * * * * * * * * * * * * * * *
; * Este programa enciende y apaga los leds en puerto D *
; * dependiendo del estado del dipswitch en puerto B    *
; *                                                     *
; * Seccion CONFIGURACION:                              *
; *  El puerto B es configurado como entrada digital    *
; *  El puerto D es configurado como salida digital     *
; *                                                     *
; * Seccion PRINCIPAL:                                  *
; *  Se realiza una lectura del puerto B al registro w  *
; *  Se escribe en el puerto D el valor del registro w  *
; * * * * * * * * * * * * * * * * * * * * * * * * * * * *


#include <P16F887.INC>

	__CONFIG _CONFIG1, _INTOSCIO & _MCLRE_OFF & _WDT_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF &  _BOR_OFF & _PWRTE_ON & _FCMEN_OFF & _IESO_OFF


	ORG 00h
CONFIGURACION

	; Cambio al banco con las posiciones del registro "01"

	BCF		STATUS,RP1        	; Cambio al banco 1
	BSF 	STATUS,RP0

	MOVLW	b'11111111'		; Configurar puerto A como entrada
	MOVWF 	TRISA
	MOVLW 	b'00000000'     	; Configurar puerto B como salida
	MOVWF 	TRISB
	

	; Cambio al banco con las posiciones del registro "11"

	BSF 	STATUS, RP1	        ; Cambio al banco 3
	BSF 	STATUS, RP0

	CLRF 	ANSEL	        	; Inicializar ANSEL para que Puerto A sea configurado como digital
	CLRF 	ANSELH


	; Cambio al banco con las posiciones del registro "00"

	BCF 	STATUS, RP1	        ; Cambio al Banco 0
	BCF 	STATUS, RP0

	CLRF 	PORTB           	; Inicializa el Registro del Puerto B

PRINCIPAL
	MOVF 	PORTA,W				; Mueve el contenido de PORTA a W
	ANDLW	b'00001111'			; Solo pasa el nible bajo
	CALL 	BINHEX				; Codifica W en codigo 7 segmentos
	MOVWF	PORTB	        	; Mueve el contenido de W a PORTB
	GOTO 	PRINCIPAL

BINHEX

	ADDWF	PCL, F
	
	RETLW	b'00111111'		;0 
	RETLW	b'00000110'		;1
	RETLW	b'01011011'		;2
	RETLW	b'01001111'		;3
	RETLW	b'01100110'		;4
	RETLW	b'01101101'		;5
	RETLW	b'01111101'		;6
	RETLW	b'00000111'		;7
	RETLW	b'01111111'		;8
	RETLW	b'01100111'		;9
	RETLW	b'01110111'		;A
	RETLW	b'01111100'		;B
	RETLW	b'00111001'		;C
	RETLW	b'01011110'		;D
	RETLW	b'01111001'		;E
	RETLW	b'01110001'		;F
	
	END

	