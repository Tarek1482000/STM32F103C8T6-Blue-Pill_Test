/*=================================================================================*/
/*  File        : LCD_Interface.h                                                  */
/*  Description : This Header file includes LCD Interface                          */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#ifndef HAL_LCD_INC_LCD_INTERFACE_H_
#define HAL_LCD_INC_LCD_INTERFACE_H_
/*************************************************
 * Main Includes
 ************************************************/
#include "LCD_Config.h"
#include "LCD_Private.h"

#include "../../MCAL/RCC/RCC_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"

#include "../../LIBRARY/ErrTypes.h"
#include "../../LIBRARY/BitMath.h"



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8_t command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8_t data);

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8_t row,uint8_t col);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8_t row,uint8_t col,const char *Str);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data);

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void);
#endif /* HAL_LCD_INC_LCD_INTERFACE_H_ */
