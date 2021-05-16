#pragma once
#include "Iterator.h"
/*
это виртуальный класс списка
тут перечислены основные методы виртуальные которые мы потом реализуем в классе
*/
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