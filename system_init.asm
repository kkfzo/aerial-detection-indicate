#include "TM57PE12.inc"  
#include "system.inc"

.export sysio_init

;=======================================================================
sysio_init:
        	;-----------------------------------
                ;PA7:P33(input)
                ;PA6:N/A
                ;PA5:N/A
                ;PA4:N/A 
                ;PA3:P34(input)
                ;PA2:LED_RR(output)
                ;PA1:LED_GG(output)
                ;PA0:LED_BB(output)
                ;-----------------------------------
                movlw   00000111b       ;set 0 input , 1 output        
        	movwr   pae

                movlw   00000000b       ;�ر����� 0��,1�ر� 
                movwr   papu
        
        
                movlw   10001000b       ;���Ϊ1����Ϊ˹���ش������� 
                movwf   pad

                ret
                