#pragma once
#include "List.h"
#include "Iterator.h"
#include <iostream>
class RingedList : public List
{
private:
	int* list = nullptr;
	int buf;
	int size = 0;
	int current_size =0;
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
		};
	inline RingedList();
	inline ~RingedList();
    RingedList(int size);
	RingedList(const RingedList&); //copy
	RingedList(RingedList&&); //move

	void push(const iterator_list&, int);
	int del(iterator_list&);
	iterator_list& find(int);
	void clear();
	bool isEmpty();
	int length();
	iterator_list& getHead();
};