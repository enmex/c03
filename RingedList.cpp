#include "RingedList.h"
template <typename T>
RingedList<T>::RingedList() : size(10), current_size(0), buf(size) {
	list = new T[size + 1];
}
template <typename T>
RingedList<T>::RingedList(int size) : size(size), current_size(0), buf(size+1) {
	list = new T[size + 1];
}
template <typename T>
RingedList<T>::RingedList(const RingedList& list) : list(list.list), size(list.size), current_size(list.current_size), buf(list.buf){}

template <typename T>
RingedList<T>::RingedList(RingedList&& list) : list(list.list), size(list.size), current_size(list.current_size), buf(list.buf){
	list.buf = 0;
	list.list = nullptr;
	list.current_size = 0;
	list.size = 0;
}

template <typename T>
void RingedList<T>::push(const iterator_list& it, T value){
	if(it.i > buf){
		//выбросить исключение
	}
	list[it.i] = value;
}
template <typename T>
T RingedList<T>::pop(iterator_list& it){
	if(current_size == 0){
		//выбросить исключение
	}
	T temp = it.getValue();
	current_size--;
	return temp;
}

template <typename T>
typename RingedList<T>::iterator_list& RingedList<T>::find(T value){
	iterator_list it(this);
	while(it.getValue() != value && !it.finish()){
		it.next();
	}
	return it;
}
template <typename T>
void RingedList<T>::clear(){
	delete list;
	list = new T[size+1];
	current_size = 0;
	buf = size;
}
template <typename T>
bool RingedList<T>::isEmpty(){
	return current_size == 0;
}
template <typename T>
int RingedList<T>::length(){
	return current_size;
}
template <typename T>
typename RingedList<T>::iterator_list& RingedList<T>::getHead(){
	return new iterator_list(this);
}

template <typename T>
RingedList<T>::iterator_list::iterator_list(RingedList<T>& list) : list(list), i(0) {}

template <typename T>
void RingedList<T>::iterator_list::start(){
	i = 0;
}
template <typename T>
T RingedList<T>::iterator_list::getValue(){
	return list[i];
}
template <typename T>
void RingedList<T>::iterator_list::next(){
	i = (i+1) % list->current_size; 
}
template <typename T>
bool RingedList<T>::iterator_list::finish(){
	return i = list->current_size;
}