// DS13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "clsMyString.h"
using namespace std;


int main()
{
	clsMyString S1;

	S1.Value = "Hameedo";
	S1.Value = "Refai";
	S1.Value = "Donia";
	S1.Value = "Aref";

	S1.Undo();


	cout << "Value : " << S1.Value << endl;


	S1.Redo();

	cout << "Value : " << S1.Value << endl;


}

