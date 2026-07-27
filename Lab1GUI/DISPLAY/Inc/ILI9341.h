/*
 * ILI9341.h
 *
 *  Created on: May 19, 2023
 *      Author: botel
 */

#ifndef INC_ILI9341_H_
#define INC_ILI9341_H_

/* Exported Includes --------------------------------------------------------------- */
#include "main.h"


/* Exported Macros ----------------------------------------------------------------- */
#define RGB_to_565(__RED__, __GREEN__, __BLUE__)		((__RED__) | (__GREEN__ << 5) | (__BLUE__ << 11))


/* Exported Function Prototypes ---------------------------------------------------- */
void ILI9341_Init(void);
void ILI9341_Draw_Bitmap(uint16_t *data, uint16_t posx, uint16_t posy, uint16_t sizex, uint16_t sizey);


#endif /* INC_ILI9341_H_ */
