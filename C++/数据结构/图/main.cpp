//。cpp
#include "stdafx.h"
#include<iostream>
#include"tree.h"
using namespace std;

int main()
{
	int * a = new int[7];
	for (int n = 0; n < 7; n++)
	{
		a[n] = n;
	}
	ALGraph mg(a, 7, 14);//有来有往
	cout << "mg.DFSTraverse(1):";
	mg.DFSTraverse(1);
	cout << "\nmg.DFSTraverse(2);";
	mg.DFSTraverse(2);
	cout << "\nmg.FindLink(0, 4);";
	mg.FindLink(0, 4);
	return 0;
}
