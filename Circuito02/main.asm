; * * * * * * * * * * * * * * * * * * * * * * * * * * * *
; *                                                     *
; *     Universidad  Nacional  Autonoma  de  Mexico     *
; *      Facultad de Estudios  Superiores Aragon        *
; *                                                     *
; *       Microprocesadores y Microcontroladores        *
; *                                                     *
; *         Práctica 2  								*
; *         Comparador de puertos    	              	*
; * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; * * * * * * * * * * * * * * * * * * * * * * * * * * * *
; * Este programa compara los bits del puerto A y C		*
; * dependiendo del resultado se mostrará una 		    *
; * combinación en el puerto B                          *
; *                                                     *
; * Seccion CONFIGURACION:                              *
; *  El puerto A y C es configurado como entrada digital*
; *  El puerto B es configurado como salida digital     *
; *                                                     *
; * 													*
; * * * * * * * * * * * * * * * * * * * * * * * * * * * *



#include <P16F887.INC>

	__CONFIG _CONFIG1, _INTOSCIO & _MCLRE_OFF & _WDT_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF &  _BOR_OFF & _PWRTE_ON & _FCMEN_OFF & _IESO_OFF


	ORG 00h
CONFIGURACION

	BCF	STATUS,RP1        	; Cambio al banco 1
	BSF 	STATUS,RP0

	MOVLW	b'11111111'		; Configurar puerto A como entrada
	MOVWF 	TRISA
	MOVLW	b'11111111'		; Configurar puerto C como entrada
	MOVWF 	TRISC
	MOVLW 	b'00000000'     	; Configurar puerto B como salida
	MOVWF 	TRISB
	
	BSF 	STATUS, RP1	        ; Cambio al banco 3
	BSF 	STATUS, RP0
	CLRF 	ANSEL	        	; Inicializar ANSELH para que Puerto B sea configurado como digital

	BCF 	STATUS, RP1	        ; Cambio al Banco 0
	BCF 	STATUS, RP0

	CLRF 	PORTB           	; Inicializa el Registro del Puerto D

PRINCIPAL
	MOVF 	PORTC,W		         ; Mueve el contenido de PORTC a W
	SUBWF   PORTA
	BTFSC	STATUS,Z 			;Si Z es igual a 0 se salta a la siguiente linea
	GOTO	ESIGUAL				;Entramos a la rutina ESIGUAL
	BTFSS 	STATUS,C			;Si C es igual a 1 se salta a la siguiente linea
	GOTO	ESMENOR				;Entramos a la rutina ESMENOR
	GOTO	ESMAYOR				;Entramos a la rutina ESMAYOR

ESIGUAL
	MOVLW 	b'10101010'			;Asignamos a W el valor que tendrá nuestra salida
	MOVWF	PORTB				;Colocamos el contenido de W en PORTB
	GOTO	PRINCIPAL			;Regresamos a la rutina principal

ESMAYOR
	MOVLW 	b'11110000'			;Asignamos a W el valor que tendrá nuestra salida
	MOVWF	PORTB				;Colocamos el contenido de W en PORTB
	GOTO	PRINCIPAL			;Regresamos a la rutina principal
	
ESMENOR
	MOVLW 	b'00001111'
	MOVWF	PORTB
	GOTO	PRINCIPAL
	END





