/*
 * nvic_lcfg.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "nvic_cfg.h"
#include "../mcal/nvic/nvic_types.h"

#define INT_PRIORITY_CFGs    INT_PRIORITY_XYY

const uint32 IntPriorityCfgs=INT_PRIORITY_CFGs;


const NVIC_CfgType NVIC_CfgArr[NVIC_NUM_OF_ENABLED_INT] =
{
     /* interruptNumber                       groupPriority                   subPriority */
 {      35,                           1,                              2},
 {      NVIC_GPIOB,                           2,                              0},
 {      NVIC_GPIOC,                           2,                              0},
 {      NVIC_GPIOD,                           2,                              0},
 {      NVIC_GPIOE,                           2,                              0},

};
