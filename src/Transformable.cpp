#include "Transformable.hpp"

Transformable::Transformable() noexcept
{
	this->setX(0);
	this->setY(0);
}

void Transformable::setX(const uint8_t x) noexcept
{
	this->__x = x;
}
void Transformable::setY(const uint8_t y) noexcept
{
	this->__y = y;
}
const uint8_t &Transformable::getX() const noexcept
{
	return this->__x;
}
const uint8_t &Transformable::getY() const noexcept
{
	return this->__y;
}

Transformable::~Transformable() noexcept
{
}
