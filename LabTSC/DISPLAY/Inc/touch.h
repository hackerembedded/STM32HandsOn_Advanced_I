#ifndef __TOUCH_H
#define __TOUCH_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

/* Touch State --------------------------------------------------------------*/
typedef struct
{
    uint16_t x_raw;
    uint16_t y_raw;

    uint16_t x;
    uint16_t y;

    uint8_t touched;

} TS_State_t;


#define TS_X_MIN    480
#define TS_X_MAX    3700


#define TS_Y_MIN    390
#define TS_Y_MAX    3600


#define LCD_WIDTH   240
#define LCD_HEIGHT  320


#define MINPRESSURE   250
#define MAXPRESSURE   3500

#define TS_ADC hadc1
#define TS_ADC_YP_CH ADC_CHANNEL_8
#define TS_ADC_XM_CH ADC_CHANNEL_4
/* Public API ---------------------------------------------------------------*/
void TS_Init(void);

uint8_t  TS_IsTouched(void);
uint16_t TS_ReadX(void);
uint16_t TS_ReadY(void);
uint16_t TS_ReadPressure(void);

uint8_t TS_GetState(TS_State_t *state);

#ifdef __cplusplus
}
#endif

#endif /* __TOUCH_H */
