#include "stdafx.h"
#include<iostream>
#include"tree.h"
using namespace std;
int main()
{
	BinTree tre;
	cout << "--------------------------------------------------------------" << endl;
	cout << "tre.CountNode();" << endl;
	tre.CountNode();
	cout << "--------------------------------------------------------------" << endl;
	cout << "tre.PreShow();" << endl;
	tre.PreShow();
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "tre.FindMaxSta();" << endl;
	tre.FindMaxSta();
	cout << "--------------------------------------------------------------" << endl;
	cout << "tre.InShow();" << endl;
	tre.InShow();
	return 0;
}
