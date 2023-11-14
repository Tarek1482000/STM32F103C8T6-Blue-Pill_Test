/*=================================================================================*/
/*  File        : LCD_Program.c                                                    */
/*  Description : This Program file includes LCD program                           */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#include <stdint.h>
#include "../../LIBRARY/BitMath.h" /* For GET_BIT Macro */
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"


PinConfig_t RS_CONFIG =
{
		.Port_Num    = LCD_RS_PORT_ID,
		.Pin_Num     = LCD_RS_PIN_ID,
		.Mode        = OUTPUT_MSPEED,
		.Input_Type  = ANALOG_INPUT,
		.Output_Type = GP_PUSH_PULL,
		.PullType    = PULLDOWN,
};


PinConfig_t E_CONFIG =
{
		.Port_Num    = LCD_E_PORT_ID,
		.Pin_Num     = LCD_E_PIN_ID,
		.Mode        = OUTPUT_MSPEED,
		.Input_Type  = ANALOG_INPUT,
		.Output_Type = GP_PUSH_PULL,
		.PullType    = PULLDOWN,
};



PinConfig_t RW_CONFIG =
{
		.Port_Num    = LCD_RW_PORT_ID,
		.Pin_Num     = LCD_RW_PIN_ID,
		.Mode        = OUTPUT_MSPEED,
		.Input_Type  = ANALOG_INPUT,
		.Output_Type = GP_PUSH_PULL,
		.PullType    = PULLDOWN,
};

#if(LCD_DATA_BITS_MODE == 8)
PinConfig_t DATA0_CONFIG =
{
		.Port_Num    = LCD_DATA_PORT_ID,
		.Pin_Num     = LCD_DB0_PIN_ID,
		.Mode        = OUTPUT_MSPEED,
		.Input_Type  = ANALOG_INPUT,
		.Output_Type = GP_PUSH_PULL,
		.PullType    = PULLDOWN,
};
PinConfig_t DATA1_CONFIG =
{
		.Port_Num    = LCD_DATA_PORT_ID,
		.Pin_Num     = LCD_DB1_PIN_ID,
		.Mode        = OUTPUT_MSPEED,
		.Input_Type  = ANALOG_INPUT,
		.Output_Type = GP_PUSH_PULL,
		.PullType    = PULLDOWN,
};
PinConfig_t DATA2_CONFIG =
{
		.Port_Num    = LCD_DATA_PORT_ID,
		.Pin_Num     = LCD_DB2_PIN_ID,
		.Mode        = OUTPUT_MSPEED,
		.Input_Type  = ANALOG_INPUT,
		.Output_Type = GP_PUSH_PULL,
		.PullType    = PULLDOWN,
};
PinConfig_t DATA3_CONFIG =
{
		.Port_Num    = LCD_DATA_PORT_ID,
		.Pin_Num     = LCD_DB3_PIN_ID,
		.Mode        = OUTPUT_MSPEED,
		.Input_Type  = ANALOG_INPUT,
		.Output_Type = GP_PUSH_PULL,
		.PullType    = PULLDOWN,
};
#endif
PinConfig_t DATA4_CONFIG =
{
		.Port_Num    = LCD_DATA_PORT_ID,
		.Pin_Num     = LCD_DB4_PIN_ID,
		.Mode        = OUTPUT_MSPEED,
		.Input_Type  = ANALOG_INPUT,
		.Output_Type = GP_PUSH_PULL,
		.PullType    = PULLDOWN,
};
PinConfig_t DATA5_CONFIG =
{
		.Port_Num    = LCD_DATA_PORT_ID,
		.Pin_Num     = LCD_DB5_PIN_ID,
		.Mode        = OUTPUT_MSPEED,
		.Input_Type  = ANALOG_INPUT,
		.Output_Type = GP_PUSH_PULL,
		.PullType    = PULLDOWN,
};
PinConfig_t DATA6_CONFIG =
{
		.Port_Num    = LCD_DATA_PORT_ID,
		.Pin_Num     = LCD_DB6_PIN_ID,
		.Mode        = OUTPUT_MSPEED,
		.Input_Type  = ANALOG_INPUT,
		.Output_Type = GP_PUSH_PULL,
		.PullType    = PULLDOWN,
};
PinConfig_t DATA7_CONFIG =
{
		.Port_Num    = LCD_DATA_PORT_ID,
		.Pin_Num     = LCD_DB7_PIN_ID,
		.Mode        = OUTPUT_MSPEED,
		.Input_Type  = ANALOG_INPUT,
		.Output_Type = GP_PUSH_PULL,
		.PullType    = PULLDOWN,
};


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void)
{

	/* Configure the direction for RS , E and RW pins as output pins */
	GPIO_u8PinInit(&RS_CONFIG);
	GPIO_u8PinInit(&E_CONFIG);
	SYSTICK_u8Delay_ms(20);		/* LCD Power ON delay always > 15ms */

#if(LCD_DATA_BITS_MODE == 4)
	/* Configure 4 pins in the data port as output pins */
	GPIO_u8PinInit(&DATA4_CONFIG);
	GPIO_u8PinInit(&DATA5_CONFIG);
	GPIO_u8PinInit(&DATA6_CONFIG);
	GPIO_u8PinInit(&DATA7_CONFIG);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif(LCD_DATA_BITS_MODE == 8)
	/* Configure the data port as output port */
	GPIO_u8PinInit(&DATA0_CONFIG);
	GPIO_u8PinInit(&DATA1_CONFIG);
	GPIO_u8PinInit(&DATA2_CONFIG);
	GPIO_u8PinInit(&DATA3_CONFIG);
	GPIO_u8PinInit(&DATA4_CONFIG);
	GPIO_u8PinInit(&DATA5_CONFIG);
	GPIO_u8PinInit(&DATA6_CONFIG);
	GPIO_u8PinInit(&DATA7_CONFIG);

	/* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#endif

	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8_t command)
{

	GPIO_u8SetPinStatus(LCD_RW_PORT_ID, LCD_RW_PIN_ID, LOW_V); /* Instruction Mode RW=0 */
	GPIO_u8SetPinStatus(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOW_V); /* Instruction Mode RS=0 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Tas = 50ns */

	GPIO_u8SetPinStatus(LCD_E_PORT_ID,LCD_E_PIN_ID,HIGH_V); /* Enable LCD E=1 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,4));
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(command,5));
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(command,6));
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(command,7));

	SYSTICK_u8Delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_u8SetPinStatus(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW_V); /* Disable LCD E=0 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_u8SetPinStatus(LCD_E_PORT_ID,LCD_E_PIN_ID,HIGH_V); /* Enable LCD E=1 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,0));
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(command,1));
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(command,2));
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(command,3));

	SYSTICK_u8Delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_u8SetPinStatus(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW_V); /* Disable LCD E=0 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
	GPIO_writePort(LCD_DATA_PORT_ID,command); /* out the required command to the data bus D0 --> D7 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_u8SetPinStatus(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW_V); /* Disable LCD E=0 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8_t data)
{
	GPIO_u8SetPinStatus(LCD_RW_PORT_ID,LCD_RW_PIN_ID,LOW_V); /* Instruction Mode RW=0 */
	GPIO_u8SetPinStatus(LCD_RS_PORT_ID,LCD_RS_PIN_ID,HIGH_V); /* Data Mode RS=1 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_u8SetPinStatus(LCD_E_PORT_ID,LCD_E_PIN_ID,HIGH_V); /* Enable LCD E=1 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(data,4));
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(data,5));
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(data,6));
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(data,7));

	SYSTICK_u8Delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_u8SetPinStatus(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW_V); /* Disable LCD E=0 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_u8SetPinStatus(LCD_E_PORT_ID,LCD_E_PIN_ID,HIGH_V); /* Enable LCD E=1 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(data,0));
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(data,1));
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(data,2));
	GPIO_u8SetPinStatus(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(data,3));

	SYSTICK_u8Delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_u8SetPinStatus(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW_V); /* Disable LCD E=0 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
	GPIO_writePort(LCD_DATA_PORT_ID,data); /* out the required command to the data bus D0 --> D7 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_u8SetPinStatus(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW_V); /* Disable LCD E=0 */
	SYSTICK_u8Delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
	/***************** Another Method ***********************
	while((*Str) != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}		
	 *********************************************************/
}

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8_t row,uint8_t col)
{
	uint8_t lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		lcd_memory_address=col;
		break;
	case 1:
		lcd_memory_address=col+0x40;
		break;
	case 2:
		lcd_memory_address=col+0x10;
		break;
	case 3:
		lcd_memory_address=col+0x50;
		break;
	}					
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8_t row,uint8_t col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_displayString(buff); /* Display the string */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}
