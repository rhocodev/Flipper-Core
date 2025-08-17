#include "MenuSystem.hpp"

#include "Text.hpp"

MenuSystem::MenuSystem() noexcept
  : __cursor_index {0}
{
}

void MenuSystem::addOption(Option option) noexcept
{
  this->__options.push(option);
}
void MenuSystem::setCursor(uint8_t y) noexcept
{
	this->__cursor_index = y;
}
void MenuSystem::moveCursor(int direction) noexcept
{
	int total = this->__options.getSize();
  int new_index = this->__cursor_index + direction;

  if (new_index < 0)
    new_index = 0;
  if (new_index >= total)
		new_index = total - 1;

  this->__cursor_index = new_index;
}
void MenuSystem::click() noexcept
{
  if(this->__cursor_index >= this->__options.getSize()) return;
  Option *option = this->__options.at(this->__cursor_index);
  if(option)
    option->onClick();
}
void MenuSystem::flush() noexcept
{
  this->__options.flush();
  this->__cursor_index = 0;
}

MenuSystem::~MenuSystem() noexcept
{
}

void MenuSystem::__draw(const DISPLAY_INSTANCE *U8G) const noexcept
{
	const int total = this->__options.getSize();
  if(total == 0) return;

  const int max_visible = MAX_OPTIONS_BY_PAGE;

  int start_index = this->__cursor_index - max_visible / 2;

  if (start_index < 0)
    start_index = 0;
  if (start_index > total - max_visible)
    start_index = max(0, total - max_visible);

  int cursor_screen_y = this->__cursor_index - start_index;

  U8G->drawStr(0, FONT_HEIGHT * (cursor_screen_y + 1) + MENU_MARGIN_TOP, ">");

  for (int i = 0; i < max_visible; ++i)
  {
    int option_index = start_index + i;
    if (option_index >= total)
      break;

		this->__options.at(option_index)->setY(FONT_HEIGHT * (i + 1) + MENU_MARGIN_TOP);
    this->__options.at(option_index)->setX(TEXT_MARGIN_LEFT);
    this->__options.at(option_index)->__draw(U8G);
  }
}
