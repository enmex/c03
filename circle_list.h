#pragma once
#include "List.h"
#include "ListException.h"
#include "Iterator.h"
#include <iostream>

class circle_list : public List
{
public:
	/*
	создаем внутри класс итератор и наследуем от вирутального итератора
	*/
	class iterator_list : public Iterator {
		private:
			circle_list* circle;
		public:
			explicit iterator_list(circle_list*);//explicit означает чтобы у нас проинициализировалась только circle_list
			void start();
			list_* getValue();
			void next();
			bool finish();
		};
private:
	iterator_list* iter; //переменная итератора
	list_* list; //указатель на список
	list_* buf, *head; //указатель на буферный элемент, на головной элемент
	int size = 0; //
	int current = 0;
public:
	circle_list();
	~circle_list();
    circle_list(int size);
	circle_list(const circle_list&); //copy
	circle_list(circle_list&&); //move

	void push(int);
	int del();
	iterator_list* find(int);
	void clear();
	bool isEmpty();
	int length();
	iterator_list* getHead();

	iterator_list* begin();
};