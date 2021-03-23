#pragma once
class Iterator
{
public:
	virtual void start();
	virtual int getValue();
	virtual void next();
	virtual bool finish();
};

