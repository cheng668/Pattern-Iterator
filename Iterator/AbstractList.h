#pragma once
#include "Iterator.h"
template<class Item>
//工厂模式
class AbstractList
{
public:
	AbstractList(){}
	virtual Iterator<Item>* CreateIterator() = 0;
	virtual ~AbstractList(){}
	//...
};