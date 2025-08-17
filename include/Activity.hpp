#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP

class Activity final
{
public:
	Activity() noexcept;
	Activity(void (*onLoop)(), void (*onSetup)(), void (*onReset)() = []()->void{}) noexcept;

	void create(void (*onLoop)(), void (*onSetup)() = []()->void{}, void (*onReset)() = []()->void{}) noexcept;

	~Activity() noexcept;

	void (*onLoop)();
	void (*onSetup)();
	void (*onReset)();
};

#endif
