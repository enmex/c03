#include "RingedList.h"
RingedList::RingedList() : size(10), current_size(0), buf(size) {
	list = new int[size + 1];
}
RingedList::~RingedList(){
	clear();
	delete list;
	buf = 0;
	size = 0;
}
RingedList::RingedList(int size) : size(size), current_size(0), buf(size+1) {
	if(size <= 0){
		throw ListException(ExceptionType::WRONG_SIZE);
	}
	list = new int[size + 1];
}
RingedList::RingedList(const RingedList& list) : list(list.list), size(list.size), current_size(list.current_size), buf(list.buf){}

RingedList::RingedList(RingedList&& list) : list(list.list), size(list.size), current_size(list.current_size), buf(list.buf){
	list.buf = 0;
	list.list = nullptr;
	list.current_size = 0;
	list.size = 0;
}
void RingedList::push(iterator_list& it, int value){
	if(it.getPos() > buf){
		throw ListException(ExceptionType::ITERATOR_OUT_OF_RANGE);
	}
	list[it.getPos()] = value;
}
int RingedList::del(iterator_list& it){
	if(current_size == 0){
		throw ListException(ExceptionType::EMPTY_LIST);
	}
	if(it.getPos() > buf){
		throw ListException(ExceptionType::ITERATOR_OUT_OF_RANGE);
	}
	int temp = it.getValue();
	current_size--;
	return temp;
}
RingedList::iterator_list& RingedList::find(int value){
	iterator_list it(this);
	while(it.getValue() != value && !it.finish()){
		it.next();
	}
	return it;
}
void RingedList::clear(){
	delete list;
	list = new int[size+1];
	current_size = 0;
	buf = size;
}
bool RingedList::isEmpty(){
	return current_size == 0;
}
int RingedList::length(){
	return current_size;
}
RingedList::iterator_list& RingedList::getHead(){
	iterator_list it(this);
	return it;
}

RingedList::iterator_list::iterator_list(RingedList* list) : list(list), i(0) {}

void RingedList::iterator_list::start(){
	i = 0;
}
int RingedList::iterator_list::getValue(){
	return list->list[i];
}
void RingedList::iterator_list::next(){
	i = (i+1) % list->current_size; 
}
bool RingedList::iterator_list::finish(){
	return i = list->current_size;
}
int RingedList::iterator_list::getPos(){
	return i;
}