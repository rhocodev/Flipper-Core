#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <Arduino.h>

// TODO - move all defined var of styles right here
// namespace Style {  }

#define FIRMWARE_NAME "Flipper-Core"
#define FIRMWARE_VERSION 0x001
#define FIRMWARE_MODEL "00A"
#define DISPLAY_INSTANCE U8G2_SSD1306_128X64_NONAME_1_HW_I2C
#define FONT_INSTANCE u8g2_font_6x10_tf
#define TEXT_MARGIN_TOP 4
#define TEXT_MARGIN_LEFT 8
#define FONT_HEIGHT 10
#define ICON_SIZE 10
#define ICON_PADDING_BOTTOM 8
#define ICON_PADDING 14
#define MENU_MARGIN_TOP 0
#define MAX_OPTIONS_BY_PAGE 5
#define MAX_OPTIONS_BY_MENU 7
#define DISPLAY_HEIGHT 64
#define DISPLAY_WgTIDTH 128
#define OPTIONS_GAP 1
#define CURSOR_MARGIN_BOTTOM 3
#define FPS 1000 / 30

#endif
