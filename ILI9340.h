#ifndef ILI9340_H_
#define ILI9340_H_

#include <stdint.h>

#include "ILI9340_defines.h"
#include "ILI9340_font.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Low-level inteface functions
 * These functions must be defined specific to the device:
 * void ILI9340_CS_Low()
 * void ILI9340_CS_High()
 * void ILI9340_DC_Low()
 * void ILI9340_DC_High()
 * void ILI9340_Reset_Low()
 * void ILI9340_Reset_High()
 * uint8_t ILI9340_TxRx_8bit(uint8_t data)
 * void ILI9340_Tx_16bit(uint16_t data)
 * voidILI9340_PauseMs()
**/

// This file must be defined by application
#include "ILI9340_linker.h"

// Generic graphic functions
uint16_t ILI9340_ColorFromRGB(uint8_t r, uint8_t g, uint8_t b); //!< Convert an RGB color into LCD color
uint8_t ILI9340_RedComponent(uint16_t);
uint8_t ILI9340_GreenComponent(uint16_t);
uint8_t ILI9340_BlueComponent(uint16_t);
void ILI9340_SetPenThickness(uint16_t t);
void ILI9340_SetTextOptions(uint16_t opt);
void ILI9340_SetBackgroundColor(uint16_t bg);
void ILI9340_SetTextSize(uint8_t ts);
uint8_t ILI9340_GetTextSize();

// SPI functions
void ILI9340_WriteCommand(uint8_t command);
void ILI9340_WriteData(uint8_t data);
void ILI9340_WriteDataBytes(uint16_t *data, uint16_t size);

void ILI9340_Reset();
void ILI9340_Initialize();	//!< ILI9340 initilization routines
void ILI9340_Rotate(uint8_t dir);
void ILI9340_SetAddressWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

void ILI9340_DrawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void ILI9340_FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void ILI9340_FillScreen(uint16_t color);
void ILI9340_ClearScreen();	//!< Clear the screen (background color)

void ILI9340_DrawBitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t *bitmapData);

void ILI9340_FillRect_HGradient(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t c1, uint16_t c2);
void ILI9340_FillRect_VGradient(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t c1, uint16_t c2);

void ILI9340_DrawPixel(uint16_t x, uint16_t y, uint16_t color);

void ILI9340_FillCircle(int16_t x, int16_t y, int16_t r, uint16_t color);
void ILI9340_DrawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);

void ILI9340_HorizontalLine(uint16_t x, uint16_t y, uint16_t w, uint16_t color);
void ILI9340_VerticalLine(uint16_t x, uint16_t y, uint16_t h, uint16_t color);

//Character functions
void ILI9340_DrawChar(uint16_t x, uint16_t y, char c, uint16_t color);
void ILI9340_DrawTransparentChar(uint16_t x, uint16_t y, char c, uint16_t color);
void ILI9340_DrawString(uint16_t x, uint16_t y, char *data, uint16_t color);

#ifdef __cplusplus
}
#endif

#endif /* SRC_ILI9340_H_ */
