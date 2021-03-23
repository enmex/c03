#pragma once
#include "List.h"
#include "Iterator.h"
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
			node<T>* pointer_;
			node<T>* head_;
		public:
			iterator_list() : pointer_(nullptr), head_(nullptr){}
			iterator_list(const RingedList& a) : pointer_(a.list_), head_(a.head_) {}
			iterator_list(node<T>* head_) : head_(head_) {}
			void start() override { pointer_ = head_;}
			T getValue() override { return pointer_->value; }
			void next() override{pointer_ = pointer_->next;}
			bool finish() override {return pointer_->next == nullptr;}
		};


	inline RingedList() : buf_(nullptr), head_(nullptr), list_(nullptr) {}
	RingedList(const RingedList&);
	RingedList(RingedList&&);
	inline void init() {
		buf_->next = buf_->prev = head_;
		head_ -> next = head_->prev = buf_;
		head_->value = 0;
		list_ = head_;
	}
	inline void push(Iterator& it, T value) override {
		iterator_list itr;
		itr = dynamic_cast<iterator_list&>(it);
		list_->next->value = value;
		list_ = list_->next;
		buf_ = buf_->next;
		buf_->prev = list_;
		buf_->next = head_;
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
		iterator_list it(head_);
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