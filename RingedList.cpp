#include "RingedList.h"

node* RingedList::iterator_list::getPointer() const
{
	return pointer_;
}

RingedList::RingedList(): head_(nullptr), buf_(nullptr)
{
	buf_->next = head_;
	buf_->prev = head_;
	head_->next = buf_;
	head_->prev = buf_;
	head_->value = 0;
	list_ = head_;
}

RingedList::RingedList(const RingedList& a) : list_(a.list_), head_(a.head_), buf_(a.buf_) {}

RingedList::RingedList(RingedList&& a) : list_(a.list_), head_(a.head_), buf_(a.buf_) {
	a.list_ = nullptr;
	a.buf_ = nullptr;
	a.head_ = nullptr;
}

void RingedList::push(Iterator it, const int value)
{
    size++;
	list_->next->value = value;
	list_ = list_->next;
}

void RingedList::clear()
{
    size = 0;
    list_ = head_;
    head_->value = 0;
	buf_ = nullptr;
}

bool RingedList::isEmpty()
{
	return list_->next == buf_;
}

RingedList RingedList::operator=(RingedList&& a)
{
    list_=a.list_;
    head_=a.head_;
    buf_=a.buf_;
	a.head_ = nullptr;
	a.buf_ = nullptr;
	a.list_ = nullptr;
	return *this;
}

int RingedList::pop(Iterator) {
    size--;
    int value = list_->value;
    node* temp = list_->prev;
    delete list_;
    list_ = temp;
    return value;
}

Iterator RingedList::find(int) {

}

int RingedList::length() {
    return size;
}

