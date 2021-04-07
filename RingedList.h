#pragma once
#include "List.h"
#include "ListException.h"
#include "Iterator.h"
#include <iostream>
class RingedList : public List
{
private:
	int* list = nullptr;
	int buf;
	int size = 0;
	int current_size = 0;
public:
	class iterator_list : public Iterator {
		private:
			int i;
			RingedList* list = nullptr;
		public:
			explicit iterator_list(RingedList*);
			void start();
			int getValue();
			void next();
			bool finish();
			int getPos();
		};
	RingedList();
	~RingedList();
    RingedList(int size);
	RingedList(const RingedList&); //copy
	RingedList(RingedList&&); //move

	void push(Iterator&, int);
	int del(Iterator&);
	iterator_list& find(int);
	void clear();
	bool isEmpty();
	int length();
	iterator_list& getHead();
};