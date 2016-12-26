#include "List.h"
#include "Iterator.h"
#include "ListIterator.h"
#include "ReverseListIterator.h"
#include <list>
#include <string>
int main()
{
	//为了让_CrtDumpMemoryLeaks()正确判断堆内存已经全部释放
	{
		list<string> ls = { "cheng", "6", "6", "8" };
		List<string> Ls(&ls);
		Iterator<string>* RListIter = Ls.CreateIterator();
		ListIterator<string>* ListIter = new ListIterator<string>(&Ls);

		for (ListIter->First(); !ListIter->IsDone(); ListIter->Next())
		{
			cout << ListIter->CurrentItem() << endl;
		}
		cout << endl;
		for (RListIter->First(); !RListIter->IsDone(); RListIter->Next())
		{
			cout << RListIter->CurrentItem() << endl;
		}
		/*这里可以用代理模式写一个资源管理类，
		就不需要用户释放内存了*/
		delete ListIter;
		delete RListIter;
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}
/*
output:
	construct Iterator!
	construct ListIterator!
	construct Iterator!
	construct ReverseListIterator!
	cheng
	6
	6
	8

	8
	6
	6
	cheng
	delete ListIterator!
	delete Iterator!
	delete ReverseListIterator!
	delete Iterator!
*/