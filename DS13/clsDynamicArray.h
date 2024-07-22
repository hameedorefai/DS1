#pragma once
#include <iostream>
using namespace std;
template <class T>
class clsDynamicArray
{
	T* OriginalArray;
	int _ItemsSize = 0;
	int _Size = 0;
	T* TempArray;
public:

	clsDynamicArray(int Size)
	{
		_Size = Size;
		OriginalArray = new T[Size];
	}

	void SetItem(T Item)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (_ItemsSize == i)
			{
				*(OriginalArray + i) = Item;
				_ItemsSize++;
				break;
			}
		}

	}

	bool SetItem(int Index, T Value)
	{
		if (_Size > Index && Index >= 0)
		{
			OriginalArray[Index] = Value;
			return 1;
		}
		return 0;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	int Size()
	{
		return _Size;
	}

	void ReSize(int NewSize)
	{
		TempArray = new T[NewSize];

		for (int i = 0; i < NewSize; i++)
		{
			TempArray[i] = OriginalArray[i];
		}
		delete OriginalArray;
		OriginalArray = TempArray;
		_Size = NewSize;
	}

	T GetItem(int Index)
	{
		return OriginalArray[Index];
	}

	void Reverse()
	{
		TempArray = new T[_Size];
		for (int j = _Size - 1; j >= 0; j--)
		{
			TempArray[_Size - j - 1] = OriginalArray[j];
		}
		delete[] OriginalArray;
		OriginalArray = TempArray;
	}

	void Clear()
	{
		ReSize(0);
	}

	int Find(T Value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (Value == OriginalArray[i])
				return i;
		}
		return -1;
	}

	bool DeleteItemAt(int Index)
	{
		if (Index >= _Size || Index < 0)
			return false;
		for (int i = Index + 1; i < _Size ; i++)
			OriginalArray[i - 1] = OriginalArray[i];
		_Size--;
		return true;
	}

	bool DeleteFirstItem()
	{
		return DeleteItemAt(0);
	}

	bool DeleteLastItem()
	{
		return DeleteItemAt(_Size - 1);
	}

	bool DeleteItem(T Value)
	{
		int Index = Find(Value);
		return DeleteItemAt(Index);
	}


	bool InsertAt(int Index, T Value)
	{
		if (Index >= _Size || Index < 0)
			return false;

		_Size++;
		TempArray = new T[_Size];
		for (int i = 0; i < _Size; i++)
		{
			TempArray[i] = OriginalArray[i];
		}

		TempArray[Index] = Value;
		for (int i = Index; i < _Size - 1; i++)
		{
			TempArray[i + 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = TempArray;

		return true;

	}

	bool InsertAtBeginning(T Value)
	{
		return InsertAt(0, Value);

	}

	bool InsertAtEnd(T Value)
	{
		_Size++;
		OriginalArray[_Size - 1] = Value;
		return 1;
	}

	bool InsertBefore(int Index, T Value)
	{		
		return InsertAt(Index, Value);
	}

	bool InsertAfter(int Index, T Value)
	{
		if (Index >= _Size)
			return InsertAt(_Size-1, Value);

		return InsertAt(Index+1, Value);

	}


	void Print()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << "arr [" << i << "]  : " <<  * (OriginalArray + i) << "\n";
		}
		cout << endl;
	}

};

