/*
 * nvic.c
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */

#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/nvic_cfg.h"
#include "../mcu_hw.h"
#include "nvic_types.h"
#include "nvic.h"

extern NVIC_CfgType NVIC_CfgArr[];
extern uint32 IntPriorityCfgs;

void NVIC_init(void)
{
    uint32 index;
    uint32 interrupt_number;
    volatile uint32* ptr_IntEnable;
    uint32 Priority_value;
    uint32 Priority_Shift;
    volatile uint32* ptr_IntPriority;

    for (index = 0; index < NVIC_NUM_OF_ENABLED_INT; index++)
    {
        interrupt_number = NVIC_CfgArr[index].InterruptNum;
        ptr_IntEnable = (uint32*) (NVIC_Base + NVIC_Interrupt_Enable_Offset + ((interrupt_number / 32) * 4));
        *ptr_IntEnable |= (1 << (interrupt_number % 32));

        switch (IntPriorityCfgs)
        {
        case INT_PRIORITY_XXX:
            Priority_value |= NVIC_CfgArr[index].Priority_Group;
            break;

        case INT_PRIORITY_XXY:
            Priority_value = NVIC_CfgArr[index].Priority_Group;
            Priority_value = Priority_value << 1;
            Priority_value |= NVIC_CfgArr[index].Sub_priority_Group;
            break;

        case INT_PRIORITY_XYY:
            Priority_value = NVIC_CfgArr[index].Priority_Group;
            Priority_value = Priority_value << 2;
            Priority_value |= NVIC_CfgArr[index].Sub_priority_Group;
            break;

        case INT_PRIORITY_YYY:
            Priority_value |= NVIC_CfgArr[index].Sub_priority_Group;
            break;
        }

        Priority_Shift = NVIC_CfgArr[index].InterruptNum;
        ptr_IntPriority = (uint32*) (NVIC_Base + NVIC_Interrupt_Priority_Offset + ((interrupt_number / 4) * 4));
        if (Priority_Shift % 4 == 0)
        {
            *ptr_IntPriority |= (Priority_value << 5) ;
        }

        else if (Priority_Shift % 4 == 1)
        {
            *ptr_IntPriority |= (Priority_value << 13) ;
        }

        else if (Priority_Shift % 4 == 2)
        {
            *ptr_IntPriority |= (Priority_value << 21) ;
        }

        else if (Priority_Shift % 4 == 3)
        {
            *ptr_IntPriority |= (Priority_value << 29) ;
        }

        else
        {
            /*DO NOTHING*/
        }
    }
}

