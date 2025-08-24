#include "Text.hpp"

Text::Text(const String text, const uint8_t x, const uint8_t y) noexcept
  : __text {text}
{
  this->setX(x);
  this->setY(y);
}

void Text::__draw(DISPLAY_INSTANCE *u8g) const noexcept
{
  u8g->drawStr(this->getX(), this->getY(), this->__text.c_str());	
}

Text::~Text()
{
}
