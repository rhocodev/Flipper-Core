#include "Option.hpp"

Option::Option(const String label, uint8_t *icon) noexcept
{
	this->setLabel(label);
	this->setIcon(icon);
	this->setX(0);
	this->setY(0);
	this->onClick = [](){};
}
Option::Option(const String label, uint8_t *icon, void (*onClick)()) noexcept
	: Option(label, icon)
{
	this->onClick = onClick;
}

void Option::setLabel(const String label) noexcept
{
	this->__label = label;
}
const String &Option::getLabel() const noexcept
{
	return this->__label;
}
void Option::setIcon(uint8_t *icon) noexcept
{
	this->__icon = icon;
}
const uint8_t *Option::getIcon() const noexcept
{
	return this->__icon;
}

Option::~Option()
{
}

void Option::__draw(DISPLAY_INSTANCE *u8g) const noexcept
{
  u8g->drawStr(this->getX() + ICON_PADDING, this->getY(), this->__label.c_str());	
	u8g->drawXBMP(this->getX(), this->getY() - ICON_PADDING_BOTTOM, ICON_SIZE, ICON_SIZE, this->__icon);
}
