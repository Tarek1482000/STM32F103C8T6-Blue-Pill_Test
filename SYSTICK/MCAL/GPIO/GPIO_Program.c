/*=================================================================================*/
/*  File        : GPIO_Program.c                                                   */
/*  Description : This Program file includes GPIO Program for STM32f103C8T6        */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#include <stdint.h>

#include "GPIO_Interface.h"
#include "../../LIBRARY/STM32F103xx.h"
#include "../../LIBRARY/ErrTypes.h"


GPIO_REG_t * GPIO_PORT[GPIO_NUMBERS]={GPIOA	,GPIOB	,GPIOC	,GPIOD	,GPIOE	,GPIOF	,GPIOG};
/*
 * @function		GPIO_u8PinInit
 * @brief			main initialization for selected pin
 * @param[in]		PinConfig : Initialization values of the pin
 * @retval			ErrorState
 */
uint8_t GPIO_u8PinInit(PinConfig_t * Pin_Config)
{
	uint8_t Local_u8ErrorState = OK;
	if (Pin_Config != NULL)
	{
		if (((Pin_Config->Port_Num)<=PORTG)&&((Pin_Config->Pin_Num)<=PIN15))
		{
			/*SET PIN MODE*/
			GPIO_PORT[Pin_Config->Port_Num]->CR[(Pin_Config->Pin_Num)/8] &= ~(MODE_MASK<<((Pin_Config->Pin_Num)%8)*MODE_PIN_ACCESS);
			GPIO_PORT[Pin_Config->Port_Num]->CR[(Pin_Config->Pin_Num)/8] |= ((Pin_Config->Mode)<<((Pin_Config->Pin_Num)%8)*MODE_PIN_ACCESS);
			/*SET MODE Configurations*/
			if ((Pin_Config->Mode) == INPUT)
			{
				/*If mode is input , set the desired input type*/
				GPIO_PORT[Pin_Config->Port_Num]->CR[(Pin_Config->Pin_Num)/8] &= ~(CNF_MASK<<((((Pin_Config->Pin_Num)%8)*CNF_PIN_ACCESS)+2));
				GPIO_PORT[Pin_Config->Port_Num]->CR[(Pin_Config->Pin_Num)/8] |=  ((Pin_Config->Input_Type)<<((((Pin_Config->Pin_Num)%8)*CNF_PIN_ACCESS)+2));

				if ((Pin_Config->Input_Type) == PULLUPDOWN_INPUT)
				{	/*If the desired input type is PULLUPDOWN_INPUT ,then set the pull type (Up or Down) */
					GPIO_PORT[Pin_Config->Port_Num]->ODR &= ~ (ODR_MASK<<(Pin_Config->Pin_Num));
					GPIO_PORT[Pin_Config->Port_Num]->ODR |=   ((Pin_Config->PullType)<<(Pin_Config->Pin_Num));

				}
			}
			else if (((Pin_Config->Mode) <=OUTPUT_HSPEED) && ((Pin_Config->Mode)>=OUTPUT_MSPEED) )
			{
				/*If mode is output , set the desired output type*/
				GPIO_PORT[Pin_Config->Port_Num]->CR[(Pin_Config->Pin_Num)/8] &= ~(CNF_MASK<<((((Pin_Config->Pin_Num)%8)*CNF_PIN_ACCESS)+2));
				GPIO_PORT[Pin_Config->Port_Num]->CR[(Pin_Config->Pin_Num)/8] |=  ((Pin_Config->Output_Type)<<((((Pin_Config->Pin_Num)%8)*CNF_PIN_ACCESS)+2));
				if (((Pin_Config->Output_Type) == AF_OPEN_DRAIN) ||((Pin_Config->Output_Type) == AF_PUSHPULL))
				{
					/*If the desired output mode is alternate function ,then set the required AF */
					/*AF Configurations*/
				}
			}

		}
		else {
			Local_u8ErrorState = InvalidPORTPIN;
		}
	}
	else
	{
		Local_u8ErrorState = Null_Pointer;
	}

	return Local_u8ErrorState;
}


/*
 * @function		GPIO_u8PortInit
 * @brief			main initialization for selected port
 * @param[in]		PinConfig : Initialization values of the port
 * @retval			ErrorState
 */
uint8_t GPIO_u8PortInit(PortConfig_t *Port_Config)
{
	switch(Port_Config->Port_Num)
	{
	case PORTA:
		for(uint8_t i = Port_Config->Pin_Num;i<=PIN15;i++)
		{
			PinConfig_t Pin_Config =
			{
					Port_Config->Port_Num,
					i,
					Port_Config->Mode,
					Port_Config->Output_Type,
					Port_Config->Input_Type,
					Port_Config->PullType,
			};
			GPIO_u8PinInit(&Pin_Config);
		}
		break;

	case PORTB:
		for(uint8_t i = Port_Config->Pin_Num;i<=PIN15;i++)
		{
			PinConfig_t Pin_Config =
			{
					Port_Config->Port_Num,
					i,
					Port_Config->Mode,
					Port_Config->Output_Type,
					Port_Config->Input_Type,
					Port_Config->PullType,
			};
			GPIO_u8PinInit(&Pin_Config);
		}
		break;

	case PORTC:
		for(uint8_t i = Port_Config->Pin_Num;i<=PIN15;i++)
		{
			if(i < 13)
				i = 13;
			PinConfig_t Pin_Config =
			{
					Port_Config->Port_Num,
					i,
					Port_Config->Mode,
					Port_Config->Output_Type,
					Port_Config->Input_Type,
					Port_Config->PullType,
			};
			GPIO_u8PinInit(&Pin_Config);
		}
		break;
	default:
		break;
	}
}
/*---------------------------------------------------------------------------------
 *
 *     NAME     	 : GPIO_u8SetPinStatus()
 *     FUNCTIONALITY : Set the selected PIN state
 *     ARGUMENT 	 : PORT - PIN - Value
 *     RETURN   	 : uint8_t Error State
 *
 *---------------------------------------------------------------------------------*/
uint8_t GPIO_u8SetPinStatus(Port_t Port,Pin_t Pin,PinVal_t State )
{
	uint8_t	Local_u8ErrorState=OK;

	if (	(Port<=PORTG)		&& 		(Pin<=PIN15)	)
	{
		if (State == HIGH_V)
			GPIO_PORT[Port]->BSSR	=	1<<Pin;
		else if (State == LOW_V)
			GPIO_PORT[Port]->BSSR	=	1<<(Pin+16);
	}
	else
	{
		Local_u8ErrorState	= InvalidPORTPIN;
	}

	return Local_u8ErrorState;
}


/*---------------------------------------------------------------------------------
 *
 *     NAME     	 : GPIO_u8SetPortStatus()
 *     FUNCTIONALITY : Set the selected Port state
 *     ARGUMENT 	 : PORT - PIN - Value
 *     RETURN   	 : uint8_t Error State
 *
 *---------------------------------------------------------------------------------*/
uint8_t GPIO_u8SetPortStatus(Port_t Port,Pin_t Pin,PinVal_t State )
{
	uint8_t	Local_u8ErrorState=OK;

	if(Port == PORTA || Port == PORTB)
	{
		for(uint8_t i=Pin;i<=15;i++)
		{
			if (	(Port<=PORTG)		&& 		(Pin<=PIN15)	)
			{
				if (State == HIGH_V)
					GPIO_PORT[Port]->BSSR	=	1<<Pin;
				else if (State == LOW_V)
					GPIO_PORT[Port]->BSSR	=	1<<(Pin+16);
				Pin++;
			}
			else
			{
				Local_u8ErrorState	= InvalidPORTPIN;
			}
		}
	}
	else if(Port == PORTC )
	{
		for(uint8_t i=Pin;i<=15;i++)
		{
			if(Pin < 13)
				Pin = 13;
			if (	(Port<=PORTG)		&& 		(Pin<=PIN15)	)
			{
				if (State == HIGH_V)
					GPIO_PORT[Port]->BSSR	=	1<<Pin;
				else if (State == LOW_V)
					GPIO_PORT[Port]->BSSR	=	1<<(Pin+16);
				Pin++;
			}
			else
			{
				Local_u8ErrorState	= InvalidPORTPIN;
			}
		}
	}

	return Local_u8ErrorState;
}

/*---------------------------------------------------------------------------------
 *
 *     NAME     	 : GPIO_u8ReadPinStatus()
 *     FUNCTIONALITY : READ the selected PIN state
 *     ARGUMENT 	 : Port - PIN - Variable address to save the state
 *     RETURN   	 : uint8_t Error State
 *
 *---------------------------------------------------------------------------------*/
uint8_t GPIO_u8ReadPinStatus(Port_t Port,Pin_t Pin, PinVal_t * State )
{
	uint8_t Local_u8ErrorState = OK;

	if (State != NULL)
	{
		if (Port <=PORTG && Pin<=PIN15)
		{
			*State = ((GPIO_PORT[Port]->IDR)>>Pin)&1;
		}
		else
		{
			Local_u8ErrorState = InvalidPORTPIN;
		}
	}
	else {
		Local_u8ErrorState = Null_Pointer;

	}
	return Local_u8ErrorState;
}


/*---------------------------------------------------------------------------------
 *
 *     NAME     	 : GPIO_u8TogglePinStatus()
 *     FUNCTIONALITY : Toggle the selected PIN state
 *     ARGUMENT 	 : Port - PIN
 *     RETURN   	 : uint8_t Error State
 *
 *---------------------------------------------------------------------------------*/
uint8_t GPIO_u8TogglePinStatus(Port_t Port,Pin_t Pin)
{
	uint8_t Local_u8ErrorState = OK;

	if (Port <=PORTG && Pin<=PIN15)
	{
		GPIO_PORT[Port]->ODR ^= 1<<Pin;
	}
	else
	{
		Local_u8ErrorState = InvalidPORTPIN;
	}

	return Local_u8ErrorState;
}


