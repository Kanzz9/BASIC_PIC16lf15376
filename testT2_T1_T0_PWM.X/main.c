

#include "mcc_generated_files/mcc.h"
#include"TEXTLCD.h"
/*
                         Main application
 */
INTERRUPT_InterruptManager (void);
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    //TMR1_Initialize();
    
    int dem=0;
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    TMR1_Initialize();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
 
    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    PWM1_Initialize();
    PWM1_LoadDutyValue(374);
    
    
    TextLCD_Init(TEXTLCD1602);
    //TMR1_DefaultInterruptHandler();
   // TMR1_StartTimer();
   // TextLCD_Puts(1,1,"Voltage",0);
    //TMR0_Initialize();
    while (1)
    {          
       // TMR1_CallBack();
    
        // Add your application code
//        TMR0_StartTimer();
//        TMR0_ReadTimer();
//        RC0_GetValue()=~ RC0_GetValue() ;
            dem++;
            __delay_ms(10);
            if(dem==99) dem=0;
        
        TextLCD_SetCursor(0, 0);
        TextLCD_Puts(0,0,"dem: ",0);
        TextLCD_PutChar(dem/10+48);
        TextLCD_PutChar(dem%10+48);
         __delay_ms(1000);
        //__delay_ms(1000);
//        LED_Toggle();
//        __delay_ms(2000);
        
    }
}   

/**
 End of File
*/