#pragma once
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//节点类
class Node 
{
public:
	char value;
	Node * leftnode;
	Node * rightnode;
	Node()
	{
		leftnode = rightnode = nullptr;
	}
	Node(char val)
	{
		value = val;
		leftnode = rightnode = nullptr;
	}
};
//二叉树类
class BinTree
{
	Node * head;//头结点
	int node_num;//节点数
	int countnode(const Node * node);//递归函数：数节点的子函数
	void preshowtree(Node * r);//递归函数：前序遍历的子函数
	void CreateBtr(Node *& r);//递归函数：创建二叉树的子函数（前序创建）
public:
	BinTree();
	void PreShow();//前序遍历
	void FindMaxSta();//寻找最大宽度
	void CountNode();//数节点（叶子）
	void InShow();//非递归中序遍历
};

BinTree::BinTree() 
{
	CreateBtr(head);
}
void BinTree::preshowtree(Node * r)
{
	if (r != nullptr)cout << r->value << ' ';
	else { cout << '#' << ' '; return; }
	preshowtree(r->leftnode);
	preshowtree(r->rightnode);
}
void BinTree::CreateBtr(Node *& r)
{
	char ch;
	cin >> ch;
	if (ch == '#') r = nullptr;
	else
	{
		r = new Node(ch);
		CreateBtr(r->leftnode);
		CreateBtr(r->rightnode);
	}
}
void BinTree::FindMaxSta()
{
	//使用队列进行层遍历
	queue<Node*> q;
	int max_wide = 1;
	int max_floor = 1;
	int now_wide = 1;
	int floor = 1;
	q.push(this->head);
	int n = 0;
	while (q.size() != 0)
	{
		for (n = 0; n < now_wide; n++)
		{
			if (q.front()->leftnode != nullptr)q.push(q.front()->leftnode);
			if (q.front()->rightnode != nullptr)q.push(q.front()->rightnode);
			q.pop();//delete
		}
		floor++;
		now_wide = q.size();
		if (now_wide > max_wide)
		{
			max_wide = now_wide;
			max_floor = floor;
		}
	}
	cout << "max wide is: " << max_wide << " in the " << max_floor << " floor." << endl;
}
int BinTree::countnode(const Node * node)
{
	int count = 0;
	if (node != nullptr)
	{
		if (node->leftnode == NULL&&node->rightnode == NULL)
		return 1;
		count += countnode(node->leftnode);
		count += countnode(node->rightnode);
		return count;
	}
	else
		return 0;
}
void BinTree::CountNode()
{
	cout << "叶子数：" << countnode(head) << endl;
}
void BinTree::PreShow()
{
	preshowtree(head);
}
void BinTree::InShow()
{
	stack<Node*> s;
	Node * temp = nullptr;
	s.push(head);
	while (s.size()!=0)
	{
		if (s.top()->leftnode == nullptr)
		{
			cout << s.top()->value <<" # ";
			temp = s.top();
			s.pop();
			if (temp->rightnode != nullptr)
			{
				s.push(temp->rightnode);
			}
			else
			{
				cout << s.top()->value << " # ";
				temp = s.top();
				s.pop();
				if (temp->rightnode != nullptr)
				{
					s.push(temp->rightnode);
				}
			}
		}
		else
		{
			s.push(s.top()->leftnode);
		}

	}
}
