
// PIC16F887 Configuration Bit Settings
// 'C' source line config statements
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "TMR2.h"
#include "LED_SEGMENT.h"
#include "TRAFFIC.h"

void PORT_Init(void);

void main (void)
{
    PORT_Init();
    TMR2_Setup(250,TMR2_PRESC_1_4,TMR2_POSTSC_1_5);
    TMR2_Interrupt(ENABLE);
    TMR2_ON();
    ei();
    SysTick.On_Off=ON;
    while(1)
    {
        while(SysTick.On_Off)
            ;
          SysTick.On_Off=ON;
        
         Clr_LED();
         Counting();
        LED_7SEGMENT_Update(Seg);
        Traffic_Light(LED);
        Latch_Traffic_LED(&LAT);
        Temp=0X00;
        Temp|=~(PORTB>>4);
        Temp&=0X0F;
        VIP=VIP_PrioTab[Temp];
        if(VIP)
            VIP_mode();
        Seg[9]=Seg[8]=0;
    }
}

void PORT_Init(void)
{
    TRISC=0X00;
    TRISB=0XF0;
    TRISA=0X00;
    TRISD=0X00;
    PORTA=0X00;
    PORTB=0X00;
    ANSELH=0X00;
    OPTION_REG &=~(1<<7);
    WPUB=0XF0;
    PORTC=0X00;
    PORTD=0X00;
    OSCCON=(1<<6)|(1<<5)|(1<<2)|1;
    
   
}

void __interrupt() ISR(void)
{
    if( TMR2_GetIntFlag())
    {
        TMR2_ClearIntFlag();
        SysTick.On_Off=OFF;
    }
}