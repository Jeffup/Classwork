#include "stdafx.h"
#include<iostream>
#include"stack.h"
using namespace std;
int main()
{
	Share_stack<int>ss(6);
	int n = 0;
	for (; n < 3; n++)
	{
		ss.push_back_head(n);
		ss.push_back_tail(n);
	}
	for (int k = 0; k < 3; k++)
	{
		ss.pop_back_head(n);
		cout << n << ' ';
		ss.pop_back_tail(n);
		cout << n << endl;
	}
	Binomial_expansion(9);
	return 0;
}
