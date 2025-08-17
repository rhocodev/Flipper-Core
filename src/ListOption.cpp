#include "ListOption.hpp"

ListOption::ListOption() noexcept
	: __size { 0 }, __head { nullptr }, __tail { nullptr }
{
}

void ListOption::push(const Option option) noexcept
{
	ListOptionNode *node = new ListOptionNode();

	node->option = option;
	node->next = nullptr;

	if(!this->__head)
	{
		this->__head = node;
		this->__tail = node;
	}
	else
	{
		this->__tail->next = node;
		this->__tail = node;
	}

	this->__size++;
}
const uint8_t &ListOption::getSize() const noexcept
{
	return this->__size;
}
const Option *ListOption::at(const uint8_t key) const noexcept
{
	ListOptionNode *current = this->__head;
	uint8_t i = 0;

	while(current)
	{
		if(i == key)
			return &current->option;

		current = current->next;
		i++;
	}

	return nullptr;
}
void ListOption::flush() noexcept
{
	while(this->__head)
	{
		ListOptionNode *tmp = this->__head->next;
		delete this->__head;
		this->__head = tmp;
	}
	this->__head = nullptr;
	this->__tail = nullptr;
	this->__size = 0;
}

ListOption::~ListOption() noexcept
{
	this->flush();
}
