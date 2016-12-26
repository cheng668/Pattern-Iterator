#pragma once
#include "AbstractList.h"
#include <list>

class IteratorOutOfBounds
{
};

template<class Item>
class ReverseListIterator;

//template<class Item>
//class ListIterator;

template<class Item>
class Iterator ;

template<class Item>
class List
	:public AbstractList<Item>
{
public:
	List(list<Item>* aList);
	virtual ~List();
	long count() const { return _list->size(); }
	Item at(long idx) const;
	list<Item>* operator->(){ return _list; }
	list<Item> operator*(){ return *_list; }
	virtual Iterator<Item>* CreateIterator() override;
private:
	list<Item>* _list;
};

template<class Item>
List<Item>::~List()
{

}

template<class Item>
List<Item>::List(list<Item>* aList)
	:_list(aList)
{

}

template<class Item>
Iterator<Item>*
List<Item>::CreateIterator()
{
	return new ReverseListIterator<Item>(this);
}

template<class Item>
Item
List<Item>::at(long idx) const
{
	if (idx >= count()) throw IteratorOutOfBounds();
	list<Item>::iterator iter = _list->begin();
	for (int ix = 0; ix<idx; ++ix) ++iter;
	return *iter;
}