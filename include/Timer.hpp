#ifndef TIMER_HPP
#define TIMER_HPP

#include <Arduino.h>

class Timer
{
public:
    Timer() noexcept;

    virtual void reset() noexcept;
    const unsigned long getMillis() const noexcept;

    virtual ~Timer() noexcept;
private:
    unsigned long __millis; 
};

#endif