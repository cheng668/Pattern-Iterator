#pragma once
#include "Iterator.h"
#include "List.h"

template<class Item>
class ListIterator :
	public Iterator<Item>
{
public:
	ListIterator(List<Item>* aList);
	virtual ~ListIterator();
	virtual void First() override;
	virtual void Next() override;
	virtual bool IsDone() override;
	virtual Item CurrentItem() const override;
private:
	List<Item>* _list;
	long _current;
};

template<class Item>
ListIterator<Item>::~ListIterator()
{
	//delete _list;
	cout << "delete ListIterator!" << endl;
}

template<class Item>
ListIterator<Item>::ListIterator(List<Item>* aList)
	:_list(aList), _current(0)
{
	cout << "construct ListIterator!" << endl;
}

template<class Item>
void
ListIterator<Item>::First()
{
	_current = 0;
}

template<class Item>
void
ListIterator<Item>::Next()
{
	_current++;
}

template<class Item>
bool
ListIterator<Item>::IsDone()
{
	return _list->count() <= _current;
}

template<class Item>
Item
ListIterator<Item>::CurrentItem() const
{
	return _list->at(_current);
}