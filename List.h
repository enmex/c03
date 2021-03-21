#pragma once
#include "Iterator.h"
class List {
private:
    int size;
public:
	virtual void push(Iterator, int);
	virtual int pop(Iterator);
	virtual Iterator find(int);
	virtual void clear();
	virtual bool isEmpty();
	virtual int length();
	virtual Iterator getHead();
};