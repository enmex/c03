#pragma once
#include "Iterator.h"
class List{
public:
	virtual void push(int)=0;
	virtual int del()=0;
	virtual Iterator* find(int)=0;
	virtual void clear()=0;
	virtual bool isEmpty()=0;
	virtual int length()=0;
	virtual Iterator* getHead()=0;
};