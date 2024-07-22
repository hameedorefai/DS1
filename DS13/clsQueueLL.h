#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class T>
class clsQueue
{

protected:
	clsDblLinkedList <T> _List;

public:

	void Push(T Item)
	{
		_List.InsertAtEnd(Item);
	}

	void Pop()
	{
		_List.DeleteFirstNode();
	}
	  
	void Print()
	{
		_List.PrintList();
	}
	
	int Size()
	{
		return _List.Size();
	}
	
	bool IsEmpty()
	{
		return _List.IsEmpty();
	}
	
	T Front()
	{
		return _List.GetItem(0);
	}
	
	T Back()
	{
		return _List.GetItem(_List.Size() - 1);
	}

	T GetItem(int Index)
	{
		return _List.GetItem(Index);
	}

	void Reverse()
	{
		_List.Reverse();
	}

	void UpdateItem(int Index, T Value)
	{
		_List.UpdateItem(Index, Value);
	}

	void InsertAfter(int Index, T Value)
	{
		_List.InsertAfter(Index, Value);
	}

	void InsetAtFront(T Value)
	{
		_List.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_List.InsertAtEnd(Value);
	}

	void Clear()
	{
		_List.Clear();
	}






};

