#pragma once
#include <iostream>
using namespace std;
template<class Item>
class Iterator
{
public:

	virtual ~Iterator(){ cout << "delete Iterator!" << endl; }

	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Item CurrentItem() const = 0;
protected:
	Iterator(){ cout << "construct Iterator!" << endl; }
};

