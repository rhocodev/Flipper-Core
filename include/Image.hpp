#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "Drawable.hpp"
#include "Transformable.hpp"

class Image : public Drawable, public Transformable
{
public:
	Image(const uint8_t *const) noexcept;

	virtual void setWidth(const uint8_t) noexcept;
	virtual void setHeight(const uint8_t) noexcept;
	const uint8_t &getWidth() const noexcept;
	const uint8_t &getHeight() const noexcept;

	virtual ~Image() noexcept;
private:
	const uint8_t *__data;
	uint8_t __width, __height;


  void __draw(const DISPLAY_INSTANCE *const) const noexcept override;
};

#endif
