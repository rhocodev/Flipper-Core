#include "F-Core.hpp"

Timer button_timer;

namespace Menu
{
  MenuSystem
    home, tools;
};

namespace Control
{
  Button
    down(2), enter(4), up(8);
};

namespace Page
{
  Activity
    home, tools;
};

void moveCursorWithButtons(MenuSystem &menu)
{ 
  if(Control::enter.isPressed() && button_timer.getMillis() > 250)
  {
    menu.click();
    button_timer.reset();
  }

  if(Control::down.isPressed()) menu.moveCursor(1);
  if(Control::up.isPressed()) menu.moveCursor(-1);
}

void boot_system()
{
  display.setup();
  Control::down.setup();
  Control::up.setup();
  Control::enter.setup();
}

void create_pages()
{
  Page::home.onLoop = []() {
    moveCursorWithButtons(Menu::home);
    display.firstPage(); do
    {
      display.draw(Menu::home);
    } while(display.nextPage());
  };
  Page::home.onSetup = []() {
    Menu::home.addOption(Option("Tools", Icon::TOOLS, FN_SWITCH(Page::tools)));
    Menu::home.addOption(Option("Upgrade", Icon::UPGRADE));
  };
  Page::home.onReset = []() {
    Menu::home.flush();
  };

  Page::tools.onLoop = []() {
    moveCursorWithButtons(Menu::tools);
    display.firstPage(); do
    {
      display.draw(Menu::tools);
    } while(display.nextPage());
  };
  Page::tools.onSetup = []() {
    Menu::tools.addOption(Option("d-auther", Icon::SCRIPT));
    Menu::tools.addOption(Option("wifi-spam", Icon::SCRIPT));
    Menu::tools.addOption(Option("bjammer", Icon::SCRIPT));
    Menu::tools.addOption(Option("FR-copy", Icon::SCRIPT));
    Menu::tools.addOption(Option("wifi-fake", Icon::SCRIPT));
    Menu::tools.addOption(Option("scan wifi", Icon::SCRIPT));
    Menu::tools.addOption(Option("bad-usb", Icon::SCRIPT));
    Menu::tools.addOption(Option("Exit", Icon::EXIT, FN_SWITCH(Page::home)));
  };
  Page::tools.onReset = []() {
    Menu::tools.flush();
  };

  switchPage(Page::home);
}

void setup()
{
  boot_system();
  create_pages();
}

void loop()
{
  processPendingSwitch();
  if(current_activity)
    current_activity->onLoop();
}
