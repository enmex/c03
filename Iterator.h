#pragma once
class Iterator
{
private:
	int i = 0;
public:
	virtual ~Iterator() = default;
	virtual void start() {}
	virtual int getValue();
	virtual void next() {}
	virtual bool finish();
};

