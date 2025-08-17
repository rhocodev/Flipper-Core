#ifndef LISTOPTION_HPP
#define LISTOPTION_HPP

#include "Option.hpp"

typedef struct __ListOptionNode
{
	Option option;
	__ListOptionNode *next;
} ListOptionNode;

class ListOption
{
public:
	ListOption() noexcept;

	virtual void push(const Option) noexcept;
	const uint8_t &getSize() const noexcept;
	const Option *at(const uint8_t) const noexcept;
	virtual void flush() noexcept;

	virtual ~ListOption() noexcept;
private:
	uint8_t __size;
	ListOptionNode *__head, *__tail;
};

#endif
