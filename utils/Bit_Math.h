/*
 * Bit_Math.h
 *
 *  Created on: Jun 15, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_LAB_SRC_UTILS_BIT_MATH_H_
#define E15_LAB_SRC_UTILS_BIT_MATH_H_

#include "Std_Types.h"

#define BIT_BAND_ACCESS(REG_ADDR,BIT_NO)                         (*((volatile uint32 *)((((uint32)REG_ADDR & 0xF0000000) | 0x02000000)|\
                                                                    (((uint32)REG_ADDR & 0x000FFFFF) *32 ) | (BIT_NO * 4))))

#define SET_BIT(u32Var,BitNo)		                             u32Var |= ((uint32)1<<BitNo)
#define CLR_BIT(u32Var,BitNo)		                             u32Var &= ~((uint32)1<<BitNo)
#define TOGGLE_BIT(u32Var,BitNo)		                         u32Var ^= ((uint32)1<<BitNo)
#define GET_BIT(u32Var,BitNo)		                            (u32Var >> BitNo) & (uint32)0x01

#define GET_REG(BASE_ADDR, REG_TYPE, REG_OFFSET)                (*((volatile REG_TYPE*)(BASE_ADDR+REG_OFFSET)))

#define ASSIGN_BIT(u32Var,BitNo,Val)                            (u32Var = (u32Var&~(1<<BitNo))|(Val<<BitNo))

#endif /* E15_LAB_SRC_UTILS_BIT_MATH_H_ */
