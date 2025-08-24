#include "F-Core.hpp"

#define FN_SWITCH(page) []() { switchPage(page); }

Display display;
Activity
  *current_activity = nullptr,
  *pending_activity = nullptr;

namespace Menu
{
  MenuSystem home, tools;
};

namespace Control
{
  Button down(2), enter(4), up(8);
};

namespace Page
{
  Activity home, tools;
};

void moveCursorWithButtons(MenuSystem &menu)
{ 
  if(Control::enter.isPressed()) menu.click();
  if(Control::down.isPressed()) menu.moveCursor(1);
  if(Control::up.isPressed()) menu.moveCursor(-1);
}

void switchPage(Activity &page)
{
  pending_activity = &page;
}

void processPendingSwitch()
{
  if (!pending_activity) return;
  if (current_activity != nullptr) current_activity->onReset();

  current_activity = pending_activity;
  pending_activity = nullptr;

  if (current_activity != nullptr) current_activity->onSetup();
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
  create_pages();
  boot_system();
}

void loop()
{
  processPendingSwitch();
  if(current_activity)
    current_activity->onLoop();
}
