/*
 * processor.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "processor.h"

static uint8 gu8_ProcessorMode = PROCESSOR_ModeNonPrivilege;

void PROCESSOR_switchMode(PROCESSOR_ModeType Mode)
{
    gu8_ProcessorMode = Mode;
    __asm(" SVC #0");
}


void PROCESSOR_SvcHandler(void)
{

    if(gu8_ProcessorMode == PROCESSOR_ModePrivilege)
    {
        __asm(" MRS R10, CONTROL \n"
              " AND R10, R10, #0xFE \n"
              " MSR CONTROL, R0 \n");

    }
    else if(gu8_ProcessorMode == PROCESSOR_ModeNonPrivilege)
    {
        __asm(" MRS R10, CONTROL \n"
              " ORR R10, R10, #0x01 \n"
              " MSR CONTROL, R0 \n");
    }
    else
    {
        //DO NOTHING
    }

}

void PROCESSOR_enableGlobalInt(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsie   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}

void PROCESSOR_disableGlobalInt(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsid   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}
