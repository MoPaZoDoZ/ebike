// Inlcudes
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Defines
#define OLED_RESET 4
#define Pin_Charging 7
#define Pin_MotorSwitch 8
#define Pin_MotorControl 3
#define Pin_RPM 2



Adafruit_SSD1306 display(OLED_RESET);

const unsigned char PROGMEM Background [] = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x20, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0x87, 0x20, 0x00, 0x00, 0x47, 0x05, 0x10, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xB1, 0x88, 0xA0, 0x00, 0x00, 0xA8, 0x85, 0x10, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xAA, 0x88, 0x20, 0x00, 0x00, 0x48, 0x05, 0x26, 0x84, 0xB0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA4, 0x88, 0x20, 0x00, 0x00, 0x08, 0x05, 0xC5, 0x44, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0x88, 0x20, 0x00, 0x00, 0x08, 0x05, 0x25, 0x44, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0x88, 0xA0, 0x00, 0x00, 0x08, 0x85, 0x15, 0x48, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0xA7, 0x20, 0x00, 0x00, 0x07, 0x05, 0x15, 0x48, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x20, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x80, 0x20, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0xA0, 0x00, 0x00, 0x47, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xB1, 0xA0, 0x00, 0x00, 0xA8, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xAA, 0xA0, 0x00, 0x00, 0x48, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA4, 0xA0, 0x00, 0x00, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0xA0, 0x00, 0x00, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0xA0, 0x00, 0x00, 0x08, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0xA0, 0x00, 0x00, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x20, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x83, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xBF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA1, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA3, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA7, 0xE4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0xC4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA1, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA2, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xA0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xBF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};


const unsigned char PROGMEM Logo [] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x40, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x41, 0x00, 0x40, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x08, 0x80, 0x20, 0x80, 0x40, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x05, 0x00, 0x20, 0x70, 0x40, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x02, 0x80, 0x20, 0x18, 0x40, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x10, 0x01, 0x00, 0x20, 0x14, 0x40, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x82, 0x20, 0x0C, 0x40, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x82, 0x00, 0x0A, 0xC0, 0x20, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x04, 0x08, 0x00, 0x08, 0x20, 0x05, 0xC0, 0x04, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x81, 0x20, 0x06, 0x80, 0x32, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x24, 0x08, 0x00, 0x84, 0xA0, 0x05, 0x80, 0x8A, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x80, 0xA0, 0x06, 0x00, 0x02, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x08, 0x82, 0x84, 0x20, 0x06, 0x00, 0xF9, 0x40,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x51, 0x00, 0x48, 0x24, 0x86, 0x01, 0xFE, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x04, 0x40, 0x88, 0x80, 0x14, 0x1C, 0x04, 0x03, 0xFF, 0x20,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x55, 0x00, 0x08, 0x14, 0x4C, 0x03, 0xFF, 0x60,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x00, 0x0A, 0x08, 0x08, 0x14, 0x6C, 0x03, 0xF7, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x55, 0x04, 0x08, 0x1C, 0x34, 0x07, 0xFB, 0xA0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x2A, 0x02, 0x08, 0x14, 0x3C, 0x16, 0x3D, 0xE0,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x80, 0x80, 0x52, 0x02, 0x08, 0x14, 0x04, 0x10, 0x1F, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x02, 0x00, 0x2C, 0x06, 0x10, 0x1F, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x40, 0x01, 0x00, 0x80, 0x54, 0x02, 0x08, 0x34, 0x03, 0x10, 0x0F, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, 0x00, 0x52, 0x02, 0x00, 0x2E, 0x03, 0xF1, 0x8F, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x80, 0x54, 0x01, 0x08, 0x76, 0x02, 0xE3, 0xCF, 0xC0,
  0xFF, 0x8F, 0x80, 0x00, 0x17, 0xE8, 0x5E, 0x9D, 0x4A, 0xFF, 0x18, 0xDB, 0x7B, 0xE6, 0xE7, 0xFF,
  0xFE, 0x00, 0x00, 0x00, 0x03, 0xC1, 0x4E, 0x00, 0xAA, 0x60, 0x4A, 0xB5, 0x07, 0xC6, 0xE6, 0xFF,
  0x48, 0x80, 0x00, 0x00, 0x00, 0x04, 0x20, 0xB5, 0x55, 0x6F, 0xBF, 0xDF, 0xFF, 0xCD, 0x63, 0xE9,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x20, 0x54, 0x1F, 0xC9, 0xE7, 0x00,
  0x00, 0x00, 0x00, 0x7F, 0xFC, 0xFF, 0xF9, 0xFF, 0xD3, 0xFF, 0xAF, 0x69, 0xDF, 0xC9, 0x77, 0x00,
  0x00, 0x00, 0x00, 0x7F, 0xF8, 0xFF, 0xF1, 0xFF, 0xCB, 0xFF, 0x8F, 0x6B, 0xDF, 0xCB, 0xC7, 0x20,
  0x00, 0x00, 0x00, 0x00, 0x38, 0xE0, 0x01, 0xC0, 0xE3, 0x81, 0xCF, 0x73, 0x9F, 0xDF, 0x97, 0x20,
  0x00, 0x00, 0x00, 0x00, 0x39, 0xE0, 0x83, 0xC1, 0xE7, 0x83, 0xCF, 0x07, 0x3F, 0xCA, 0xC7, 0xE0,
  0x00, 0x00, 0x00, 0x00, 0x71, 0xC0, 0x03, 0x81, 0xD7, 0x03, 0x83, 0xDE, 0x7F, 0x8B, 0xD7, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x71, 0xC1, 0x13, 0x81, 0xC7, 0x03, 0xAB, 0xFC, 0xFF, 0xD1, 0xE5, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0xF3, 0xC0, 0x07, 0x83, 0xCF, 0x07, 0x9B, 0xF9, 0xFD, 0xCF, 0x85, 0xC0,
  0x00, 0x00, 0x01, 0xC0, 0xE3, 0xFF, 0x07, 0xFE, 0x2F, 0xFC, 0x28, 0xE3, 0xFF, 0xDB, 0x61, 0xC0,
  0x00, 0x00, 0x01, 0xC0, 0xE3, 0xFF, 0x27, 0xFE, 0xCF, 0xFD, 0x9D, 0xCF, 0xFB, 0xCF, 0xE9, 0xC0,
  0x00, 0x00, 0x03, 0xC1, 0xE7, 0x80, 0x2F, 0xF0, 0xDF, 0xE0, 0x69, 0xDF, 0xFF, 0xC6, 0x4A, 0xC0,
  0x00, 0x00, 0x03, 0x81, 0xC7, 0x00, 0x0E, 0xF2, 0x9D, 0xE5, 0xDB, 0xDF, 0xEF, 0xCB, 0xCF, 0x40,
  0x00, 0x00, 0x03, 0x81, 0xC7, 0x13, 0x0E, 0x38, 0x1C, 0x77, 0xB3, 0x9F, 0xFF, 0xCB, 0x8F, 0x80,
  0x00, 0x00, 0x07, 0x03, 0xCE, 0x00, 0x9E, 0x38, 0x3C, 0x72, 0xF3, 0xBF, 0xFF, 0xC7, 0x1F, 0xC0,
  0x00, 0x00, 0x07, 0x03, 0x8E, 0x00, 0x1C, 0x3C, 0xB9, 0x79, 0xF7, 0xBF, 0xFF, 0xC0, 0x1F, 0x80,
  0x00, 0x00, 0x01, 0xFE, 0x0F, 0xFF, 0x1C, 0x1E, 0x39, 0x3D, 0x77, 0x3F, 0xFF, 0xE0, 0x2F, 0x00,
  0x00, 0x00, 0x43, 0xFC, 0x1F, 0xFF, 0x38, 0x1E, 0x72, 0xBD, 0xF7, 0x7F, 0xFF, 0xF0, 0x2F, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x7F, 0xFF, 0xF8, 0x77, 0x00,
  0x00, 0x00, 0x20, 0x40, 0x20, 0x88, 0xA1, 0x41, 0x53, 0xA3, 0x15, 0x7F, 0xFF, 0xFD, 0xF3, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x7F, 0xFC, 0x1F, 0xFB, 0xFE, 0xFF, 0xBF, 0xEF, 0xFB, 0xFE, 0xF7, 0x7F, 0xDF, 0xB7, 0xFD, 0xFE,
  0x7F, 0xFE, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x80, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x49, 0x24, 0x92, 0x49, 0x24, 0x92, 0x49, 0x24, 0x92, 0x49, 0x24, 0x92, 0x49, 0x24, 0x92, 0x49
};

// Variables
int throttle = 0;
int throttle2 = 0;
int input = 0;
int on = 0;
int rpm_count = 0;
float rpm = 0;
int rpm_count_c = 0;
int timeold = 0;
int I = 0;
int charging = 0;
float motor_temp = 0;
int motor_amp_static = 0;
float mc_temp = 0;
float battery_voltage = 0;
float battery_level = 0;
int battery_bars = 0;
int T = 0;
int battery_voltage_data[4] {333, 333, 222, 444};

// Timing variables
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;


void setup() {
  tone(10, 200, 50);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  display.drawBitmap(0, 0,  Logo, 128, 64, WHITE);
  display.display();
  delay(1000);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  pinMode(Pin_Charging, INPUT_PULLUP);
  pinMode(Pin_MotorSwitch, OUTPUT);
  pinMode(Pin_MotorControl, OUTPUT);

  //TCCR2B = (TCCR2B & 0xF8) | 0x05;
  attachInterrupt(0, motor_rpm, CHANGE);

  for (int I = 0; I < 10; I++)
  {
    tone(10, 30 + I * 2);
    display.fillCircle(112, 45, I * 15, WHITE);
    display.fillCircle(112, 45, I * 15 - 2, BLACK);
    display.display();

  }
  noTone(10);

  draw_oled(false);
  display.fillRect(15, 46, 111, 16, BLACK);

  for (int I = 0; I < battery_bars; I++) {
    tone(10, 500 + I * 50);
    display.fillRect(15 + I * 4, 46, 3, 16, WHITE);
    display.display();
  }
  noTone(10);
  motor_amp_static = analogRead(A6) + analogRead(A7);
}





void loop() {

  // Timing
  unsigned long currentMillis = millis();

  battery_voltage_data[4] = analogRead(A2);
  charging = !digitalRead(7);
  if (charging == 1)
  {
    tone(10, 4000, 50);
    delay(1000);
  }
  else {
    input = analogRead(A0);
    throttle = max(map(input, 199, 860, 100, 0), 0);

    rpm_count_c = rpm_count;


    rpm = rpm_count_c;
    rpm_count = 0;

    throttle2 = max(min(throttle2 + 2, throttle - rpm * 3), 0);
    //analogWrite(11,throttle2*2.55);

    if (throttle > 0 && !on)
    {

      on = 1;
      tone(10, 2000, 50);
      delay(100);
      tone(10, 2000 + throttle * 50, 50);
      delay(100);
    }
    else if (throttle == 0 && on)
    {
      on = 0;
      tone(10, 1000, 150);
    }

    if (on == 1) {
      digitalWrite(8, false);
      analogWrite(3, throttle2 * 2.55);

    }
    else {
      I += 1;
      digitalWrite(8, false);
      analogWrite(3, 0);
    }

  }

  tone(10, 1000, 1);


  Serial.print("Throttle: ");
  Serial.print(input);
  Serial.print(" mapped: ");
  Serial.print(throttle2);
  Serial.print(" rpm: ");
  Serial.print(rpm);
  Serial.print(" rpm_count: ");
  Serial.print(rpm_count);
  Serial.print(" motor controller temp: ");

  Serial.print(3);
  Serial.print(" motor temp: ");
  Serial.print(analogRead(A1));
  Serial.print(" battery level: ");
  Serial.print(analogRead(A2));
  Serial.print("V");
  Serial.print(" Charging: ");
  Serial.print(charging);

  Serial.print(" Amp1: ");
  Serial.print(analogRead(A6));
  Serial.print(" Amp2: ");
  Serial.print(analogRead(A7));

  Serial.println("");

  battery_voltage_data[0] = battery_voltage_data[1];
  battery_voltage_data[1] = battery_voltage_data[2];
  battery_voltage_data[2] = battery_voltage_data[3];
  battery_voltage_data[3] = battery_voltage_data[4];

  // Update screen 500 ms
  if (currentMillis - previousMillis >= 500) {
    draw_oled(true);
    previousMillis = currentMillis;
  }
  
  // Update heavy stuff
  if (currentMillis - previousMillis2 >= 1000) {
    motor_temp = analogRead(A1);
    motor_temp = log(30000.0 * ((1024.0 / motor_temp - 1)));
    motor_temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * motor_temp * motor_temp )) * motor_temp );
    motor_temp = motor_temp - 273.15;

    mc_temp = analogRead(A3);
    mc_temp = log(22000.0 * ((1024.0 / mc_temp - 1)));
    mc_temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * mc_temp * mc_temp )) * mc_temp );
    mc_temp = mc_temp - 273.15;


    battery_voltage = ((battery_voltage_data[0] + battery_voltage_data[1] + battery_voltage_data[2] + battery_voltage_data[3]) / 4) * 0.0299;
    //battery_level=map(battery_voltage,23.78,25.32,0,100);
    battery_level = min(max(battery_voltage - 23.78, 0) / (25.72 - 23.78), 1) * 100;
    previousMillis2 = currentMillis;
  }


}

void motor_rpm() {
  rpm_count += 1;
}


void draw_oled(int Draw) {
  if (Draw)
  {
    display.clearDisplay();
  }
  else {
    battery_voltage_data[0] = analogRead(A2);
    battery_voltage_data[1] = analogRead(A2);
    battery_voltage_data[2] = analogRead(A2);
    battery_voltage_data[3] = analogRead(A2);
  }




  battery_bars = map(battery_level, 0, 100, 0, 28);

  display.drawBitmap(0, 0,  Background, 128, 64, WHITE);
  display.setCursor(23, 26);
  display.print(round(motor_temp));
  display.setCursor(12, 36);
  display.print(round(mc_temp));
  display.setCursor(47, 36);
  display.print((analogRead(A7) + analogRead(A6) - motor_amp_static) * 0.02 * battery_voltage);
  display.print("Watt");

  display.setCursor(2, 2);
  display.print(analogRead(A6));
  display.setCursor(2, 10);
  display.print(analogRead(A7));
  display.print(" ");
  display.print(battery_voltage_data[2]);
  for (int I = 0; I < battery_bars; I++) {
    display.fillRect(15 + I * 4, 46, 3, 16, WHITE);
  }

  display.setTextColor(BLACK);
  display.setCursor(47, 50);
  display.print(battery_voltage);
  display.print("V");
  display.setCursor(49, 50);
  display.print(battery_voltage);
  display.print("V");
  display.setCursor(48, 51);
  display.print(battery_voltage);
  display.print("V");
  display.setCursor(48, 49);
  display.print(battery_voltage);
  display.print("V");
  display.setTextColor(WHITE);
  display.setCursor(48, 50);
  display.print(battery_voltage);
  display.print("V");

  if (Draw)
  {
    display.display();
  }
}
