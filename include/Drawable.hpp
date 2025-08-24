#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <U8g2lib.h>
#include "Config.hpp"

class Drawable
{
public:
  virtual ~Drawable() noexcept = default;

  friend class Display;
private:
  virtual void __draw(DISPLAY_INSTANCE *) const noexcept = 0;
};

#endif
