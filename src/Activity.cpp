#include "Activity.hpp"

#define __EMPTY_FUNCTION [](){}

Activity::Activity() noexcept
{
	this->create(__EMPTY_FUNCTION, __EMPTY_FUNCTION, __EMPTY_FUNCTION);
}
Activity::Activity(void (*onLoop)(), void (*onSetup)(), void (*onReset)()) noexcept
	: Activity()
{
  this->create(onLoop, onSetup, onReset);
}

void Activity::create(void (*onLoop)(), void (*onSetup)(), void (*onReset)()) noexcept
{
  	this->onLoop = onLoop;
  	this->onSetup = onSetup;
	this->onReset = onReset;
}

Activity::~Activity() noexcept
{
}
