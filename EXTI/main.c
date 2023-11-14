/*=================================================================================*/
/*  File        : main.c                                                           */
/*  Description : This Program file includes APP program for STM32f103C8T6         */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/


#include "MCAL/RCC/RCC_Interface.h"
#include "MCAL/AFIO/AFIO_Interface.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "MCAL/NVIC/NVIC_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "HAL/LED/LED_Interface.h"

void led_tog(void);


PinConfig_t LED_CONFIG =
{
		.Port_Num    = PORTC,
		.Pin_Num     = PIN13,
		.Mode        = OUTPUT_MSPEED,
		.Input_Type  = ANALOG_INPUT,
		.Output_Type = GP_PUSH_PULL,
		.PullType    = PULLDOWN,
};


PinConfig_t PinConfig =
{
		.Port_Num    = PORTC,
		.Pin_Num     = PIN14,
		.Mode        = INPUT,
		.Input_Type  = PULLUPDOWN_INPUT,
		.Output_Type = AF_PUSHPULL,
		.PullType    = PULLUP,
};

EXTI_Confg Copy_EXTI =
{
		.LINE      = EXTI14,
		.Trigger   = FallingEdge,
		.Mode      = Enable,
		.EXTI_CallBackFunc = led_tog
};


int main(void)
{
	RCC_SetClockStatus(HSI, ON);
	RCC_SetSystemClock(HSI);
	RCC_Set_APB2Peripheral_CLK(APB2_IOPA, ENABLED);
	RCC_Set_APB2Peripheral_CLK(APB2_IOPB, ENABLED);
	RCC_Set_APB2Peripheral_CLK(APB2_IOPC, ENABLED);
	RCC_Set_APB2Peripheral_CLK(APB2_AFIO, ENABLED);



	GPIO_u8PinInit(&PinConfig);
	AFIO_U8SetEXTIPort(AFIO_EXTI14, AFIO_PortC);
	NVIC_EnableIRQ(EXTI15_10_IRQ);
	EXTI_Init(&Copy_EXTI);
	EXTI_Enable(EXTI14);

	LED_OFF(&LED_CONFIG);

	for(;;)
	{


	}
}




void led_tog(void)
{
	LED_TOG(&LED_CONFIG);
}
