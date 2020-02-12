/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "../../mcal/mcu_hw.h"
#include "dio.h"

Std_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Std_levelType ret;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /* Return the level value of given Channel */
    switch(PortId)
    {
    case Dio_Port_A :
        ret = GET_BIT(PORTA_BaseAddr->GPIODATA, ChannelPos);
        break;

    case Dio_Port_B :
        ret = GET_BIT(PORTB_BaseAddr->GPIODATA, ChannelPos);
        break;

    case Dio_Port_C :
        ret = GET_BIT(PORTC_BaseAddr->GPIODATA, ChannelPos);
        break;

    case Dio_Port_D :
        ret = GET_BIT(PORTD_BaseAddr->GPIODATA, ChannelPos);
        break;

    case Dio_Port_E :
        ret = GET_BIT(PORTE_BaseAddr->GPIODATA, ChannelPos);
        break;

    case Dio_Port_F :
        ret = GET_BIT(PORTF_BaseAddr->GPIODATA, ChannelPos);
        break;

    default :

        break;
    }
    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Std_levelType Level)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /* Write the input value in the corresponding ChannelId */
    switch(PortId)
    {
    case Dio_Port_A :
        ASSIGN_BIT(PORTA_BaseAddr->GPIODATA, ChannelPos, Level);
        break;

    case Dio_Port_B :
        ASSIGN_BIT(PORTB_BaseAddr->GPIODATA, ChannelPos, Level);
        break;

    case Dio_Port_C :
        ASSIGN_BIT(PORTC_BaseAddr->GPIODATA, ChannelPos, Level);
        break;

    case Dio_Port_D :
        ASSIGN_BIT(PORTD_BaseAddr->GPIODATA, ChannelPos, Level);
        break;

    case Dio_Port_E :
        ASSIGN_BIT(PORTE_BaseAddr->GPIODATA, ChannelPos, Level);
        break;

    case Dio_Port_F :
        ASSIGN_BIT(PORTF_BaseAddr->GPIODATA, ChannelPos, Level);
        break;

    default :

        break;
    }
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;

    /* Return the Port Value*/
    switch(PortId)
    {
    case Dio_Port_A :
        ret = PORTA_BaseAddr->GPIODATA;
        break;

    case Dio_Port_B :
        ret = PORTB_BaseAddr->GPIODATA;
        break;

    case Dio_Port_C :
        ret = PORTC_BaseAddr->GPIODATA;
        break;

    case Dio_Port_D :
        ret = PORTD_BaseAddr->GPIODATA;
        break;

    case Dio_Port_E :
        ret = PORTE_BaseAddr->GPIODATA;
        break;

    case Dio_Port_F :
        ret = PORTF_BaseAddr->GPIODATA;
        break;

    default :

        break;
    }
    return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{

    /* Write the input value in the corresponding PortId */
    switch(PortId)
    {
    case Dio_Port_A :
        PORTA_BaseAddr->GPIODATA = value;
        break;

    case Dio_Port_B :
        PORTB_BaseAddr->GPIODATA = value;
        break;

    case Dio_Port_C :
        PORTC_BaseAddr->GPIODATA = value;
        break;

    case Dio_Port_D :
        PORTD_BaseAddr->GPIODATA = value;
        break;

    case Dio_Port_E :
        PORTE_BaseAddr->GPIODATA = value;
        break;

    case Dio_Port_F :
        PORTF_BaseAddr->GPIODATA = value;
        break;

    default :

        break;
    }


}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /*  toggle the corresponding ChannelId */
    switch(PortId)
    {
    case Dio_Port_A :
        TOGGLE_BIT(PORTA_BaseAddr->GPIODATA, ChannelPos);
        break;

    case Dio_Port_B :
        TOGGLE_BIT(PORTB_BaseAddr->GPIODATA, ChannelPos);
        break;

    case Dio_Port_C :
        TOGGLE_BIT(PORTC_BaseAddr->GPIODATA, ChannelPos);
        break;

    case Dio_Port_D :
        TOGGLE_BIT(PORTD_BaseAddr->GPIODATA, ChannelPos);
        break;

    case Dio_Port_E :
        TOGGLE_BIT(PORTE_BaseAddr->GPIODATA, ChannelPos);
        break;

    case Dio_Port_F :
        TOGGLE_BIT(PORTF_BaseAddr->GPIODATA, ChannelPos);
        break;

    default :

        break;
    }


}
void Dio_FlipPort(Dio_PortType PortId)
{
    /*: toggle the port value */
    switch(PortId)
    {
    case Dio_Port_A :
        PORTA_BaseAddr->GPIODATA = ~PORTA_BaseAddr->GPIODATA;
        break;

    case Dio_Port_B :
        PORTB_BaseAddr->GPIODATA = ~PORTB_BaseAddr->GPIODATA;
        break;

    case Dio_Port_C :
        PORTC_BaseAddr->GPIODATA = ~PORTC_BaseAddr->GPIODATA;
        break;

    case Dio_Port_D :
        PORTD_BaseAddr->GPIODATA = ~PORTD_BaseAddr->GPIODATA;
        break;

    case Dio_Port_E :
        PORTE_BaseAddr->GPIODATA = ~PORTE_BaseAddr->GPIODATA;
        break;

    case Dio_Port_F :
        PORTF_BaseAddr->GPIODATA = ~PORTF_BaseAddr->GPIODATA;
        break;

    default :

        break;
    }
}



