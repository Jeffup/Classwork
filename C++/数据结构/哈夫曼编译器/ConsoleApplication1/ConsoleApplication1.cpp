// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
#include<sstream>
using namespace std;

class HFMNODE
{
	static int number;
public:
	int index;
	char val;
	unsigned int weight;
	string code;
	int parentindex;
	HFMNODE * leftnode;
	int leftindex;
	HFMNODE * rightnode;
	int rightindex;
	HFMNODE()
	{
		leftnode = nullptr;
		rightnode = nullptr;
		leftindex = -1;
		rightindex = -1;
		code = '-1';
		parentindex = -1;
		index = number++;
	}
	HFMNODE(const HFMNODE & hfm)
	{
		this->val = hfm.val;
		this->weight = hfm.weight;
	}
	bool CreatNode()
	{
		cout << "输入字符(#则退出)：";
		val = getchar();//清空输入流问题
		val = getchar();
		if (val == '#')return 0;
		cout << "输入权值：";
		cin >> weight;
		cout << endl;
		return 1;
	}
	~HFMNODE()
	{
		number--;
	}
};
int HFMNODE::number = 0;
class HFM
{
	HFMNODE * head;
	vector<HFMNODE *> vec;
	int Leafnumber;
	void printHelp(HFMNODE* p, string ss)//中序遍历
	{
		if (p == NULL)
			return;
		ss += "   ";
		printHelp(p->rightnode, ss);
		cout << ss << p->val << endl;
		printHelp(p->leftnode, ss);
	}
public:
	HFM()
	{
		head = nullptr;
		Leafnumber = 0;
	}
	//1、初始化
	void Initial()
	{
		head = new HFMNODE();
		while (head->CreatNode())
		{
			vec.push_back(head);
			Leafnumber++;
			head = new HFMNODE();
		}
		head->~HFMNODE();
		//---构造哈弗曼树---//
		vector <HFMNODE*> vec_temp = vec;		//辅助变量
		vector<HFMNODE*>::iterator k;
		
		while (vec_temp.size() != 1)
		{
			//---排序---//
			if (vec_temp.size() == 0)
			{
				cout << "内存中无内容！" << endl;
				return;
			}
			HFMNODE *temp;
			for (int n = 0; n < vec_temp.size(); n++)
			{
				for (int i = 0; i < vec_temp.size(); i++)
				{
					if (vec_temp[n]->weight < vec_temp[i]->weight)
					{
						temp = vec_temp[n];
						vec_temp[n] = vec_temp[i];
						vec_temp[i] = temp;
					}
				}
			}
			//----------//
			head = new HFMNODE();

			head->leftnode = vec_temp[0];
			head->leftindex = vec_temp[0]->index;
			vec_temp[0]->parentindex = head->index;

			head->rightnode = vec_temp[1];
			head->rightindex = vec_temp[1]->index;
			vec_temp[1]->parentindex = head->index;

			head->weight = vec_temp[0]->weight + vec_temp[1]->weight;
			head->val = '*';

			k = vec_temp.begin();
			vec_temp.erase(k);//删除第一个元素
			k = vec_temp.begin();
			vec_temp.erase(k);//删除第二个元素

			vec_temp.push_back(head);
			vec.push_back(head);
		}
		//-----------------//
		//---哈夫曼编码---//
		HFMNODE *temp;
		HFMNODE *temp1;
		HFMNODE *temp2;
		for (int n = 0; n < Leafnumber; n++)
		{
			temp1 = vec[n];
			temp1->code = '\0';
			while (temp1->parentindex != -1)
			{
				temp2 = vec[temp1->parentindex];
				if (temp2->leftindex == temp1->index)
					vec[n]->code = '0' + vec[n]->code;
				if (temp2->rightindex == temp1->index)
					vec[n]->code = '1' + vec[n]->code;
				temp = temp2;
				
				temp1 = temp;
			}
		}
		//----------------//
		//---输出哈弗曼树---//
		ofstream fout;
		fout.open("hfmTree.txt");
		if (!fout.is_open())
		{
			cout << "文件hfmTree.txt打开失败！" << endl;
			return;//强行退出
		}
		for (int n = 0; n < vec.size(); n++)
		{
			fout << vec[n]->index << ' ' << vec[n]->val << ' ' << vec[n]->weight << ' ' << vec[n]->leftindex << ' ' << vec[n]->rightindex << ' '<<vec[n]->parentindex<<' ' << vec[n]->code << endl;
		}
		fout.close();
		//------------------//
	}
	HFMNODE * FindCode(char val)
	{
		for (int n = 0; n < this->vec.size(); n++)
		{
			if (vec[n]->val == val)
				return vec[n];
		}
		return nullptr;
	}
	//2、编码
	void HFMCoding()
	{
		//---判断是否存在哈夫曼树&&哈弗曼树建立---//
		if (vec.size() == 0)
		{
			ifstream fin;
			fin.open("hfmTree.txt");
			if (!fin.is_open())
			{
				cout << "文件hfmTree.txt打开失败！" << endl;
				return;//强行退出
			}
			HFMNODE * temp;
			while (fin)
			{
				temp = new HFMNODE();
				fin >> temp->index;
				fin.get();
				temp->val = fin.get();
				fin >> temp->weight >> temp->leftindex >> temp->rightindex >> temp->parentindex >> temp->code;
				vec.push_back(temp);
				if (temp->leftindex >= 0)
				temp->leftnode = vec[temp->leftindex];
				if (temp->rightindex >= 0)
				temp->rightnode = vec[temp->rightindex];
				if(temp->rightindex == -1 & temp->leftindex == -1)
					Leafnumber++;
			}
			fin.close();
			vec[vec.size() - 1]->~HFMNODE();
			vec.pop_back();
			head = vec[vec.size() - 1];
		}
		//--------------------------//

		//---读入数据代码---//
		ifstream fin;
		fin.open("ToBeTran.txt");
		if (!fin.is_open())
		{
			cout << "文件 ToBeTran.txt 打开失败！程序终止！" << endl;
			fin.close();
			return;
		}
		ostringstream buf;
		char ch;
		while (buf&&fin.get(ch))
			buf.put(ch);
		string str;
		str = buf.str();
		fin.close();
		//------------------//

		//---输出数据代码---//
		ofstream fout;
		fout.open("CodeFile.txt");
		if (!fout.is_open())
		{
			cout << "文件 ToBeTran.txt 打开失败！程序终止！" << endl;
			fout.close();
			return;
		}
		//---核心代码---//
		HFMNODE * node;
		for (int n = 0; n < str.size(); n++)
		{
			node = FindCode(str[n]);
			fout << node->code;
		}
		//--------------//
		fout.close();
		//------------------//
	}
	//3、译码
	void HFMDecoding()
	{
		if (vec.size() == 0)
		{
			cout << "内存中无哈弗曼树！请先进行初始化！" << endl;
			return;
		}
		//---读取文件---//
		ifstream fin;
		fin.open("CodeFile.txt");
		if (!fin.is_open())
		{
			cout << "文件 CodeFile.txt 打开失败！程序终止！" << endl;
			fin.close();
			return;
		}
		ostringstream buf;
		char ch;
		while (buf&&fin.get(ch))
			buf.put(ch);
		string str;
		str = buf.str();
		fin.close();
		//--------------//

		//---输出数据代码---//
		ofstream fout;
		fout.open("TextFile.txt");
		if (!fout.is_open())
		{
			cout << "文件 TextFile.txt 打开失败！程序终止！" << endl;
			fout.close();
			return;
		}
		//---核心代码---//
		HFMNODE * temp = head;
		for (int n = 0; n < str.size(); n++)
		{
			if (str[n] == '1' )//&& temp->rightnode != nullptr
				temp = temp->rightnode;
			if (str[n] == '0')// && temp->leftnode != nullptr
				temp = temp->leftnode;
			if (temp->leftnode == nullptr&& temp->rightnode == nullptr)
			{
				fout << temp->val;
				temp = head;
			}
		}
		//--------------//
		fout.close();
		//------------------//
	}
	//4、打印代码文件
	void PrintCodeFile()
	{
		if (vec.size() == 0)
		{
			cout << "内存中无哈弗曼树！请先进行初始化！" << endl;
			return;
		}
		//---读取文件---//
		ifstream fin;
		fin.open("CodeFile.txt");
		if (!fin.is_open())
		{
			cout << "文件 CodeFile.txt 打开失败！程序终止！" << endl;
			fin.close();
			return;
		}
		ostringstream buf;
		char ch;
		while (buf&&fin.get(ch))
			buf.put(ch);
		string str;
		str = buf.str();
		fin.close();
		//--------------//

		//---写入到CodePrin文件 && 输出到屏幕---//
		ofstream fout;
		fout.open("CodePrin.txt");
		if (!fout.is_open())
		{
			cout << "文件 CodePrin.txt 打开失败！程序终止！" << endl;
			fout.close();
			return;
		}
		for (int n = 1; n <= str.size(); n++)
		{
			cout << str[n-1];
			fout << str[n-1];
			if (n % 50 == 0)
			{
				cout << endl;
				fout << endl;
			}
		}
		fout.close();
		//----------------------------------------//
	}
	//5、打印哈弗曼树
	void ShowHFMTree()
	{
		if (vec.size() == 0)
		{
			cout << "内存中无哈弗曼树！请先进行初始化！" << endl;
			return;
		}
		string ss = "";
		printHelp(head, ss);
	}
	void Management()
	{
		cout << "*************************************************************" << endl;
		cout << "*******************欢迎使用哈夫曼编/译码器*******************" << endl;
		cout << "*************************************************************" << endl;
		cout << "*                          功能菜单                         *" << endl;
		cout << "*1、初始化|2、编码 |3、译码 |4、打印代码文件|5、打印哈弗曼树*" << endl;
		cout << "*************************************************************" << endl;
		int choose;
		cout << "请输入功能选项(-1 to quit)：";
		cin >> choose;
		while (choose != -1)
		{
			switch (choose)
			{
			case 1:Initial(); break;
			case 2:HFMCoding(); break;
			case 3:HFMDecoding(); break;
			case 4:PrintCodeFile(); break;
			case 5:ShowHFMTree(); break;
			default:cout << "无此选项！" << endl; break;
			}
			cout << endl;
			cout << "*************************************************************" << endl;
			cout << "*                          功能菜单                         *" << endl;
			cout << "*1、初始化|2、编码 |3、译码 |4、打印代码文件|5、打印哈弗曼树*" << endl;
			cout << "*************************************************************" << endl;
			cout << "请输入功能选项(-1 to quit)：";
			cin >> choose;
		}
	}
};
int main()
{
	HFM hfm;
	hfm.Management();
	return 0;
}
//1、清空输入流问题✔ 加一个val = getchar();
//2、管理程序会崩溃✔ 少了个break;
//3、无法打开CodeFile文件✔ 加一个文件就好了
//4、构造哈弗曼树的时候左右节点的序号乱了✔ 结果是因为用的是vec而不是vec_temp
//5、构造哈弗曼树的时候vector发生溢出✔ 结果是忘了加条件，因为当index=-1的时候就崩了
//6、FindCode函数中root是空指针✔ 在HFMCoding函数中没有赋值给head，所以传入FindCode中参数root为空-》head = vec[vec.size() - 1];
//7、编码没反应，我觉得是FindCode的问题✔ 好像不是，在录入的时候多出了一个节点（空的），要去掉，head才有leftnode和rightnode
//8、CodePrin.txt输出格式错误✔ 加一个if(n!=0)
//9、将其中一个FindCode函数去掉，优化HFMCoding函数
//10、然而，译码函数HFMDecoding错了，没输出✔ 我用的是string类型，所以里面的0和1都是字符类型，所以我应该用str[n] == '0'; 而不是str[n] == '1';
/*bool FindCode(char val, int weight, HFMNODE* root, ostream & os)//辅助函数->>编码
	{
		if (val == root->val&&weight == root->weight)
			return 1;
		else if ((root->weight > weight&&root->leftnode == nullptr) || (root->weight < weight&&root->rightnode == nullptr))
			return 0;
		else
		{
			if (root->weight > weight)
			{
				os << '0';
				FindCode(val, weight, root->leftnode, os);
			}
			else
			{
				os << '1';
				FindCode(val, weight, root->rightnode, os);
			}
		}
	}*/





// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
