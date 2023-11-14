/*=================================================================================*/
/*  File        : SYSTICK_Private.h                                                */
/*  Description : This Header file includes SYSTICK Private for STM32f103C8T6      */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/


#ifndef SYSTICK_INC_SYSTICK_PRIVATE_H_
#define SYSTICK_INC_SYSTICK_PRIVATE_H_

#define 	ENABLE_MASK				0b1
#define 	ENABLE_BIT_ACCESS		0

#define 	INTERRUPT_MASK			0b1
#define 	INTERRUPT_BIT_ACCESS	1u

#define		CLKSRC_MASK				0b1
#define 	CLKSRC_BIT_ACCESS		2u

#define 	TICK_TIME				0.125

#define 	COUNTFLAG				16u


#endif /* SYSTICK_INC_SYSTICK_PRIVATE_H_ */
