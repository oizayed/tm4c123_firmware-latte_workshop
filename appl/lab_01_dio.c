/*
 * lab_03_spi.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Muhammad.Elzeiny
 */
#include <tm4c123_firmware-latte_workshop/mcal/PortDriver/port.h>
#include <tm4c123_firmware-latte_workshop/mcal/SysCtr/SysCtr.h>
#include "../mcal/dio/dio.h"

void lab_00_dio(void)
{
    /*TODO: write simple code to test System control clock */

    SysCtr_init();
    SysCtr_prepheralClkEnable(SYSCTL_PERIPH_GPIOA);
    SysCtr_prepheralClkEnable(SYSCTL_PERIPH_GPIOB);
    SysCtr_prepheralClkEnable(SYSCTL_PERIPH_GPIOC);
    SysCtr_prepheralClkEnable(SYSCTL_PERIPH_GPIOD);
    SysCtr_prepheralClkEnable(SYSCTL_PERIPH_GPIOE);
    SysCtr_prepheralClkEnable(SYSCTL_PERIPH_GPIOF);
    PORT_init();

    Dio_WriteChannel(Dio_Channel_F0, STD_high);
    Dio_WriteChannel(Dio_Channel_F1, STD_high);
    Dio_WriteChannel(Dio_Channel_F2, STD_high);

    while(1)
    {

    }
}


