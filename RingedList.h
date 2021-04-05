#pragma once
#include "List.h"
#include "Iterator.h"
#include <iostream>
template <typename T>
class RingedList : public List<T>
{
private:
	T* list = nullptr;
	int buf;
	int size = 0;
	int current_size =0;
public:
	class iterator_list : public Iterator<T> {
		private:
			int i;
			RingedList<T>* list = nullptr;
		public:
			explicit iterator_list(RingedList<T>&);
			void start();
			T getValue();
			void next();
			bool finish();
		};
	RingedList(); //default size = 10
	RingedList(int size);
	RingedList(const RingedList&); //copy
	RingedList(RingedList&&); //move
	void push(const iterator_list&, T);
	T pop(iterator_list&);
	iterator_list& find(T);
	void clear();
	bool isEmpty();
	int length();
	iterator_list& getHead();
};