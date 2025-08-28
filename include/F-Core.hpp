#ifndef F_CORE_HPP
#define F_CORE_HPP

#include "Display.hpp"
#include "Activity.hpp"
#include "Text.hpp"
#include "ListOption.hpp"
#include "Button.hpp"
#include "MenuSystem.hpp"
#include "Icon.hpp"
#include "Image.hpp"
#include "Timer.hpp"

#define FN_SWITCH(page) []() { switchPage(page); }

Display display;
Activity
  *current_activity = nullptr,
  *pending_activity = nullptr;

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

#endif