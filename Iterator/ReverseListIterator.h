#pragma once
#include "Iterator.h"
#include "List.h"

template<class Item>
class ReverseListIterator
	:public Iterator<Item>
{
public:
	ReverseListIterator(List<Item>* aList);
	virtual ~ReverseListIterator(){ cout << "delete ReverseListIterator!" << endl; }
	virtual void First() override;
	virtual void Next() override;
	virtual bool IsDone() override;
	virtual Item CurrentItem() const override;
private:
	List<Item>* _list;
	long _current;
};


template<class Item>
ReverseListIterator<Item>::ReverseListIterator(List<Item>* aList)
	:_list(aList), _current(0)
{
	cout << "construct ReverseListIterator!" << endl;
}

template<class Item>
void
ReverseListIterator<Item>::First()
{
	_current = _list->count() - 1;
}

template<class Item>
void
ReverseListIterator<Item>::Next()
{
	_current--;
}

template<class Item>
bool
ReverseListIterator<Item>::IsDone()
{
	return 0 > _current;
}

template<class Item>
Item
ReverseListIterator<Item>::CurrentItem() const
{
	return _list->at(_current);
}