#ifndef OPTION_HPP
#define OPTION_HPP

#include <Arduino.h>
#include "Drawable.hpp"
#include "Transformable.hpp"

class Option : public Drawable, public Transformable
{
public:
	Option(const String = "<label>", const uint8_t* = NULL) noexcept;
	Option(const String, const uint8_t*, void (*onClick)()) noexcept;

	void setLabel(const String) noexcept;
	const String &getLabel() const noexcept;
	void setIcon(const uint8_t*) noexcept;
	const uint8_t *getIcon() const noexcept;
	void (*onClick)();

	friend class MenuSystem;

	~Option() noexcept;
private:
	String __label;
	uint8_t *__icon, __x, __y;

  void __draw(const DISPLAY_INSTANCE *const) const noexcept override;
};

#endif
