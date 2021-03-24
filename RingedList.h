#pragma once
#include "List.h"
#include "Iterator.h"
#include <iostream>
template <typename T>
struct node {
	T value;
	node* next, * prev;
};
template <typename T>
class RingedList : public List<T>
{
private:
	node<T>* list_;
	node<T>* head_;
	node<T>* buf_;
	int size = 0;
public:

	class iterator_list : public Iterator {
		private:
			node<T>* list_;
			int i;
			int size;
		public:
			iterator_list() : i(0), size(0) {}
			iterator_list(const RingedList& a) : i(0), size(a.size), list_(a.list_) {}
			void init(node<T>* list_) {this->list_ = list_;}
			void start() override {
				 i = 0;}
			T getValue() override { return list_->value; }
			void next() override{
				list_ = list_->next;
				}
			bool finish() override {return list_->next == nullptr;}
		};


	inline RingedList() : buf_(nullptr), head_(nullptr), list_(nullptr) {}
	RingedList(const RingedList&);
	RingedList(RingedList&&);
	inline void init() {
		list_ = new node<T>;
		head_ = list_;
		head_->value = 0;
		buf_ = new node<T>;
		buf_->next = head_;
		buf_->prev = head_;
		head_ -> next = buf_;
		head_->prev = buf_;
	}
	inline void push(const Iterator& it, T value) override {
		/*
		Node* temp = new Node;
		temp = list;
		temp->x = y;
		temp->next=list->next;
		list=temp;
		*/
		size++;
		node<T>* temp = reinterpret_cast<iterator_list>(it).pointer_;
		temp->value = value;
		temp->next_ = buf_;
		buf_->prev = temp;
		temp->prev = list_;
		list_ = temp;
		delete temp;
		reinterpret_cast<iterator_list>(it).init(list_);
	};
	inline T pop(Iterator& it) override {
		size--;
		node<T>* temp = list_->prev;
		buf_ = list_;
		buf_->value = 0;
		T value = it.getValue();
		delete list_;
		list_ = temp;
		return value;
	};
	inline iterator_list& find(T value) override {
		iterator_list it;
		it.start();
		while(it.getValue()!=value || !it.finish()){
			it.next();
		}
		return it;
	}
	inline void clear() override {
		delete list_;
		delete head_;
		delete buf_;
		init();
	}
	inline bool isEmpty() override {
		return size == 0;
	};
    inline iterator_list& getHead() override {
		it.start();
		return it;
	};
    inline int length() override {
		return size;
	};
	RingedList<T>& operator=(RingedList<T>&& a){
		buf_ = a.buf_;
		head_ = a.head_;
		list_ = a.list_;
		delete a.buf_;
		delete a.head_;
		delete a.list_;
		return *this;
	}
	RingedList<T>& operator=(const RingedList<T>& a){
		if(this == &a){
			return *this;
		}
		buf_ = a.buf_;
		head_ = a.head_;
		list_ = a.list_;
		return *this;
	}
};