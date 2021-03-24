#pragma once
class Iterator
{
public:
	virtual void start()=0;
	virtual int getValue()=0;
	virtual void next()=0;
	virtual bool finish()=0;
};

