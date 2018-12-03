/*
 * CRC16.h
 *
 *  Created on: 2016年5月24日
 *      Author: Administrator
 */

#ifndef SOURCE_MODULES_CRC16_CRC16_H_
#define SOURCE_MODULES_CRC16_CRC16_H_

#include "Common.h"

#define CRC_INITIAL_REMAINDER        (0xFFFF)
#define CRC_FINAL_XOR_VALUE          (0x0000)

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
extern uint16 CRC16_Calculate(uint8 * message,uint32 length,
        uint16 remainder, uint16 xorMask);

#ifdef __cplusplus
}
#endif


#endif /* SOURCE_MODULES_CRC16_CRC16_H_ */
