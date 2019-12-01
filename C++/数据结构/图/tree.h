#include<iostream>
#include<stack>
using namespace std;
const int MaxSize = 10;    //图的最大顶点数
struct ArcNode
{
	int adjvex;
	ArcNode *next;
};
struct VertexNode
{
	int vertex;
	ArcNode *firstedge;
};

class ALGraph
{
public:
	ALGraph(int a[], int n, int e);
	void FindLink(int i, int j);
	void DFSTraverse(int v);
private:
	void dfstraverse(int v, int visited[]);
	bool findlink(const int & i,const int & j, stack<int> & q, int *visited);
	VertexNode adjlist[MaxSize];
	int vertexNum, arcNum;
};

ALGraph::ALGraph(int a[], int n, int e)
{
	vertexNum = n; arcNum = e;
	int i, j, k;
	for ( i = 0; i < vertexNum; i++)
		//输入顶点信息，初始化顶点表
	{
		adjlist[i].vertex = a[i];
		adjlist[i].firstedge = NULL;
	}
	ArcNode *s;
	for (k = 0; k<arcNum; k++)
		//输入边的信息存储在边表中
	{
		cin >> i >> j;
		s = new ArcNode; s->adjvex = j;
		s->next = adjlist[i].firstedge;
		adjlist[i].firstedge = s;
	}
}
void ALGraph::dfstraverse(int v,int visited[])
{
	cout << adjlist[v].vertex;  visited[v] = 1;
	ArcNode * p;
	int j;
	p = adjlist[v].firstedge;
	while (p != NULL)
	{
		j = p->adjvex;
		if (visited[j] == 0) 
		{
			cout << "->";
			dfstraverse(j, visited);		
		}
		p = p->next;
	}
}
void ALGraph::DFSTraverse(int v)
{
	int *visited = new int[vertexNum];
	for (int n = 0; n < vertexNum; n++)
	{
		visited[n] = 0;
	}
	dfstraverse(v, visited);
}
void ALGraph::FindLink(int i, int j)
{
	stack<int> q;
	int *visited = new int[vertexNum];
	for (int n = 0; n < vertexNum; n++)
	{
		visited[n] = 0;
	}
	q.push(i);
	findlink(i, j, q, visited);
	if (q.size()>1)
	{
		stack<int> q1;
		while (q.size() != 0)//颠倒栈
		{
			q1.push(q.top());
			q.pop();
		}
		while (q1.size() != 0)
		{
			cout << q1.top();
			if (q1.size() > 1)
			{
				cout << "->";
			}
			q1.pop();
		}
	}
	else
	cout << "无" << i << "到" << j << "的路径。";
}
bool ALGraph::findlink(const int & i,const int & j, stack<int>& q, int *visited)
{
	ArcNode * p = adjlist[i].firstedge;
	while (p != NULL)
	{
		q.push(p->adjvex);
		if(p->adjvex == j)
		{
			return 1;
		}
		else if(visited[p->adjvex]==0) //防止无限递归
		{
			visited[p->adjvex] = 1;
			if (findlink(p->adjvex, j, q, visited))//用BOOL值判断时候找到
			{
				return 1;
			}
		}
		q.pop();
		p = p->next;
	}
	return 0;
}
}