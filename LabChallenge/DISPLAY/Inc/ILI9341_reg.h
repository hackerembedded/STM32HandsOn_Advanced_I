/*
 * ILI9341_reg.h
 *
 *  Created on: Jul 14, 2026
 *      Author: botelhod
 */

#ifndef INC_ILI9341_REG_H_
#define INC_ILI9341_REG_H_


/* Exported Defines - Command Set -------------------------------------------------- */
#define	DCS_NOP	                        				0x00
#define	DCS_SOFT_RESET	                				0x01
#define	DCS_GET_RED_CHANNEL	        					0x06
#define	DCS_GET_GREEN_CHANNEL	        				0x07
#define	DCS_GET_BLUE_CHANNEL	       					0x08
#define DCS_GET_DISPLAY_STATUS							0x09
#define	DCS_GET_POWER_MODE	        					0x0A
#define	DCS_GET_ADDRESS_MODE	        				0x0B
#define	DCS_GET_PIXEL_FORMAT	        				0x0C
#define	DCS_GET_DISPLAY_MODE	        				0x0D
#define	DCS_GET_SIGNAL_MODE	        					0x0E
#define	DCS_GET_DIAGNOSTIC_RESULT						0x0F
#define	DCS_ENTER_SLEEP_MODE	       					0x10
#define	DCS_EXIT_SLEEP_MODE	        					0x11
#define	DCS_ENTER_PARTIAL_MODE	        				0x12
#define	DCS_ENTER_NORMAL_MODE	        				0x13
#define	DCS_EXIT_INVERT_MODE	        				0x20
#define	DCS_ENTER_INVERT_MODE	        				0x21
#define	DCS_SET_GAMMA_CURVE	       						0x26
#define	DCS_SET_DISPLAY_OFF	        					0x28
#define	DCS_SET_DISPLAY_ON	        					0x29
#define	DCS_SET_COLUMN_ADDRESS	       					0x2A
#define	DCS_SET_PAGE_ADDRESS	       					0x2B
#define	DCS_WRITE_MEMORY_START	        				0x2C
#define	DCS_WRITE_LUT	                				0x2D
#define	DCS_READ_MEMORY_START	        				0x2E
#define	DCS_SET_PARTIAL_ROWS	        				0x30
#define	DCS_SET_PARTIAL_COLUMNS	        				0x31
#define	DCS_SET_SCROLL_AREA	        					0x33
#define	DCS_SET_TEAR_OFF	        					0x34
#define	DCS_SET_TEAR_ON	               					0x35
#define	DCS_SET_ADDRESS_MODE	        				0x36
#define	DCS_SET_SCROLL_START	        				0x37
#define	DCS_EXIT_IDLE_MODE	        					0x38
#define	DCS_ENTER_IDLE_MODE	        					0x39
#define	DCS_SET_PIXEL_FORMAT	        				0x3A
#define	DCS_WRITE_MEMORY_CONTINUE						0x3C
#define	DCS_SET_3D_CONTROL	        					0x3D
#define	DCS_READ_MEMORY_CONTINUE						0x3E
#define	DCS_GET_3D_CONTROL	        					0x3F
#define	DCS_SET_VSYNC_TIMING	        				0x40
#define	DCS_SET_TEAR_SCANLINE	        				0x44
#define	DCS_GET_SCANLINE	        					0x45
#define	DCS_READ_DDB_START	        					0xA1
#define	DCS_READ_DDB_CONTINUE	        				0xA8
#define DCS_SET_BRIGHTNESS								0x51
#define DCS_GET_DISPLAY_BRIGHTNESS						0x52
#define DCS_SET_CTRL_DISPLAY							0x53
#define DCS_GET_CTRL_DISPLAY							0x54
#define DCS_GET_ID1										0xDA
#define DCS_GET_ID2										0xDB
#define DCS_GET_ID3										0xDC


#endif /* INC_ILI9341_REG_H_ */
