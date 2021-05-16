#pragma once
struct list_{
	int value;
	list_* next, *prev;
};
class Iterator
{
public:
	virtual void start()=0;
	virtual list_* getValue()=0;
	virtual void next()=0;
	virtual bool finish()=0;
};

/*
виртуальный класс для итератора
*/