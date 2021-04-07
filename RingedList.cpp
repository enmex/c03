#include "RingedList.h"
RingedList::RingedList() : size(10), current_size(0), buf(10) {
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
void RingedList::push(Iterator& it, int value){
	iterator_list* iter = dynamic_cast<iterator_list*>(&it);
	if(iter->getPos() > buf){
		throw ListException(ExceptionType::ITERATOR_OUT_OF_RANGE);
	}
	if(iter->getPos()!=buf){
		current_size++;
	}
	list[iter->getPos()] = value;
}
int RingedList::del(Iterator& it){
	iterator_list* iter = dynamic_cast<iterator_list*>(&it);
	if(current_size == 0){
		throw ListException(ExceptionType::EMPTY_LIST);
	}
	if(iter->getPos() > buf){
		throw ListException(ExceptionType::ITERATOR_OUT_OF_RANGE);
	}
	int temp = iter->getValue();
	current_size--;
	int k = 0;
	int* tempList = new int[current_size];
	for(int i = 0; i < current_size+1; i++){
		if(i!=iter->getPos()){
			tempList[k] = list[i];
			k++;
		}
	}
	list = tempList;
	return temp;
}
RingedList::iterator_list& RingedList::find(int value){
	iterator_list *it = new iterator_list(this);
	it->start();
	while(it->getValue() != value && !it->finish()){
		it->next();
	}
	return *it;
}
void RingedList::clear(){
	delete list;
	list = new int[size+1];
	buf = size;
}
bool RingedList::isEmpty(){
	return current_size == 0;
}
int RingedList::length(){
	return current_size;
}
RingedList::iterator_list& RingedList::getHead(){
	iterator_list* it = new iterator_list(this);
	return *it;
}

RingedList::iterator_list::iterator_list(RingedList* list) : list(list), i(0) {}

void RingedList::iterator_list::start(){
	i = 0;
}
int RingedList::iterator_list::getValue(){
	return list->list[i];
}
void RingedList::iterator_list::next(){
	i = (i+1) % list->size; 
}
bool RingedList::iterator_list::finish(){
	return i == list->current_size-1;
}
int RingedList::iterator_list::getPos(){
	return i;
}