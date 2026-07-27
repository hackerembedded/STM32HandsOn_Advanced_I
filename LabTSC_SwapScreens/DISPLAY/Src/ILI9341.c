/*
 * ILI9341.h
 *
 *  Created on: May 19, 2023
 *      Author: botel
 */

/* Private Includes ---------------------------------------------------------------- */
#include "ILI9341.h"
#include "ILI9341_conf.h"
#include "ILI9341_reg.h"


/* Private Defines ----------------------------------------------------------------- */
#define PA_DATA_MASK (GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10)
#define PB_DATA_MASK (GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_10)
#define PC_DATA_MASK (GPIO_PIN_7)

/* Private Macros ------------------------------------------------------------------ */
#define DISP_CSX_LOW()			DISPLAY_CSX_PORT->BSRR  |= (DISPLAY_CSX_PIN << 16)
#define DISP_CSX_HIGH()			DISPLAY_CSX_PORT->BSRR |= DISPLAY_CSX_PIN

#define DISP_DCX_LOW()			DISPLAY_DCX_PORT->BSRR  |= (DISPLAY_DCX_PIN << 16)
#define DISP_DCX_HIGH()			DISPLAY_DCX_PORT->BSRR |= DISPLAY_DCX_PIN

#define DISP_WRX_LOW()			DISPLAY_WRX_PORT->BSRR  |= (DISPLAY_WRX_PIN << 16)
#define DISP_WRX_HIGH()			DISPLAY_WRX_PORT->BSRR |= DISPLAY_WRX_PIN

#define DISP_NRST_LOW()			DISPLAY_NRST_PORT->BSRR  |= (DISPLAY_NRST_PIN << 16)
#define DISP_NRST_HIGH()		DISPLAY_NRST_PORT->BSRR |= DISPLAY_NRST_PIN

#define DISP_D0_LOW()			DISPLAY_D0_PORT->BSRR  |= (DISPLAY_D0_PIN << 16)
#define DISP_D0_HIGH()			DISPLAY_D0_PORT->BSRR  |= DISPLAY_D0_PIN

#define DISP_D1_LOW() 			DISPLAY_D1_PORT->BSRR  |= (DISPLAY_D1_PIN << 16)
#define DISP_D1_HIGH()			DISPLAY_D1_PORT->BSRR  |= DISPLAY_D1_PIN

#define DISP_D2_LOW()			DISPLAY_D2_PORT->BSRR  |= (DISPLAY_D2_PIN << 16)
#define DISP_D2_HIGH()			DISPLAY_D2_PORT->BSRR  |= DISPLAY_D2_PIN

#define DISP_D3_LOW()			DISPLAY_D3_PORT->BSRR  |= (DISPLAY_D3_PIN << 16)
#define DISP_D3_HIGH()			DISPLAY_D3_PORT->BSRR  |= DISPLAY_D3_PIN

#define DISP_D4_LOW()			DISPLAY_D4_PORT->BSRR  |= (DISPLAY_D4_PIN << 16)
#define DISP_D4_HIGH()			DISPLAY_D4_PORT->BSRR  |= DISPLAY_D4_PIN

#define DISP_D5_LOW()			DISPLAY_D5_PORT->BSRR  |= (DISPLAY_D5_PIN << 16)
#define DISP_D5_HIGH()			DISPLAY_D5_PORT->BSRR  |= DISPLAY_D5_PIN

#define DISP_D6_LOW()			DISPLAY_D6_PORT->BSRR  |= (DISPLAY_D6_PIN << 16)
#define DISP_D6_HIGH()			DISPLAY_D6_PORT->BSRR  |= DISPLAY_D6_PIN

#define DISP_D7_LOW()			DISPLAY_D7_PORT->BSRR  |= (DISPLAY_D7_PIN << 16)
#define DISP_D7_HIGH()			DISPLAY_D7_PORT->BSRR  |= DISPLAY_D7_PIN


/* Private Global Variables -------------------------------------------------------- */
/* Private Function Prototypes ----------------------------------------------------- */
void Display_Reset(void);
void Display_On(void);
void Display_Off(void);
void Display_write_8(uint8_t data);
void Display_Command_Send(uint8_t command);
void Display_Command_Send_With_Data(uint8_t command, uint8_t* data, uint32_t size);
void Display_Command_Send_With_Data16(uint8_t command, uint16_t* data, uint32_t size);
void Display_Set_Area(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);


/* Private Functions --------------------------------------------------------------- */
void Display_Reset(void)
{
	DISP_NRST_LOW();
	HAL_Delay(100);
	DISP_NRST_HIGH();
	HAL_Delay(100);
}

void Display_On(void)
{
	/* Turn the Display ON */
	Display_Command_Send(DCS_SET_DISPLAY_ON);
	HAL_Delay(20);
}

void Display_Off(void)
{
	/* Turn the Display OFF */
	Display_Command_Send(DCS_SET_DISPLAY_OFF);
	HAL_Delay(20);
}

void Display_write_8(uint8_t data)
{
	//	/* Local Variables */
	//    uint32_t pa = 0;
	//    uint32_t pb = 0;
	//    uint32_t pc = 0;
	//
	//    /* Compute the GPIO access */
	//    pa |= (data & (1<<0)) ? (1<<3)  : 0; //D0 - PA9
	//    pa |= (data & (1<<1)) ? (1<<7)  : 0;
	//    pb |= (data & (1<<2)) ? (1<<1)  : 0;
	//    pa |= (data & (1<<3)) ? (1<<12) : 0;
	//    pb |= (data & (1<<4)) ? (1<<5)  : 0;
	//    pb |= (data & (1<<5)) ? (1<<8)  : 0;
	//    pa |= (data & (1<<6)) ? (1<<10) : 0;
	//    pb |= (data & (1<<7)) ? (1<<15) : 0;
	//
	//    GPIOA->BSRR = pa | ((PA_DATA_MASK & ~pa) << 16);
	//    GPIOB->BSRR = pb | ((PB_DATA_MASK & ~pb) << 16);
	//    GPIOC->BSRR = pc | ((PC_DATA_MASK & ~pb) << 16);
#ifndef USE_OPTMIZATION
	    uint32_t pa =
	          ((data & 0x01) ? GPIO_PIN_9  : 0)
	        | ((data & 0x04) ? GPIO_PIN_10 : 0)
	        | ((data & 0x80) ? GPIO_PIN_8  : 0);

	    uint32_t pb =
	          ((data & 0x08) ? GPIO_PIN_3  : 0)
	        | ((data & 0x10) ? GPIO_PIN_5  : 0)
	        | ((data & 0x20) ? GPIO_PIN_4  : 0)
	        | ((data & 0x40) ? GPIO_PIN_10 : 0);

	    uint32_t pc =
	          ((data & 0x02) ? GPIO_PIN_7 : 0);

	    GPIOA->BSRR = pa | ((PA_DATA_MASK & ~pa) << 16);
	    GPIOB->BSRR = pb | ((PB_DATA_MASK & ~pb) << 16);
	    GPIOC->BSRR = pc | ((PC_DATA_MASK & ~pc) << 16);
#else

	if(data & 0b1)
		DISP_D0_HIGH();
	else
		DISP_D0_LOW();

	if(data & 0b10)
		DISP_D1_HIGH();
	else
		DISP_D1_LOW();

	if(data & 0b100)
		DISP_D2_HIGH();
	else
		DISP_D2_LOW();

	if(data & 0b1000)
		DISP_D3_HIGH();
	else
		DISP_D3_LOW();

	if(data & 0b10000)
		DISP_D4_HIGH();
	else
		DISP_D4_LOW();

	if(data & 0b100000)
		DISP_D5_HIGH();
	else
		DISP_D5_LOW();

	if(data & 0b1000000)
		DISP_D6_HIGH();
	else
		DISP_D6_LOW();

	if(data & 0b10000000)
		DISP_D7_HIGH();
	else
		DISP_D7_LOW();
#endif
}

void Display_Command_Send(uint8_t command)
{
	/* Reset the chip select pin */
	DISP_CSX_LOW();

	/* Reset the Data command pin - low = command */
	DISP_DCX_LOW();

	/* Reset the Write pin */
	DISP_WRX_LOW();

	/* Update the data pin signals */
	Display_write_8(command);

	/* Set the Write pin - force the display controller to read the data */
	DISP_WRX_HIGH();

	/* Set the data command pin - default state */
	DISP_DCX_HIGH();

	/* Reset the chip select pin */
	DISP_CSX_HIGH();
}

void Display_Command_Send_With_Data(uint8_t command, uint8_t* data, uint32_t size)
{
	/* Local variables */
	uint8_t *p_aux = data;

	/* Reset the chip select pin */
	DISP_CSX_LOW();

	/* Reset the Data command pin - low = command */
	DISP_DCX_LOW();

	/* Reset the Write pin */
	DISP_WRX_LOW();

	/* Update the data pin signals */
	Display_write_8(command);

	/* Set the Write pin - force the display controller to read the data */
	DISP_WRX_HIGH();

	/* Set the data command pin - high = data */
	DISP_DCX_HIGH();

	/* Loop to transmit all data */
	for(uint16_t i = 0; i < (size); i++)
	{
		/* Reset the Write pin */
		DISP_WRX_LOW();

		/* Update the data pin signals */
		Display_write_8(*p_aux);
		p_aux++;

		/* Set the Write pin - force the display controller to read the data */
		DISP_WRX_HIGH();
	}

	/* Reset the chip select pin */
	DISP_CSX_HIGH();
}

void Display_Command_Send_With_Data16(uint8_t command, uint16_t* data, uint32_t size)
{
	/* Local variables */
	uint8_t *p_aux = (uint8_t*)data;

	/* Reset the chip select pin */
	DISP_CSX_LOW();

	/* Reset the Data command pin - low = command */
	DISP_DCX_LOW();

	/* Reset the Write pin */
	DISP_WRX_LOW();

	/* Update the data pin signals */
	Display_write_8(command);

	/* Set the Write pin - force the display controller to read the data */
	DISP_WRX_HIGH();

	/* Set the data command pin - high = data */
	DISP_DCX_HIGH();

	/* Loop to transmit all data */
	for(uint16_t i = 0; i < (size); i++)
	{
		/* Reset the Write pin */
		DISP_WRX_LOW();

		/* Update the data pin signals */
		Display_write_8(p_aux[1]);

		/* Set the Write pin - force the display controller to read the data */
		DISP_WRX_HIGH();

		/* Reset the Write pin */
		DISP_WRX_LOW();

		/* Update the data pin signals */
		Display_write_8(p_aux[0]);
		p_aux+=2;

		/* Set the Write pin - force the display controller to read the data */
		DISP_WRX_HIGH();
	}

	/* Reset the chip select pin */
	DISP_CSX_HIGH();
}

void Display_Set_Area(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
	/* Local Variables */
	uint8_t arguments[4];

	/* Set columns */
	arguments[0] = x0 >> 8;
	arguments[1] = x0 & 0xFF;
	arguments[2] = x1 >> 8;
	arguments[3] = x1 & 0xFF;

	/* Send Command */
	Display_Command_Send_With_Data(DCS_SET_COLUMN_ADDRESS, arguments, 4);

	/* Set rows */
	arguments[0] = y0 >> 8;
	arguments[1] = y0 & 0xFF;
	arguments[2] = y1 >> 8;
	arguments[3] = y1 & 0xFF;

	/* Send Command */
	Display_Command_Send_With_Data(DCS_SET_PAGE_ADDRESS, arguments, 4);
}


/* Exported Functions -------------------------------------------------------------- */
void ILI9341_Init(void)
{
	/* Local Variables */
	uint8_t arguments[4];

	/* Set the CS and NRST pin */
	DISP_CSX_HIGH();
	DISP_NRST_HIGH();

	/* Reset the Display */
	Display_Reset();

	/* Sleep Out */
	Display_Command_Send(DCS_EXIT_SLEEP_MODE);
	HAL_Delay(100);

	/* Display Normal mode */
	Display_Command_Send(DCS_ENTER_NORMAL_MODE);
	HAL_Delay(100);

	/* MADCTL: Mirror X */
	arguments[0] = 0x48;
	Display_Command_Send_With_Data(DCS_SET_ADDRESS_MODE, arguments, 1);
	HAL_Delay(100);

	/* Pixel Format */
	arguments[0] = 0x05; // RGB565
	Display_Command_Send_With_Data(DCS_SET_PIXEL_FORMAT, arguments, 1);
	HAL_Delay(100);

	/* Turn display on */
	Display_On();
}

void ILI9341_Draw_Bitmap(uint16_t *data, uint16_t posx, uint16_t posy, uint16_t sizex, uint16_t sizey)
{
	/* Local Variables */
	uint8_t command = DCS_WRITE_MEMORY_START;
	uint32_t size = sizex * sizey;

	/* Define the Display Area */
	Display_Set_Area(posx, posy, posx + sizex - 1, posy + sizey - 1);

	/* Send the pixels to the display */
	Display_Command_Send_With_Data16(command, data, size);
}
