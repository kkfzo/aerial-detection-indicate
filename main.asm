#include "TM57PE12.inc"  
#include "system.inc"
.autoimport on
				
	org	00h	  
	goto	start 
	org	10h	 

start: 					;system Initialization 
        movlw	00000000b
	movwf	pad
		 
	movlw	00000000b
	movwf	pbd          		;I/O out=0	 
		
	movlw	11111111b       	
	movwr	pae					
		
	movlw	11111111b       	
	movwr	pbe					;I/O State is input
		
        movlw	11111111b 
        movwr 	papu				
         
        movlw	11111111b 
        movwr 	pbpu				;disable up-pull 
        
	movlw	00000000b
	movwf	intf				;close all interrupt flag
		
        movlw	00100000b
        movwf 	inte 				;close all interrupt
        
	movlw	0x20
	movwf	fsr	
clr_bank0:		
	movlw	0x00
	movwf	indf
	incf	fsr,1
	movfw	fsr
	xorlw	0x4f
	btfss	status,2
	goto	clr_bank0
	movlw	0x00
	movwf	indf  				;clear all RAM   		
                 				
        call    sysio_init
main:  
        ;clrwdt
main_input_check:
        btfss   INPUT_A
        goto    main_input_check_b1             ;input a = 0
        goto    main_input_check_b2             ;input b = 1
main_input_check_b1
        btfss   INPUT_B
        goto    main_led_gg                ;input b = 0,a = 0
        goto    main_led_yy                ;input b = 1,a = 0
main_input_check_b2
        btfss   INPUT_B
        goto    main_led_yy                ;input a = 1,b = 0
        goto    main_led_rr                ;input a = 1,b = 1
main_led_gg                    ;ledÂÌ¹â 
        bsf     LED_GG
        bcf     LED_RR
        goto    main
main_led_rr                    ;ledºì¹â 
        bsf     LED_RR
        bcf     LED_GG
        goto    main
main_led_yy                    ;led»ìÉ« 
        bsf     LED_RR
        bsf     LED_GG 
        goto    main
        end
        
   