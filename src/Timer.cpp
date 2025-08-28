#include "Timer.hpp"

Timer::Timer() noexcept
{
    this->__millis = millis();
}

void Timer::reset() noexcept
{
    this->__millis = millis();
}
const unsigned long Timer::getMillis() const noexcept
{
    return millis() - this->__millis;
}

Timer::~Timer() noexcept
{
}
