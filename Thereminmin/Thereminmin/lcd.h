/*
 * lcd.h
 *
 * Created: 16/02/2022 10:14:50
 *  Author: stijn
 */ 


#ifndef LCD_H
#define LCD_H

void LCD_init();
void LCD_clear();
void LCD_display_text(char *str);
void LCD_set_cursor(int position);

#endif