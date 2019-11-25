#include <iostream>
#include "FibHeap.h"
#include<vector>
using namespace std;

#define DEBUG 0

const int NoEdge = -1;
void Dijkstra(int s, vector<int>& d, int p[], int arr[][5])
{
	//寻找从顶点s（第几号节点）出发的最短路径,在d中存储的是s->i的最短距离 ,arr是存储图的矩阵 
	//p中存储的是i的父节点    
	int n = d.size();	//此时d容器的大小既是节点的多少
	if (s < 0 || s > n)
	{
		cerr << "溢出！" << endl;
		return;
	}
	//路径可到达的顶点列表,这里可以用上述实现的fibonacci堆代码。   
	FibHeap<int> FH;

	//初始化d, p, and L     
	for (int i = 0; i < n; i++)
	{
		d[i] = arr[s][i];

		if (d[i] == NoEdge)
		{
			p[i] = NoEdge;
		}
		else
		{
			p[i] = s;
			FH.insert(d[i], i);//插入结点 d[i]是key，代表距离，i代表下标
		}
	}

	//更新d, p     
	while (FH.nodenum())
	{
		//寻找最小d的点v     
		FibNode<int>* v = FH.minimum();
		//FibHeapNode<int, int>* w = v.Next();
		int i = v->index;
		d[i] = v->key;
		FH.removeMin();
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != NoEdge
				&& (p[j]==NoEdge || d[j] > d[i] + arr[i][j]))    //d[i]是父节点  
			{
				// 刷新更小的d[j]      
				d[j] = d[i] + arr[i][j];
				FH.update(j, d[j]);
				// 如果j没有父节点,则添加到L     
				if (p[j]== NoEdge)
					FH.insert(d[j], j);

				// 更新父节点     
				p[j] = i;
			}
		}
	}
}


int main()
{
	int weight1[5][5] ={
				{0,4,NoEdge,2,NoEdge},
				{4,0,4,1,NoEdge},
				{NoEdge,4,0,1,3},
				{2,1,1,0,7},
				{NoEdge,NoEdge,3,7,0}
	};
	int p[5] = { -1 };
	vector<int>d(5);
	Dijkstra(0, d, p, weight1);
	for (int i = 0; i < 5; i++)
	{
		cout <<i<<':'<< d[i] << endl;
	}
	return 0;
}