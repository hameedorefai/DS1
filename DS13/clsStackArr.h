#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
#include "clsQueueLL.h"
#include "clsQueueArr.h"
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsStackArr : public clsQueueArr <T>
{

protected:
	clsDynamicArray <T> _List;

public:

	void Push(T Item)
	{
		_List.InsertAtBeginning(Item);
	}

	T Bottom()
	{
		return _List.GetItem(_List.Size() - 1);

	}

	T Top()
	{
		return _List.GetItem(0);
	}

};

