#pragma once
template <typename T> class Iterator
{
public:
	virtual void start() = 0;
	virtual T getValue() = 0;
	virtual void next() = 0;
	virtual bool finish() = 0;
};

