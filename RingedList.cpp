#include "RingedList.h"
template <typename T>
RingedList<T>::RingedList(const RingedList& a) : list_(a.list_), buf_(a.buf_), head_(a.head_) {}
template <typename T>
RingedList<T>::RingedList(RingedList&& a) : list_(a.list_), buf_(a.buf_), head_(a.head_){
	a.list_ = nullptr;
	a.buf_ = nullptr;
	a.head_ = nullptr;
}