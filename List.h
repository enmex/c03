#pragma once
#include "Iterator.h"
template <class T>
class List {
public:
	virtual void push(const Iterator&, T)=0;
	virtual T pop(Iterator&)=0;
	virtual Iterator& find(T)=0;
	virtual void clear()=0;
	virtual bool isEmpty()=0;
	virtual int length()=0;
	virtual Iterator& getHead()=0;
};