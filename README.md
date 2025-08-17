# Flipper Core - Firmware 0x00A

Recomendo fazer o upload para o Arduino usando Linux, pois só testei nele. No entanto, se você tem experiência com Windows fazendo o upload desta base de código via arduino-cli (ou Arduino IDE*), envie uma PR mostrando os passos.

## Instalando
Instalar a biblioteca `U8g2lib` com:
```bash
$ arduino-cli lib install U8g2
```

Instalar a biblioteca `arduino:avr` com:
```bash
$ arduino-cli core install arduino:avr
```

## Upload code to arduino
Usar `root` com `sudo -E` para envio preguiçoso. (somente para o arduino por enquanto)
```bash
$ sudo -E make
```

## AVISO - Porte para ESP-32
É totalmente possível usar esse código no ESP-32, mas como eu não tenho um ESP-32 ainda, você vai ter que saber adaptar editando o `Makefile`. Nesse momento só há o envio para o `arduino:avr`, então efetue a devida edição juntamente com a porta do seu ESP-32 e envie.

# Como usar a Flipper Core
A flipper core é basicamente um sistema de menus com um sistema de páginas com um sistema de gerenciamento de memória e array dinâmico.

Então, a partir desse projeto é possível adaptar para seus interesses, como por exemplos ferramentas de pentest legais ou talves um menu com sistema para gerenciar sua casa (ativar luzes).

## Activity - Páginas
Eu recomendo, para boas práticas no gerenciamento de memória, você sempre dar um `menu.flush()` na `onReset` da sua Activity, assim vai liberar mais memória para os próximos menus, e sempre configure as `Option` do `MenuSystem` no `onSetup` (mas apenas os `addOption`) se possível.

# Exemplo - Criando um menu e uma páginas `tools` (ferramentas).
```c++
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
    Menu::home.flush(); // sempre liberar memoria que é configurada no setup da page
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
    Menu::tools.flush(); // sempre liberar memoria que é configurada no setup da page
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
```

## screenshots
![](screenshots/makethel.jpeg)
