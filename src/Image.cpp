#include "Image.hpp"

Image::Image(const uint8_t *const data) noexcept
{
	this->__data = data;
	this->setX(0);
	this->setY(0);
}


void Image::setWidth(const uint8_t width) noexcept
{
	this->__width = width;
}
void Image::setHeight(const uint8_t height) noexcept
{
	this->__height = height;
}
const uint8_t &Image::getWidth() const noexcept
{
	return this->__width;
}
const uint8_t &Image::getHeight() const noexcept
{
	return this->__height;
}

Image::~Image() noexcept
{
}

void Image::__draw(const DISPLAY_INSTANCE *const U8G) const noexcept
{
	// TODO - Deixar o tamanho variável
	U8G->drawXBMP(this->getX(), this->getY(), 10, 10, this->__data);
}
