#pragma once
#include "Iterator.h"
template <typename T>
class List {
public:
	virtual void push(const Iterator<T>&, T)=0;
	virtual T pop(Iterator<T>&)=0;
	virtual Iterator<T>& find(T)=0;
	virtual void clear()=0;
	virtual bool isEmpty()=0;
	virtual int length()=0;
	virtual Iterator<T>& getHead()=0;
};