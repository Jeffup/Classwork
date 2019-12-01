#pragma once
#include<iostream>
using namespace std;
enum Status { SUCCESS = 0, FAILURE = 1, OVERSTACK = 2, ISFULL = 3 ,ISEMPTY = 4};
template<class T>
class Share_stack
{
	T * mvalue;
	int headIndex;
	int tailIndex;
	int elemcount;
	int size;
public:
	Share_stack(int size)
	{
		this->mvalue = new T[size];
		this->elemcount = 0;
		this->headIndex = -1;
		this->tailIndex = size;
		this->size = size;
	}
	Status isEmpty()
	{
		if (this->elemcount == 0)
			return SUCCESS;
		else if (this->elemcount != this->size)
			return FAILURE;
		else
			return ISFULL;
	}
	Status push_back_head(T elem);
	Status push_back_tail(T elem);
	Status pop_back_head(T & x);
	Status pop_back_tail(T & x);
	~Share_stack()
	{
		if (this->size == 1)delete mvalue;
		else if (this->size != 0)
			delete[]mvalue;
	}
};
template<class T>
Status Share_stack<T>::push_back_head(T elem)
{
	if (this->isEmpty() != ISFULL)//测试元素是否已满
	{//实行添加操作
		this->headIndex++;
		this->elemcount++;
		mvalue[this->headIndex] = elem;
		return SUCCESS;
	}
	else
	{
		return OVERSTACK;//超过顺序表的大小
	}
}
template<class T>
Status Share_stack<T>::push_back_tail(T elem)
{
	if (this->isEmpty() != ISFULL)//测试元素是否已满
	{//实行添加操作
		this->tailIndex--;
		this->elemcount++;
		mvalue[this->tailIndex] = elem;
		return SUCCESS;
	}
	else
	{
		return OVERSTACK;//超过顺序表的大小
	}
}
template<class T>
Status Share_stack<T>::pop_back_head(T & x)
{
	if (this->isEmpty() == SUCCESS)
	{
		return ISEMPTY;
	}
	else
	{
		x = this->mvalue[this->headIndex--];
		this->elemcount--;
		return SUCCESS;
	}
}
template<class T>
Status Share_stack<T>::pop_back_tail(T & x)
{
	if (this->isEmpty() == SUCCESS)
	{
		return ISEMPTY;
	}
	else
	{
		x = this->mvalue[this->tailIndex++];
		this->elemcount--;
		return SUCCESS;
	}
}

template<class TYPE>
void Swap(TYPE & val_1, TYPE & val_2)
{
	TYPE temp = val_1;
	val_1 = val_2;
	val_2 = temp;
}

class Queue
{
	int * mvalue;
	int elemnum;
	int msize;
public:
	Queue(int size):msize(size)
	{
		elemnum = 0;
		mvalue = new int[size];
	}
	bool isEmpty()
	{
		if (this->elemnum == 0)return true;
		else return false;
	}
	bool isFull()
	{
		if (this->elemnum == this->msize)return true;
		else return false;
	}

	Status push_back(int elem)
	{
		if (isFull() != true)
		{
			*(this->mvalue + elemnum) = elem;
			elemnum++;
			return SUCCESS;
		}
		else
			return ISFULL;
	}
	Status pop_back(int & elem)
	{
		if (isEmpty() != true)
		{
			elem = *(this->mvalue);
			for (int n = 1; n < elemnum; n++)
			{
				Swap<int>(*(mvalue + n - 1), *(mvalue + n));
			}
			elemnum--;
			return SUCCESS;
		}
		else
			return ISEMPTY;
	}
	void resize(int size)//重新开辟新空间
	{
		if (this->msize == 1)delete mvalue;
		else if (this->msize != 0)
			delete[]mvalue;
		elemnum = 0;
		mvalue = new int[size];
		msize = size;
	}
	~Queue()
	{
		if (this->msize == 1)delete mvalue;
		else if(this->msize != 0)
			delete[]mvalue;
	}
};

void Binomial_expansion(int factor)
{
	if (factor < 0)return;
	factor++;
	int temp1 = 0, temp2 = 0;
	Queue * pst1 = new Queue(1);
	Queue * pst2 = new Queue(1);
	for (int n = 0; n <= factor; n++)
	{
		pst2->push_back(1);
		for (int k = 1; k <= n; k++)
		{
			if (k % 2 == 1||k == 1)//取出并输出上一层的数据
			{
				if(pst1->pop_back(temp1)==SUCCESS && n != 1)
				{
					cout << temp1 << ' ';
				}
				else
				{
					temp1 = 0;
				}
			}
			if (k % 2 == 0 || k == 1)
			{
				if (pst1->pop_back(temp2) == SUCCESS )
				{
					if(k!=1)
					cout << temp2 << ' ';
				}
				else
				{
					temp2 = 0;
				}
			}
			pst2->push_back(temp1 + temp2);
		}
		cout << endl;//前一行输出完毕，后一行加载完毕
		pst1->resize(n + 2);//重新设置队列大小
		Swap<Queue *>(pst1, pst2);//交换指针，以便下一层的操作
	}
	pst1->~Queue();
	pst2->~Queue();
};
