
/*
 * port.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Muammad Elzeiny
 */
#define MAX_NUM_OF_CH_IN_PORT       8
#define MAX_NUM_OF_PORTS            6

#include <tm4c123_firmware-latte_workshop/utils/Std_Types.h>
#include "../../utils/Bit_Math.h"
#include "../../config/port_cfg.h"
#include "../mcu_hw.h"
#include <tm4c123_firmware-latte_workshop/mcal/PortDriver/port_types.h>
#include <tm4c123_firmware-latte_workshop/mcal/PortDriver/port.h>

extern Port_CfgType PortCfgArr[];
static volatile PORT_RegType* BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                               PORTC_BaseAddr,PORTD_BaseAddr,
                                                               PORTE_BaseAddr,PORTF_BaseAddr};
void PORT_init(void)
{
    uint8 CfgArrIndex;
    Port_IdType PortId;
    Port_ChIdType ChannelId;
    uint8 ChannelPosInPort;
    volatile PORT_RegType* BaseAddr;


    for (CfgArrIndex = 0; CfgArrIndex < PORT_NUM_OF_ACTIVATED_CH; ++CfgArrIndex)
    {
        /*get channelID from CfgIndex*/
        ChannelId = PortCfgArr[CfgArrIndex].Channel;

        /*get Channel Position in PortGroup using ChannelId */
        ChannelPosInPort = ChannelId % MAX_NUM_OF_CH_IN_PORT;

        /*get PORTId using ChannelId*/
        PortId = (Port_IdType)(ChannelId / MAX_NUM_OF_CH_IN_PORT);

        /*get baseAddress using PortId*/
        BaseAddr = BaseAddrArr[PortId];

        /* unlock the port channel */
        BaseAddr->GPIOLOCK = 0x00;
        SET_BIT((*BaseAddr).GPIOCR, ChannelPosInPort);


        /* set channel direction */
        BaseAddr->GPIODIR |= PortCfgArr[CfgArrIndex].Dir << ChannelPosInPort;


        if(PortCfgArr[CfgArrIndex].Mode != Port_Mode_DIO)
        {
            SET_BIT(BaseAddr->GPIOAFSEL, ChannelPosInPort);
        }
        else
        {
            CLR_BIT(BaseAddr->GPIOAFSEL, ChannelPosInPort);
        }

        /* set channel mode */
        BaseAddr->GPIOPCTL |= ( PortCfgArr[CfgArrIndex].Mode << (ChannelPosInPort*4) );


        /* set Interrupt configuration */
        if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntDisable)
        {
            CLR_BIT(BaseAddr->GPIOIM, ChannelPosInPort);
        }
        else
        {
            SET_BIT(BaseAddr->GPIOIM, ChannelPosInPort);

            if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntBothEdges)
            {
                SET_BIT(BaseAddr->GPIOIBE, ChannelPosInPort);
                CLR_BIT(BaseAddr->GPIOIEV, ChannelPosInPort);
            }
            else if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntRisingEdge)
            {
                CLR_BIT(BaseAddr->GPIOIBE, ChannelPosInPort);
                SET_BIT(BaseAddr->GPIOIEV, ChannelPosInPort);
            }
            else
            {
                CLR_BIT(BaseAddr->GPIOIBE, ChannelPosInPort);
                CLR_BIT(BaseAddr->GPIOIEV, ChannelPosInPort);
            }
        }


        /* set Internal Attachment configuration */
        if(PortCfgArr[CfgArrIndex].AttachedRes == Port_InternalAttach_OpenDrain)
        {
            SET_BIT(BaseAddr->GPIOODR, ChannelPosInPort);
            CLR_BIT(BaseAddr->GPIOPUR, ChannelPosInPort);
            CLR_BIT(BaseAddr->GPIOPDR, ChannelPosInPort);
        }
        else if(PortCfgArr[CfgArrIndex].AttachedRes == Port_InternalAttach_PullUpRes)
        {
            CLR_BIT(BaseAddr->GPIOODR, ChannelPosInPort);
            SET_BIT(BaseAddr->GPIOPUR, ChannelPosInPort);
            CLR_BIT(BaseAddr->GPIOPDR, ChannelPosInPort);
        }
        else if(PortCfgArr[CfgArrIndex].AttachedRes == Port_InternalAttach_PullDownRes)
        {
            CLR_BIT(BaseAddr->GPIOODR, ChannelPosInPort);
            CLR_BIT(BaseAddr->GPIOPUR, ChannelPosInPort);
            SET_BIT(BaseAddr->GPIOPDR, ChannelPosInPort);
        }
        else
        {
            //DO NOTHING
        }


        /* set current strength configuration */
        if(PortCfgArr[CfgArrIndex].CurrentDrive == Port_CurrDrive_2mA)
        {
            SET_BIT(BaseAddr->GPIODR2R, ChannelPosInPort);
            CLR_BIT(BaseAddr->GPIODR4R, ChannelPosInPort);
            CLR_BIT(BaseAddr->GPIODR8R, ChannelPosInPort);
        }
        else if(PortCfgArr[CfgArrIndex].CurrentDrive == Port_CurrDrive_4mA)
        {
            CLR_BIT(BaseAddr->GPIODR2R, ChannelPosInPort);
            SET_BIT(BaseAddr->GPIODR4R, ChannelPosInPort);
            CLR_BIT(BaseAddr->GPIODR8R, ChannelPosInPort);
        }
        else if(PortCfgArr[CfgArrIndex].CurrentDrive == Port_CurrDrive_8mA)
        {
            CLR_BIT(BaseAddr->GPIODR2R, ChannelPosInPort);
            CLR_BIT(BaseAddr->GPIODR4R, ChannelPosInPort);
            SET_BIT(BaseAddr->GPIODR8R, ChannelPosInPort);
        }
        else
        {
            CLR_BIT(BaseAddr->GPIODR2R, ChannelPosInPort);
            CLR_BIT(BaseAddr->GPIODR4R, ChannelPosInPort);
            CLR_BIT(BaseAddr->GPIODR8R, ChannelPosInPort);
        }


        /*Check if analog functionality is required*/
        if(PortCfgArr[CfgArrIndex].Mode != Port_Mode_AIN )
        {
            /* enable digital and disable ADC  */
            SET_BIT(BaseAddr->GPIODEN, ChannelPosInPort);
            CLR_BIT(BaseAddr->GPIOAMSEL, ChannelPosInPort);
            CLR_BIT(BaseAddr->GPIOADCCTL, ChannelPosInPort);


        }
        else
        {
            /* disable digital and enable ADC */
            CLR_BIT(BaseAddr->GPIODEN, ChannelPosInPort);
            SET_BIT(BaseAddr->GPIOAMSEL, ChannelPosInPort);
            SET_BIT(BaseAddr->GPIOADCCTL, ChannelPosInPort);

        }

        /* check if the port needed to be locked or not */
        BaseAddr->GPIOCR |= PortCfgArr[CfgArrIndex].LockStatus << ChannelPosInPort;
        BaseAddr->GPIOLOCK = 0x01;
    }

}
