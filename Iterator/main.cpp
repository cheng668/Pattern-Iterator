#include "List.h"
#include "Iterator.h"
#include "ListIterator.h"
#include "ReverseListIterator.h"
#include <list>
#include <string>
int main()
{
	//Ϊ����_CrtDumpMemoryLeaks()��ȷ�ж϶��ڴ��Ѿ�ȫ���ͷ�
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
		/*��������ô���ģʽдһ����Դ�����࣬
		�Ͳ���Ҫ�û��ͷ��ڴ���*/
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