#include "RingedList.h"
template <typename T> 
RingedList<T>::RingedList() : buf_(nullptr), head_(nullptr), list_(nullptr) {}
template <typename T>
RingedList<T>::RingedList(const RingedList& a) : list_(a.list_), buf_(a.buf_), head_(a.head_) {}
template <typename T>
RingedList<T>::RingedList(RingedList&& a) : list_(a.list_), buf_(a.buf_), head_(a.head_){
	a.list_ = nullptr;
	a.buf_ = nullptr;
	a.head_ = nullptr;
}
template <typename T>
void RingedList<T>::init(){
	buf_->next = buf_->prev = head_;
	head_ -> next = head_->prev = buf_;
	head_->value = 0;
	list_ = head_;
}