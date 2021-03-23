#pragma once
#include "Iterator.h"
template <class T>
class List {
public:
	virtual void push(Iterator&, T);
	virtual T pop(Iterator&);
	virtual Iterator& find(T);
	virtual void clear();
	virtual bool isEmpty();
	virtual int length();
	virtual Iterator& getHead();
};