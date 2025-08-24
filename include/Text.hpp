#ifndef TEXT_HPP
#define TEXT_HPP

#include "Config.hpp"
#include "Drawable.hpp"
#include "Transformable.hpp"

class Text : public Drawable, public Transformable
{
public:
  Text(const String, const uint8_t, const uint8_t) noexcept;

  ~Text() noexcept;
private:
  String __text;

  void __draw(DISPLAY_INSTANCE *) const noexcept;
};

#endif
