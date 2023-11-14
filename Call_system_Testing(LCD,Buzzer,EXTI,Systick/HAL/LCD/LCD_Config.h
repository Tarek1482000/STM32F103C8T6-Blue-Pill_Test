/*=================================================================================*/
/*  File        : LCD_Config.h                                                     */
/*  Description : This Header file includes LCD Config                             */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#ifndef HAL_LCD_INC_LCD_CONFIG_H_
#define HAL_LCD_INC_LCD_CONFIG_H_

#include "../../MCAL/GPIO/GPIO_Interface.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* LCD Data bits mode configuration, its value should be 4 or 8*/
#define LCD_DATA_BITS_MODE 4

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

/* LCD HW Ports and Pins Id */
#define LCD_RS_PORT_ID                  PORTB
#define LCD_RS_PIN_ID                   PIN12

#define LCD_RW_PORT_ID                  PORTB
#define LCD_RW_PIN_ID                   PIN13

#define LCD_E_PORT_ID                   PORTB
#define LCD_E_PIN_ID                    PIN13

#define LCD_DATA_PORT_ID               PORTA

#if (LCD_DATA_BITS_MODE == 8)
#define LCD_DB0_PIN_ID                 PIN0
#define LCD_DB1_PIN_ID                 PIN1
#define LCD_DB2_PIN_ID                 PIN2
#define LCD_DB3_PIN_ID                 PIN3
#define LCD_DB4_PIN_ID                 PIN4
#define LCD_DB5_PIN_ID                 PIN5
#define LCD_DB6_PIN_ID                 PIN6
#define LCD_DB7_PIN_ID                 PIN7
#elif (LCD_DATA_BITS_MODE == 4)
#define LCD_DB4_PIN_ID                 PIN3
#define LCD_DB5_PIN_ID                 PIN2
#define LCD_DB6_PIN_ID                 PIN1
#define LCD_DB7_PIN_ID                 PIN0
#endif



#endif /* LCD_H_ */
