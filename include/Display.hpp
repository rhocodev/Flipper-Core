#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "Drawable.hpp"
#include "Config.hpp"

class Display
{
  public:
    Display() noexcept;

    void setup() noexcept;
    void draw(const Drawable&) const noexcept;
    void firstPage() noexcept;
    const int nextPage() noexcept;

    ~Display() noexcept;
  private:
    DISPLAY_INSTANCE *__u8g;
};

#endif
