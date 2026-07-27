/*
 * ILI9341_conf.h
 *
 *  Created on: May 19, 2023
 *      Author: botel
 */

#ifndef INC_ILI9341_CONF_H_
#define INC_ILI9341_CONF_H_

/* Exported Includes --------------------------------------------------------------- */
#include "main.h"

/* Display Parameters */
#define DISPLAY_PIXELS_V				240
#define DISPLAY_PIXELS_H				320
#define DISPLAY_PIXELS_NBR				DISPLAY_PIXELS_H * DISPLAY_PIXELS_V
#define DISPLAY_PARTIAL_BUFFER_RATIO	8
#define DISPLAY_PARTIAL_BUFFER_SIZE		DISPLAY_PIXELS_NBR/DISPLAY_PARTIAL_BUFFER_RATIO

/* Display Pinout ------------------------------------------------------------------ */
#define DISPLAY_CSX_PORT				LCD_CS_GPIO_Port
#define DISPLAY_CSX_PIN					LCD_CS_Pin

#define DISPLAY_WRX_PORT				LCD_WR_GPIO_Port
#define DISPLAY_WRX_PIN					LCD_WR_Pin

#define DISPLAY_NRST_PORT				LCD_RST_GPIO_Port
#define DISPLAY_NRST_PIN				LCD_RST_Pin

#define DISPLAY_DCX_PORT				LCD_RS_GPIO_Port
#define DISPLAY_DCX_PIN					LCD_RS_Pin

#define DISPLAY_D0_PORT					LCD_D0_GPIO_Port
#define DISPLAY_D0_PIN					LCD_D0_Pin

#define DISPLAY_D1_PORT					LCD_D1_GPIO_Port
#define DISPLAY_D1_PIN					LCD_D1_Pin

#define DISPLAY_D2_PORT					LCD_D2_GPIO_Port
#define DISPLAY_D2_PIN					LCD_D2_Pin

#define DISPLAY_D3_PORT					LCD_D3_GPIO_Port
#define DISPLAY_D3_PIN					LCD_D3_Pin

#define DISPLAY_D4_PORT					LCD_D4_GPIO_Port
#define DISPLAY_D4_PIN					LCD_D4_Pin

#define DISPLAY_D5_PORT					LCD_D5_GPIO_Port
#define DISPLAY_D5_PIN					LCD_D5_Pin

#define DISPLAY_D6_PORT					LCD_D6_GPIO_Port
#define DISPLAY_D6_PIN					LCD_D6_Pin

#define DISPLAY_D7_PORT					LCD_D7_GPIO_Port
#define DISPLAY_D7_PIN					LCD_D7_Pin


#endif /* INC_ILI9341_CONF_H_ */
