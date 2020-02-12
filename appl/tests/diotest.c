/*
 * diotest.c
 *
 *  Created on: Feb 13, 2020
 *      Author: Omar Zayed
 */



#include "../../mcal/nvic/nvic.h"
#include "../../mcal/PortDriver/port.h"
#include "../../mcal/mcu_hw.h"
#include "../../mcal/dio/dio.h"

void diotest(void)
{

    RCGCGPIO_REG.R0  = 1;
    RCGCGPIO_REG.R1  = 1;
    RCGCGPIO_REG.R2  = 1;
    RCGCGPIO_REG.R3  = 1;
    RCGCGPIO_REG.R4  = 1;
    RCGCGPIO_REG.R5  = 1;


    PORT_init();
    Dio_WriteChannel(Dio_Channel_F0, STD_high);
    //Dio_WriteChannel(Dio_Channel_F1, STD_high);
    Dio_WriteChannel(Dio_Channel_F2, STD_high);



    while(1)
    {

    }
}


