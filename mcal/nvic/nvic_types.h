/*
 * nvic_types.h
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TM4C123_FIRMWARE_MCAL_NVIC_NVIC_TYPES_H_
#define TM4C123_FIRMWARE_MCAL_NVIC_NVIC_TYPES_H_


typedef enum
{
    NVIC_GPIOA                              = 0,
    NVIC_GPIOB,
    NVIC_GPIOC,
    NVIC_GPIOD,
    NVIC_GPIOE,
    NVIC_UART0,
    NVIC_UART1,
    NVIC_SSI0,
    NVIC_I2C0,
    NVIC_PWM0_FAULT,
    NVIC_PWM0_Generator0,
    NVIC_PWM0_Generator1,
    NVIC_PWM0_Generator2,
    NVIC_QEI0,
    NVIC_ADC0_Sequence0,
    NVIC_ADC0_Sequence1,
    NVIC_ADC0_Sequence2,
    NVIC_ADC0_Sequence3,
    NVIC_WATCHDOG_TIMERS0_1,
    NVIC_TIMER0A_16_32,
    NVIC_TIMER0B_16_32,
    NVIC_TIMER1A_16_32,
    NVIC_TIMER1B_16_32,
    NVIC_TIMER2A_16_32,
    NVIC_TIMER2B_16_32,
    NVIC_ANALOG_COMPARATOR0,
    NVIC_ANALOG_COMPARATOR1,

    NVIC_SYSTEM_CONTROL                     = 28,
    NVIC_FLASH_MEMORY_EEPROM_CONTROL,
    NVIC_GPIOF,

    NVIC_UART2                              = 33,
    NVIC_SSI1,
    NVIC_TIMER3A_16_32,
    NVIC_TIMER3B_16_32,
    NVIC_I2CI,
    NVIC_QEI1,
    NVIC_CAN0,
    NVIC_CAN1,

    NVIC_HIBERNATION_MODULE                 = 43,
    NVIC_USB,
    NVIC_PWM_GENERATOR3,
    NVIC_DMA_SOFTWARE,
    NVIC_DMA_ERROR,
    NVIC_ADC1_Sequence,
    NVIC_ADC1_Sequence1,
    NVIC_ADC1_Sequence2,
    NVIC_ADC1_Sequence3,

    NVIC_SSI2                               = 57,
    NVIC_SSI3,
    NVIC_UART3,
    NVIC_UART4,
    NVIC_UART5,
    NVIC_UART6,
    NVIC_UART7,
    NVIC_I2C2                               = 68,
    NVIC_I2C3,
    NVIC_Bit_Timer4A_16_32,
    NVIC_Bit_Timer4B_16_32,

    NVIC_Bit_Timer5A_16_32                  = 92,
    NVIC_Bit_Timer5B_16_32,
    NVIC_Bit_Timer0A_32_64,
    NVIC_Bit_Timer0B_32_64,
    NVIC_Bit_Timer1A_32_64,
    NVIC_Bit_Timer1B_32_64,
    NVIC_Bit_Timer2A_32_64,
    NVIC_Bit_Timer2B_32_64,
    NVIC_Bit_Timer3A_32_64,
    NVIC_Bit_Timer3B_32_64,
    NVIC_Bit_Timer4A_32_64,
    NVIC_Bit_Timer4B_32_64,
    NVIC_Bit_Timer5A_32_64,
    NVIC_Bit_Timer5B_32_64,
    NVIC_System_Exception,

    NVIC_PWM1_Generator0                    = 134,
    NVIC_PWM1_Generator1,
    NVIC_PWM1_Generator2,
    NVIC_PWM1_Generator3,
    NVIC_PWM1_Fault

}NVIC_INtType;

typedef struct
{
    /*TODO create types to contain Configuration parameters for each Interrupts*/
     uint32 InterruptNum;
     uint32 Priority_Group;
     uint32 Sub_priority_Group;

}NVIC_CfgType;



#endif /* TM4C123_FIRMWARE_MCAL_NVIC_NVIC_TYPES_H_ */
