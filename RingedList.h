#pragma once
#include "List.h"
struct node {
	int value;
	node* next, * prev;
};
class RingedList : public List
{
private:
	node* list_;
	node* head_;
	node* buf_;
	int size = 0;
	class iterator_list final : public Iterator {
	private:
		node* pointer_;
	public:

		iterator_list() : pointer_(nullptr){}
		void start() override { pointer_ = reinterpret_cast<RingedList*>(this)->head_; }
		int getValue() override { return pointer_->value; }
		void next() override
		{
			pointer_ = reinterpret_cast<RingedList*>(this)->list_->next;
			reinterpret_cast<RingedList*>(this)->list_ = reinterpret_cast<RingedList*>(this)->list_->next;
		}
		bool finish() override { return reinterpret_cast<RingedList*>(this)->list_->next == reinterpret_cast<RingedList*>(this)->buf_; }
		node* getPointer() const;
	};
public:
	RingedList();
	RingedList(const RingedList&);
	RingedList(RingedList&&);
	void push(Iterator, int) override;
	int pop(Iterator) override;
	Iterator find(int) override;
	void clear() override;
	bool isEmpty() override;
    Iterator getHead() override;
    int length() override();
	RingedList operator=(RingedList&&);
	RingedList operator=(const RingedList&);

};

