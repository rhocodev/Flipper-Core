#include "Display.hpp"
#include <Wire.h>

Display::Display() noexcept
{
}

void Display::setup() noexcept
{
  this->__u8g = new DISPLAY_INSTANCE(U8G2_R0, U8X8_PIN_NONE);
	this->__u8g->begin();
  this->__u8g->setColorIndex(1);
  this->__u8g->setFont(FONT_INSTANCE);
}
void Display::draw(const Drawable &drawable) const noexcept
{
  drawable.__draw(this->__u8g);
}
void Display::firstPage() noexcept
{
  this->__u8g->firstPage();
}
const int Display::nextPage() noexcept
{
  return this->__u8g->nextPage();
}

Display::~Display() noexcept
{
  delete this->__u8g;
}
