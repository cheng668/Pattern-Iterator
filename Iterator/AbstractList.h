#pragma once
#include "Iterator.h"
template<class Item>
//����ģʽ
class AbstractList
{
public:
	AbstractList(){}
	virtual Iterator<Item>* CreateIterator() = 0;
	virtual ~AbstractList(){}
	//...
};