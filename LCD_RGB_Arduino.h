/*
  I2C_ADC_Suli.h

  This is a Suly compatible Library

  2014 Copyright (c) Seeed Technology Inc.  All right reserved.

  Loovee
  2014-4-15

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef __LCD_RGB_ARDUINO_H__
#define __LCD_RGB_ARDUINO_H__

#include "Arduino.h"
#include "LCD_RGB_Suli.h"

class rgb_lcd 
{

public:

    void begin(uint8 cols, uint8 rows, uint8 charsize = LCD_5x8DOTS)
    {
        suli_i2c_init(&Wire);
        rgb_lcd_init(&Wire, cols, rows, LCD_5x8DOTS);
        setRGB(255, 255, 255);
    }
    
    void write(unsigned char dta)
    {
        rgb_lcd_write(dta);
    }
    
    void setRGB(unsigned char r, unsigned char g, unsigned char b)
    {
        rgb_lcd_setRGB(r, g, b);
    }    
    
    void print(char *str)
    {
        rgb_lcd_print(str);
    }
    
    void print(int num)
    {
        char str[10];
        sprintf(str, "%d", num);
        print(str);
    }
    
    void print(char c)
    {
        rgb_lcd_write(c);
    }
    
    // x: 0-15
    // y: 0-1
    void setCursor(int x, int y)
    {
        rgb_lcd_setCursor(x, y);
    }
    
    void clear(){rgb_lcd_clear();}
    void home(){rgb_lcd_home();}

    void noDisplay(){rgb_lcd_noDisplay();}
    void display(){rgb_lcd_display();}
    void noBlink(){rgb_lcd_noBlink();}
    void blink(){rgb_lcd_blink();}
    void noCursor(){rgb_lcd_noCursor();}
    void cursor(){rgb_lcd_cursor();}
    void scrollDisplayLeft(){rgb_lcd_scrollDisplayLeft();}
    void scrollDisplayRight(){rgb_lcd_scrollDisplayRight();}
    void leftToRight(){rgb_lcd_leftToRight();}
    void rightToLeft(){rgb_lcd_rightToLeft();}
    void autoscroll(){rgb_lcd_autoscroll();}
    void noAutoscroll(){rgb_lcd_no_autoscroll();}

    void createChar(uint8 location, uint8 *charmap){rgb_lcd_create_char(location, charmap);}
    void setCursor(uint8 col, uint8 row){rgb_lcd_setCursor(col, row);}
    
    void setPWM(unsigned char color, unsigned char pwm){rgb_lcd_setPwm(color, pwm);}      // set pwm
    
/*
    // color control
    void setRGB(unsigned char r, unsigned char g, unsigned char b)                  // set rgb
    {
        rgb_lcd_setRGB(r, g, b);
    }
    
     void setPWM(unsigned char color, unsigned char pwm){rgb_lcd_setPwm(color, pwm)}      // set pwm

    void setColor(unsigned char color);
    void setColorAll(){setRGB(0, 0, 0);}
    void setColorWhite(){setRGB(255, 255, 255);}
*/
    
};

#endif