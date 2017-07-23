#ifndef _ILI9340_FONT_H
#define _ILI9340_FONT_H

#include <stdint.h>

enum FontOptions
{
	TEXT_DEFAULT 		= 0x0000,	//!< No special options

    TEXT_TRANSPARENT	= 0x0001,	//!< Don't fill with background color

    WRAP_CHARACTER		= 0x0010,	//!< Wrap lines at each character
    WRAP_WORD 			= 0x0020,	//!< Wrap lines at each word

    ALIGN_CENTRE		= 0x0100,	//!< Align text at center of bounding box
	ALIGN_RIGHT			= 0x0200,	//!< Align text at right of bounding box
};

//These values must be defined to make the text look nice
#define FONT_HEIGHT 21
#define FONT_CHAR_GAP 2
#define FONT_SPACE_SIZE 5

typedef struct
{
    unsigned char charWidth;
    unsigned short charOffset;
} ILI9340_CHAR_INFO;

// Font data for Courier New 11pt
extern const unsigned char FONT_DATA[];
extern const ILI9340_CHAR_INFO CHAR_LOOKUP[];

#ifdef __cplusplus
extern "C" {
#endif

unsigned char char_offset(char c);
unsigned char char_width(char c);
unsigned short char_address(char c);

unsigned short line_width(char *c);

#ifdef __cplusplus
}
#endif

#endif
