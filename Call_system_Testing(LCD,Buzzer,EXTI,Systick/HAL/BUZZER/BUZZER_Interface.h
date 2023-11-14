/*=================================================================================*/
/*  File        : BUZZER_Interface.h                                               */
/*  Description : This Header file includes BUZZER Interface                       */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#ifndef BUZZER_INC_BUZZER_INTERFACE_H_
#define BUZZER_INC_BUZZER_INTERFACE_H_

/******************* MAIN INCLUDES *********************/
#include <stdint.h>
#include "../../LIBRARY/ErrTypes.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
/*******************************************************/

/****************** MAIN FUNCTIONS *********************/

/*
 * @function 		:	BUZZER_ON
 * @brief			:	Set BUZZER Pin to HIGH
 * @param			:	BUZZER_Configs
 * @retval			:	Error State
 */
void BUZZER_ON(PinConfig_t * BUZZER_Configs);

/*
 * @function 		:	BUZZER_OFF
 * @brief			:	Set BUZZER Pin to LOW
 * @param			:	BUZZER_Configs
 * @retval			:	Error State
 */
void BUZZER_OFF(PinConfig_t * BUZZER_Configs);


#endif /* BUZZER_INC_BUZZER_INTERFACE_H_ */
