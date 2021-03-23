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

	class iterator_list : virtual public Iterator<T> {
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


	RingedList();
	RingedList(const RingedList&);
	RingedList(RingedList&&);
	void init();
	inline void push(Iterator<T>& it, T value) override {
		iterator_list itr;
		itr = dynamic_cast<iterator_list&>(it);
		list_->next->value = value;
		list_ = list_->next;
		buf_ = buf_->next;
		buf_->prev = list_;
		buf_->next = head_;
	};
	inline T pop(Iterator<T> it) override {
		size--;
		iterator_list itr;
		itr = dynamic_cast<iterator_list&>(it);
		
	};
	inline Iterator<T> find(T value) override {
		iterator_list it;
		it.start();
		while(it.getValue()!=value || !it.finish()){
			it.next();
		}
		if(it.getValue() != value){
			return iterator_list();
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
    inline Iterator<T> getHead() override {
		iterator_list it(head_);
		it.start();
		return it;
	};
    inline int length() override {
		return size;
	};
	RingedList<T> operator=(RingedList<T>&& a){
		buf_ = a.buf_;
		head_ = a.head_;
		list_ = a.list_;
		delete a.buf_;
		delete a.head_;
		delete a.list_;
	}
	RingedList<T> operator=(const RingedList<T>& a){
		buf_ = a.buf_;
		head_ = a.head_;
		list_ = a.list_;
	}
};