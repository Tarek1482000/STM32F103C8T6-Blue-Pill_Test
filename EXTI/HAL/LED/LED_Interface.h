/*=================================================================================*/
/*  File        : LED_Interface.h                                                  */
/*  Description : This Header file includes LED_Interface                          */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#ifndef LED_INC_LED_INTERFACE_H_
#define LED_INC_LED_INTERFACE_H_


/******************* MAIN INCLUDES *********************/
#include <stdint.h>
#include "../../LIBRARY/ErrTypes.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
/*******************************************************/

/****************** MAIN FUNCTIONS *********************/

/*
 * @function 		:	LED_ON
 * @brief			:	Set LED Pin to HIGH
 * @param			:	LED Configurations
 * @retval			:	Error State
 */
void LED_ON(PinConfig_t * LED_Configs);

/*
 * @function 		:	LED_OFF
 * @brief			:	Set LED Pin to LOW
 * @param			:	LED Configurations
 * @retval			:	Error State
 */
void LED_OFF(PinConfig_t * LED_Configs);

/*
 * @function 		:	LED_TOG
 * @brief			:	Set LED Pin to LOW or HIGH
 * @param			:	LED Configurations
 * @retval			:	Error State
 */
void LED_TOG(PinConfig_t * LED_Configs);


/***************End of MAIN FUNCTIONS*******************/


#endif /* LED_INC_LED_INTERFACE_H_ */
