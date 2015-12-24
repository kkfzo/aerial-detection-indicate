;-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
;-*-*-*-*-*-*-*-*-*-**-*-*- F--Plane *-*-*-*--*-*-*-*-*-*-*--*-*-*-*-*-*-*-
;-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
indf            	equ   	00h   	;Indirect addressing register
tmr0          		equ   	01h   	;Timer0 content
pc              	equ   	02h   	;Program counter
;--------------------------------------------------------------------------
status			equ   	03h   	;Status register
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
gbit1       	equ   6         	;General purpose bit
to          	equ   4         	;WDT time out flag
pd          	equ   3         	;Sleep mode flag
z           	equ   2         	;Zero Flag
dc          	equ   1         	;Decimal Carry Flag
c           	equ   0         	;Carry Flag
;--------------------------------------------------------------------------
fsr             	equ   	04h   	;File select register
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
gbit2       	equ   7         	;General purpose bit
			    		;(Bit6~Bit0)indirect address mode pointer
;--------------------------------------------------------------------------
pad             	equ   	05h   	;PortA pin or "data register"
			    		;bit7 only input
			    		;(Bit6~Bit0) input/ouput 
;--------------------------------------------------------------------------
pbd            		equ  	06h   	;PortB pin or "data register"
			    		;only bit3~Bit0 input/ouput 
;--------------------------------------------------------------------------
inte			equ	08h	;Interrupt enable register
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
pwm0ie		equ	7		;pwm0 interrupt enable;1=enable;0=disable
tm2ie		equ	6		;time2 interrupt enable;1=enable;0=disable
tm0ie		equ	4		;time0 interrupt enable;1=enable;0=disable
wktie		equ	3		;wakeup Time interrupt enable;1=enable;0=disable
xint2e		equ	2		;INT2 pin interrupt enable;1=enable;0=disable
xint1e		equ	1		;INT1 pin interrupt enable;1=enable;0=disable
xint0e		equ	0		;INT0 pin interrupt enable;1=enable;0=disable
;--------------------------------------------------------------------------
intf			equ	09h	;Interrupt enable register
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
pwm0i 		equ	7		;PWM0 interrupt event pending flag, set by H/W while PWM overflow
					;write 0: clear this flag; write 1: no action
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
tm2i 		equ	6		;Timer2 interrupt event pending flag, set by H/W while Timer2 overflow
					;write 0: clear this flag; write 1: no action					
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
tm0i 		equ	4		;Timer0 interrupt event pending flag, set by H/W while Timer0 overflow
					;write 0: clear this flag; write 1: no action
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
wkti 		equ	3		;WKT interrupt event pending flag, set by H/W while WKT time out
					;write 0: clear this flag; write 1: no action
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
xint2 		equ	2		;INT2 interrupt event pending flag, set by H/W at INT2 pin¡¯s falling edge
					;write 0: clear this flag; write 1: no action
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
xint1 		equ	1		;INT1 interrupt event pending flag, set by H/W at INT1 pin¡¯s falling edge
					;write 0: clear this flag; write 1: no action
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
xint0 		equ	0		;INT0 interrupt event pending flag, set by H/W at INT0 pin¡¯s f/r edge		
					;write 0: clear this flag; write 1: no action
;--------------------------------------------------------------------------
pwm0duty 		equ	12h	;PWM0 duty 8-bit
;--------------------------------------------------------------------------
ctrlsys		equ	14h
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
selsub 		equ	7 		;sleect sub-clk as cpuclk
stpfck 		equ	6 		;stop fast clock
sube 		equ	5		;sub-clk enable
clrtm2		equ	2		;Write 1 to clear TM2 timer
stoptm0		equ	1		;Stop TM0 timer counting
clrpwm0		equ	0 		;PWM0 clear and hold
;-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
;-*-*-*-*-*-*-*-*-*-**-*-*- R--Plane *-*-*-*--*-*-*-*-*-*-*--*-*-*-*-*-*-*-
;-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
tm0ctrl			equ	02h
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
t0iedgeR 	equ	b'11011111'	;bit5 0: T0I(PA2)rising edge to increase Timer0/PSC count
t0iedgeS 	equ	b'00100000'	;bit5 1: T0I(PA2) falling edge to increase Timer0/PSC count
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
selt0iR 	equ	b'11101111'	;bit4 0: Timer0/PSC clock source is ¡°Instruction Cycle¡±
selt0iS		equ	b'00010000'	;bit4 1: Timer0/PSC clock source is T0I pin
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
tm0pscR		equ	b'11110000'	;bit3~bit0
					;0000: Timer0 input clock divided by 1
 					;0001: Timer0 input clock divided by 2
					;~
					;0111: Timer0 input clock divided by 128
					;1000: Timer0 input clock divided by 256
;--------------------------------------------------------------------------
pwrdown 		equ	03h	;write this register to enter Power-Down Mode
;--------------------------------------------------------------------------
clrwdt 			equ	04h 	;write this register to clear WDT/WKT
;--------------------------------------------------------------------------
pae			equ	05h	
					;bit6~bit3-->0: the pin is open-drain output or Schmitt-trigger input
					;bit6~bit3-->1: the pin is CMOS push-pull output
					;bit2~bit0-->0: the pin is pseudo-open-drain output or Schmitt-trigger input
					;bit2~bit0-->1: the pin is CMOS push-pull output
;--------------------------------------------------------------------------
pbe			equ	06h
					;bit3~bit0-->0: the pin is open-drain output or Schmitt-trigger input
					;bit3~bit0-->1: the pin is CMOS push-pull output
;--------------------------------------------------------------------------
papu			equ	08h
					;bit6~bit0-->0: the pin pull up resistor is enable, except 	 
						       ;the pin¡¯s output data register (PAD) is 0 	 
 			 			       ;the pin¡¯s CMOS push-pull mode is chosen (PAE=1) 	 
						       ;the pin is working for Crystal or external RC oscillation 	 
					;bit6~bit0-->1: the pin pull up resistor is disable 	 
;--------------------------------------------------------------------------
pbpu			equ	09h
					;bit3~bit0-->0: the pin pull up resistor is enable
					;bit3~bit0-->1: the pin pull up resistor is disable
;--------------------------------------------------------------------------
int0wkt			equ	0bh
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int0edgeR 	equ	b'11101111'	;bit4 0: INT0 pin falling edge to trigger interrupt event					
int0edgeS 	equ	b'00010000'	;bit4 1: INT0 pin rising edge to trigger interrupt event
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
clk2pinR 	equ	b'11110111'	;bit3 0: No Instruction Clock output to PA3 pin
clk2pinS 	equ	b'00001000'	;bit3 1: Instruction Clock output to PA3 pin for external/internal RC mode	
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
wktpscR		equ	b'11111100'	;bit1~bit0
					;00: WDT/WKT period is 15mS
					;01: WDT/WKT period is 30mS
					;10: WDT/WKT period is 60mS
					;11: WDT/WKT period is 120mS
;--------------------------------------------------------------------------
pwm0period		equ	10h
;--------------------------------------------------------------------------
pwm0ctrl		equ	11h
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
pwm0eR		equ	b'11111011'	;bit2------->PWM0 positive output to PA1 pin
pwm0eS		equ	b'00000100'	;bit2------->PWM0 positive output to PA1 pin
pwm0divR	equ	b'11111100'	;bit1~bit0-->PWM0 Pre-Scale, 0:div1, 1:div2, 2:div4, 3:div8
;--------------------------------------------------------------------------
pawkup 			equ	13h	;Enable PA6~PA1 pin low level wake up
;--------------------------------------------------------------------------
tm2subtyp 		equ	14h
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
tm2clkR 	equ	b'11101111'	;bit4------->Timer2 Clock Source 0:SLOW Clock; 1:CPUCLK/128
tm2clkS 	equ	b'00010000'	;bit4------->Timer2 Clock Source 0:SLOW Clock; 1:CPUCLK/128
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
tm2divR		equ	b'11110011'	;bit3~bit2-->Timer2 interrupt is timer2 clock divide by ¨C
					;bit3~bit2--> 0: 32768, 1: 16384 , 2: 8192 ,3 :127
subtypR 	equ	b'11111100'	;bit1~bit0--> sub-clk type 0:SXT , 1: ILRC , 2: XRC
;--------------------------------------------------------------------------
pbwkup 			equ	18h	;bit3~bit1--> Enable PB3~PB1 pin low level wake up
;-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
;-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
w               equ    0
f               equ    1  
;-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
;-*-*-*-*-*-*-*-*-*-**-*-*- General purpose RAM -*-*-*--*-*-*-*-*-*-*--*-*-
;-*-*-*-*-*-*-*-*-*-**- 20h~3fh-RAM/Bit Addressable -*-*--*-*-*-*-*-*-*--*-
;-*-*-*-*-*-*-*-*-*-**-*- 40h~4fh-RAM Addressable -*-*--*-*-*-*-*-*-*--*-*-
;-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
