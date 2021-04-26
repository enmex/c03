#include "circle_list.h"
circle_list::circle_list() : size(10), current(0), buf(new list_), list(new list_){
	buf->next = buf;
	buf->prev = buf;
	list = buf;
}
circle_list::~circle_list(){
	clear();
	list = nullptr;
	buf->value = 0;
	buf->next = buf;
	buf->prev = buf;
	delete list;
	size = 0;
	current = 0;
}
circle_list::circle_list(int size) : size(size), current(0), buf(new list_), list(new list_), head(nullptr) { //создается список размера size, все элементы в котором равны 0
	if(size <= 0){
		throw ListException(ExceptionType::WRONG_SIZE);
	}
	buf->next = buf;
	buf->prev = buf;
	list = buf;
}

circle_list::circle_list(const circle_list& list) : list(list.list), size(list.size), buf(list.buf), current(list.current), iter(list.iter), head(list.head) {}

circle_list::circle_list(circle_list&& list) : list(list.list), size(list.size), buf(list.buf), iter(list.iter), current(list.current), head(list.head){
	list.head = nullptr;
	list.list = nullptr;
	list.buf = nullptr;
	delete list.list, list.buf, list.head;
	list.size = 0;
	list.current = 0;
}
void circle_list::push(int value){
	if(current == size){
		throw ListException(ExceptionType::FULL_LIST);
	}
	list_* temp = new list_;
	temp->value = value;
	temp->next = list;
	temp->prev = buf;
	list->prev = temp;
	list = temp;
	buf->next = list;
	head = list;
	temp = nullptr;
	delete temp;
}
int circle_list::del(){
	if(current == 0){
		throw ListException(ExceptionType::EMPTY_LIST);
	}
	int x = iter->getValue()->value;
	list = iter->getValue();
	list_* prev = iter->getValue()->prev;
	list_* next  =iter->getValue()->next;
	if(prev) {prev->next = list->next;}
	if(next) { next->prev = list->prev;}
	free(list);
	current--;
	return x;
}
circle_list::iterator_list* circle_list::find(int value){
	iter->start();
	while(iter->getValue()->value != value && !iter->finish()){
		iter->next();
	}
	return iter;
}
void circle_list::clear(){
	while(list!=buf){
		list = list->next;
		free(list->prev);
	}
	free(buf);
}
bool circle_list::isEmpty(){
	return current == 0;
}
int circle_list::length(){
	return current;
}
circle_list::iterator_list* circle_list::getHead(){
	iter->start();
	return iter;
}

circle_list::iterator_list::iterator_list(circle_list* circle) : circle(circle) {}

void circle_list::iterator_list::start(){
	circle->list = circle->head;
}
list_* circle_list::iterator_list::getValue(){
	return circle->list;
}
void circle_list::iterator_list::next(){
	circle->list = circle->list->next;
}
bool circle_list::iterator_list::finish(){
	return circle->list == circle->buf;
}
circle_list::iterator_list* circle_list::begin(){
	iter = new iterator_list(this);
	iter->start();
	return iter;
}