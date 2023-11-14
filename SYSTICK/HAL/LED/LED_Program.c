/*=================================================================================*/
/*  File        : LED_Program.c                                                    */
/*  Description : This Program file includes LED program                           */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/


/******************* MAIN INCLUDES *********************/
#include <stdint.h>

#include "../../HAL/LED/LED_Interface.h"
/*******************************************************/

/*
 * @function 		:	LED_ON
 * @brief			:	Set LED Pin to HIGH
 * @param			:	LED Configurations
 * @retval			:	Error State
 */
void LED_ON(PinConfig_t * LED_Configs)
{
	if (NULL != LED_Configs)
	{
		GPIO_u8PinInit(LED_Configs);
		GPIO_u8SetPinStatus(LED_Configs->Port_Num, LED_Configs->Pin_Num, HIGH_V);
	}
	else
	{
		/*Error => Do Nothing*/
	}
}

/*
 * @function 		:	LED_OFF
 * @brief			:	Set LED Pin to LOW
 * @param			:	LED Configurations
 * @retval			:	Error State
 */
void LED_OFF(PinConfig_t * LED_Configs)
{
	if (NULL != LED_Configs)
	{
		GPIO_u8PinInit(LED_Configs);
		GPIO_u8SetPinStatus(LED_Configs->Port_Num, LED_Configs->Pin_Num, LOW_V);
	}
	else
	{
		/*Error => Do Nothing*/
	}
}

void LED_TOG(PinConfig_t * LED_Configs)
{
	if (NULL != LED_Configs)
	{
		uint8_t state = 0;
		GPIO_u8PinInit(LED_Configs);
		GPIO_u8ReadPinStatus(LED_Configs->Port_Num, LED_Configs->Pin_Num, &state);

		if(state)
			GPIO_u8SetPinStatus(LED_Configs->Port_Num, LED_Configs->Pin_Num, LOW_V);
		else
			GPIO_u8SetPinStatus(LED_Configs->Port_Num, LED_Configs->Pin_Num, HIGH_V);	}
	else
	{
		/*Error => Do Nothing*/
	}

}
