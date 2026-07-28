#include "touch.h"

extern ADC_HandleTypeDef hadc1;

/* Private Functions --------------------------------------------------------*/

static void GPIO_RestoreAfterTouch(void);
static void GPIO_Output(GPIO_TypeDef *port,
                        uint16_t pin,
                        GPIO_PinState state);

static void GPIO_Input(GPIO_TypeDef *port,
                       uint16_t pin);

static void GPIO_Analog(GPIO_TypeDef *port,
                        uint16_t pin);

static uint16_t ADC_Read(uint32_t channel);

static uint16_t TS_ReadX_Avg(void);
static uint16_t TS_ReadY_Avg(void);

static int32_t map_value(
        int32_t x,
        int32_t in_min,
        int32_t in_max,
        int32_t out_min,
        int32_t out_max);

/* Public Functions ---------------------------------------------------------*/

void TS_Init(void)
{
    GPIO_RestoreAfterTouch();
}

uint16_t TS_ReadPressure(void)
{
    GPIO_Output(TS_XP_PORT, TS_XP_PIN, GPIO_PIN_RESET);
    GPIO_Output(TS_YM_PORT, TS_YM_PIN, GPIO_PIN_SET);

    GPIO_Input(TS_XM_PORT, TS_XM_PIN);
    GPIO_Input(TS_YP_PORT, TS_YP_PIN);

    for(volatile uint32_t i=0;i<500;i++);

    uint16_t z1 = ADC_Read(TS_ADC_XM_CH);
    uint16_t z2 = ADC_Read(TS_ADC_YP_CH);

    return (4095U - (z2 - z1));
}

uint8_t TS_IsTouched(void)
{
    uint16_t z = TS_ReadPressure();

    return ((z > MINPRESSURE) &&
            (z < MAXPRESSURE));
}

uint16_t TS_ReadX(void)
{
    GPIO_Input(TS_YP_PORT, TS_YP_PIN);
    GPIO_Input(TS_YM_PORT, TS_YM_PIN);

    GPIO_Output(TS_XP_PORT, TS_XP_PIN, GPIO_PIN_SET);
    GPIO_Output(TS_XM_PORT, TS_XM_PIN, GPIO_PIN_RESET);

    for(volatile uint32_t i=0;i<500;i++);

    GPIO_Analog(TS_YP_PORT, TS_YP_PIN);

    return (4095U - ADC_Read(TS_ADC_YP_CH));
}

uint16_t TS_ReadY(void)
{
    GPIO_Input(TS_XP_PORT, TS_XP_PIN);
    GPIO_Input(TS_XM_PORT, TS_XM_PIN);

    GPIO_Output(TS_YP_PORT, TS_YP_PIN, GPIO_PIN_SET);
    GPIO_Output(TS_YM_PORT, TS_YM_PIN, GPIO_PIN_RESET);

    for(volatile uint32_t i=0;i<500;i++);

    GPIO_Analog(TS_XM_PORT, TS_XM_PIN);

    return (4095U - ADC_Read(TS_ADC_XM_CH));
}

uint8_t TS_GetState(TS_State_t *state)
{
    uint16_t z1, z2, z;

    state->x_raw = TS_ReadX_Avg();
    state->y_raw = TS_ReadY_Avg();

    GPIO_Output(TS_XP_PORT, TS_XP_PIN, GPIO_PIN_RESET);
    GPIO_Output(TS_YM_PORT, TS_YM_PIN, GPIO_PIN_SET);

    GPIO_Input(TS_XM_PORT, TS_XM_PIN);
    GPIO_Input(TS_YP_PORT, TS_YP_PIN);

    GPIO_Analog(TS_XM_PORT, TS_XM_PIN);
    GPIO_Analog(TS_YP_PORT, TS_YP_PIN);

    z1 = ADC_Read(TS_ADC_XM_CH);
    z2 = ADC_Read(TS_ADC_YP_CH);

    z = 4095U - (z2 - z1);

    state->touched =
            ((z > MINPRESSURE) &&
             (z < MAXPRESSURE));

    GPIO_RestoreAfterTouch();

    if(state->touched)
    {
        state->x = map_value(
                state->x_raw,
                TS_X_MIN,
                TS_X_MAX,
                0,
                LCD_WIDTH - 1);

        state->y = map_value(
                state->y_raw,
                TS_Y_MIN,
                TS_Y_MAX,
                0,
                LCD_HEIGHT - 1);

        if(state->x >= LCD_WIDTH)
            state->x = LCD_WIDTH - 1;

        if(state->y >= LCD_HEIGHT)
            state->y = LCD_HEIGHT - 1;
    }
    else
    {
        state->x = 0;
        state->y = 0;
    }

    return state->touched;
}

/* Private Functions --------------------------------------------------------*/

static uint16_t TS_ReadX_Avg(void)
{
    uint32_t sum = 0;

    for(int i=0;i<4;i++)
        sum += TS_ReadX();

    return (uint16_t)(sum / 4);
}

static uint16_t TS_ReadY_Avg(void)
{
    uint32_t sum = 0;

    for(int i=0;i<4;i++)
        sum += TS_ReadY();

    return (uint16_t)(sum / 4);
}

static int32_t map_value(
        int32_t x,
        int32_t in_min,
        int32_t in_max,
        int32_t out_min,
        int32_t out_max)
{
    return (x - in_min) *
           (out_max - out_min) /
           (in_max - in_min) +
           out_min;
}

static uint16_t ADC_Read(uint32_t channel)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    sConfig.Channel = channel;
    sConfig.Rank = 1;
    sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES;

    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 10);

    uint16_t value = HAL_ADC_GetValue(&hadc1);

    HAL_ADC_Stop(&hadc1);

    return value;
}

static void GPIO_Output(GPIO_TypeDef *port,
                        uint16_t pin,
                        GPIO_PinState state)
{
    GPIO_InitTypeDef gpio = {0};

    gpio.Pin = pin;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

    HAL_GPIO_Init(port, &gpio);

    HAL_GPIO_WritePin(port, pin, state);
}

static void GPIO_Input(GPIO_TypeDef *port,
                       uint16_t pin)
{
    GPIO_InitTypeDef gpio = {0};

    gpio.Pin = pin;
    gpio.Mode = GPIO_MODE_INPUT;
    gpio.Pull = GPIO_PULLDOWN;

    HAL_GPIO_Init(port, &gpio);
}

static void GPIO_Analog(GPIO_TypeDef *port,
                        uint16_t pin)
{
    GPIO_InitTypeDef gpio = {0};

    gpio.Pin = pin;
    gpio.Mode = GPIO_MODE_ANALOG;
    gpio.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(port, &gpio);
}

static void GPIO_RestoreAfterTouch(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    HAL_GPIO_WritePin(LCD_RS_GPIO_Port,
                      LCD_RS_Pin,
                      GPIO_PIN_SET);

    GPIO_InitStruct.Pin = LCD_RS_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(LCD_RS_GPIO_Port, &GPIO_InitStruct);

    HAL_GPIO_WritePin(LCD_CS_GPIO_Port,
                      LCD_CS_Pin,
                      GPIO_PIN_SET);

    GPIO_InitStruct.Pin = LCD_CS_Pin;
    HAL_GPIO_Init(LCD_CS_GPIO_Port, &GPIO_InitStruct);

    HAL_GPIO_WritePin(LCD_D1_GPIO_Port,
                      LCD_D1_Pin,
                      GPIO_PIN_SET);

    GPIO_InitStruct.Pin = LCD_D1_Pin;
    HAL_GPIO_Init(LCD_D1_GPIO_Port, &GPIO_InitStruct);

    HAL_GPIO_WritePin(LCD_D0_GPIO_Port,
                      LCD_D0_Pin,
                      GPIO_PIN_SET);

    GPIO_InitStruct.Pin = LCD_D0_Pin;
    HAL_GPIO_Init(LCD_D0_GPIO_Port, &GPIO_InitStruct);
}
