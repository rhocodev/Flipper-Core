#ifndef MENUSYSTEM_HPP
#define MENUSYSTEM_HPP

#include "ListOption.hpp"
#include "Display.hpp"
#include "Config.hpp"

class MenuSystem : public Drawable
{
public:
  MenuSystem() noexcept;

  void addOption(Option) noexcept;
  void setCursor(uint8_t) noexcept;
  void moveCursor(int) noexcept;
  void click() noexcept;
  void flush() noexcept;

  ~MenuSystem() noexcept;
private:
  void __draw(DISPLAY_INSTANCE*) const noexcept;

  ListOption __options;
  uint8_t __cursor_index;
};

#endif
