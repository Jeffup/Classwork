#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include <math.h>
#include<sstream>

using namespace  std;
#pragma warning(disable:4996)
//算数编码
//	递归的F（s r）函数
double Fsr(char* s,char a, char b, double pa, double pb);
//二进制转结果
char* BtoO(double p, int len, char a, char b);
char* Arithmetic_coding(char* in,char a,char b,double pa,double pb)
{
	//声明主要信息
	int count_a = 0, count_b = 0;//字符a,b个数
	double L = 0;//输出字符串长度
	//A{a,b}
	//检测编码环境的正确性！
	if (pa + pb != 1)
	{
		cout << "概率之和不是1，编码失败！" << endl;
		return NULL;
	}
	for (int i = 0; i < strlen(in); i++)
	{
		if (in[i] != a && in[i] != b)
		{
			cout << "字符串包含字符集：{" << a << ',' << b << "} 之外的字符！编码失败！" << endl;
			return NULL;
		}
		//计算a,b字符的数量
		if (in[i] == a)count_a++;
		else count_b++;
	}

	//取得长度
	L = ceil(log(1 / (pow(pa, count_a) * pow(pb, count_b))) / log(2));
	//递归得出结果
	return BtoO(Fsr(in, a, b, pa, pb), L, a, b);
}
//F(s r) = F(s)+P(s)*F(r)
double Fsr(char* s, char a, char b, double pa, double pb)
{
	double count_Fs;
	double count_P=0;
	if (strlen(s) <= 1)
	{
		if (*s == a)
			count_Fs = 0;
		else
			count_Fs = pa;
	}
	else {
		count_P = 1;
		char tmp_r = s[strlen(s)-1];
		char* tmp_s = new char[strlen(s)];
		//P(s)*F(r)
		for (int i = 0; i < strlen(s)-1; i++)
		{
			tmp_s[i] = s[i];
			if (s[i] == a)
				count_P *= pa;
			else
				count_P *= pb;
		}
		if (tmp_r == b)
		{
			count_P *= pa;
		}
		else
		{
			count_P = 0;
		}
		tmp_s[strlen(s) - 1] = '\0';
		//F(s)
		count_Fs = Fsr(tmp_s, a, b, pa, pb);
		delete[]tmp_s;
	}	
	//cout << count_Fs + count_P << endl;
	return count_Fs + count_P;
}
//二进制转结果
char* BtoO(double p,int len, char a, char b)
{
	char* re = new char[len+1];
	for (int i = 0; i < len; i++)
	{
		p *= 2;
		if (p > 1)
		{
			re[i] = b;
			p -= 1;
		}
		else
		{
			re[i] = a;
		}
	}
	if (p > 0)
	{
		for (int n = len-1; n >= 0; n--)
		{
			if (re[n] == '0')
			{
				re[n] = '1';
				break;
			}
			else
			{
				re[n] = '0';
			}
		}
	}
	re[len] = '\0';
	return re;
}

//将结果变成十进制小数
double OtoB(char* p, char b);
char* Fs(char * P, char a, char b, double pa, double pb);
char* Arithmetic_decoding(char* out, char a, char b, double pa, double pb)
{
	double P;
	if (pa + pb != 1)
	{
		cout << "概率之和不是1，编码失败！" << endl;
		return NULL;
	}
	char* de = new char[strlen(out)+1];
	for (int i = 0; i < strlen(out); i++)
	{
		if (out[i] != a && out[i] != b)
		{
			cout << "字符串包含字符集：{" << a << ',' << b << "} 之外的字符！编码失败！" << endl;
			return NULL;

		}
		if (out[i] == a)
		{
			de[i] = '0';
		}
		else
		{
			de[i] = '1';
		}
	}
	de[strlen(out)] = '\0';
	return Fs(de, a, b, pa, pb);
}
double OtoB(char* p,  char b)
{
	double de = 0;
	for (int i = 1; i <= strlen(p); i++)
	{
		if (p[i-1] == b)
		{
			de += pow(2, -i);
		}
	}
	return de;
}
 char* Fs(char * P, char a, char b, double pa, double pb)
{
	//密码概率
	double C = OtoB(P, b);
	//累计译码的概率
	double p;
	//C - F(s) < P(s) * P(0) =>0   判断方法（译码方法）
	//一开始的译码输出（初始化）
	string str;
	if (C < pa)
	{
		str += '0';
	}
	else
	{
		str += '1';
	}
	int i = 0;
	while(1)
	{
		p = 1;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == a)
			{
				p *= pa;
			}
			else
			{
				p *= pb;
			}
		}
		if (ceil(log(1/p)/log(2))>=strlen(P))break;
		if (C - Fsr((char*)str.c_str(), a, b, pa, pb) < p * pa)
		{
			str += '0';
		}
		else if(C - Fsr((char*)str.c_str(), a, b, pa, pb) > p * pa)
		{
			str += '1';
		}
		i++;

	}
	char* re = new char[str.length() + 1];
	int j = 0;
	for (; j < str.length();j++)
	{
		re[j] = str[j];
	}
	re[j] = '\0';
	return re;
}

 //r为译码符号的个数
 bool Judge_Only_Decoding(vector<string> en, int r = 2)
 {
	 //克拉夫特不等式
	 double Kraft = 0;
	 for (int i = 0; i < en.size(); i++)
	 {
		 Kraft += pow(r, -(int)en[i].length());
	 }
	 if (Kraft > 1)
	 {
		 cout << "不满足克拉夫特不等式！" << endl;
		 return false;
	 }
	 else
	 {
		 //萨德纳斯判断
		 //将码C中所有可能的尾随后缀组成一个集合F
		 //当且仅当集合F中没有包含任意码字
		 //则可判断码C为唯一可译变长码
		 vector<string>postfix; 
		 string tmp;
		 for (int i = 0; i < en.size(); i++)
		 {
			 if (!tmp.empty())
				 tmp.clear();
			 for (int j = 0; j < en.at(i).length() - 1; j++)
			 {
				 tmp = tmp + en.at(i)[j];
				 int k = 0;
				 for (; k < postfix.size(); k++)
				 {
					 if (postfix.at(k) == tmp)
					 {
						 break;
					 }
				 }	
				 if (k == postfix.size())
				 {
					 postfix.push_back(tmp);
				 }
				 for (int n = 0; n < en.size(); n++)
				 {
					 if (postfix.at(k) == en.at(n))
					 {
						 return false;
					 }
				 }
			 }
		 }
		 return true;
	 }
 }

 //5
 //游程编码
 string RL_Encoding(string en)
 {
	 //计算长度
	 char tmp = '0';
	 string len = "0";
	 //编码结果
	 string re;
	 for (int i = 0; i <= en.length(); i++)
	 {
		 if (en[i] == tmp)
		 {
			 len[0] = char((int)(len[0]) + 1);
		 }
		 else
		 {
			 re += len;
			 re += " ";//间隔开
			 len = "1";//重新计算长度
			 if (tmp == '0')
			 {
				 tmp = '1';
			 }
			 else
			 {
				 tmp = '0';
			 }

		 }
	 }
	 return re;
 }
 string RL_Decoding(string de)
 {
	 string re;
	 string tmp;
	 for (int i = 0; i < de.length(); i++)
	 {
		 if (i % 4 == 0)
		 {
			 tmp = "0";
		 }
		 if (i % 4 == 2)
		 {
			 tmp = "1";
		 }
		 if (de[i] != ' ')
		 {
			 for (int j = 0; j<(int(de[i])-48); j++)
			 {
				 re += tmp;
			 }
		 }
	 }
	 return re;
 }

 //凯撒?加密
 string Caesar_Encoding(string en)
 {
	 char tmp;
	 for (int i = 0; i < en.length()/2; i++)
	 {
		 tmp = en[i];
		 en[i] = en[en.length() - 1 - i];
		 en[en.length() - 1 - i] = tmp;
	 }
	 return en;
 }
 string Caesar_Decoding(string de)
 {
	 char tmp;
	 for (int i = 0; i < de.length() / 2; i++)
	 {
		 tmp = de[i];
		 de[i] = de[de.length() - 1 - i];
		 de[de.length() - 1 - i] = tmp;
	 }
	 return de;
 }

 //类MH编码
 class MH_Node
 {
 public:
	 char RL;
	 string code;
	 MH_Node* parentNode;
	 MH_Node* rightNode;
	 MH_Node* leftNode;
	 MH_Node()
	 {
		 leftNode = nullptr;
		 rightNode = nullptr;
		 parentNode = nullptr;
		 code = "";
		 RL = -1;
	 }
	 MH_Node(MH_Node* mh)
	 {
		 this->RL = mh->RL;
		 this->code = mh->code;
		 leftNode = nullptr;
		 rightNode = nullptr;
		 parentNode = nullptr;
	 }
 };
 class MH_Coding
 {
	 MH_Node* head1;//白
	 vector<MH_Node*> vec1;
	 MH_Node* head2;//黑
	 vector<MH_Node*> vec2;
	 MH_Node* temp;
	 //vector<MH_Node*>* vec;
 public:
	 MH_Coding(char * filename1, char* filename2)
	 {//码表
		 head1 = new MH_Node;
		 head2 = new MH_Node;
	//构造树
		 ifstream fin;
		 fin.open(filename1);
		 if (!fin.is_open())
		 {
			 cout << "文件" << filename1 << "打开失败！" << endl;
			 return;//强行退出
		 }
		//读取节点信息		
		 while (fin)
		 {
			 MH_Node* tmp = new MH_Node;
			 fin >> tmp->RL >> tmp->code;
			 vec1.push_back(tmp);
		}
		 fin.close();
		 for (int i = 0; i < vec1.size(); i++)
		 {//0->left   1->right
			 int codelen = vec1.at(i)->code.length();
			 MH_Node* tmp = head1;
			 for (int j = 0; j < codelen; j++)
			 {
				 if (vec1.at(i)->code[j] == '0')
				 {
					 if (j == codelen - 1)
					 {
						 tmp->leftNode = vec1.at(i);
						 break;
					 }
					 if (tmp->leftNode == nullptr)
					 {
						 MH_Node* node = new MH_Node;
						 node->parentNode = tmp;
						 tmp->leftNode = node;
						 vec1.push_back(node);
						 tmp = node;
					 }
					 else
					 {
						 tmp = tmp->leftNode;
					 }
				 }
				 else {
					 if (j == codelen - 1)
					 {
						 tmp->rightNode = vec1.at(i);
						 break;
					 }
					 if (tmp->rightNode == nullptr)
					 {
						 MH_Node* node = new MH_Node;
						 node->parentNode = tmp;
						 tmp->rightNode = node;
						 vec1.push_back(node);
						 tmp = node;
					 }
					 else
					 {
						 tmp = tmp->rightNode;
					 }
				 }
			 }
		 }
		 fin.open(filename2);
		 if (!fin.is_open())
		 {
			 cout << "文件" << filename2 << "打开失败！" << endl;
			 return;//强行退出
		 }
		 //读取节点信息		
		 while (fin)
		 {
			 MH_Node* tmp = new MH_Node;
			 fin >> tmp->RL >> tmp->code;
			 vec2.push_back(tmp);
		 }
		 fin.close();
		 for (int i = 0; i < vec2.size(); i++)
		 {//0->left   1->right
			 int codelen = vec2.at(i)->code.length();
			 MH_Node* tmp = head2;
			 for (int j = 0; j < codelen; j++)
			 {
				 if (vec2.at(i)->code[j] == '0')
				 {
					 if (j == codelen - 1)
					 {
						 tmp->leftNode = vec2.at(i);
						 break;
					 }
					 if (tmp->leftNode == nullptr)
					 {
						 MH_Node* node = new MH_Node;
						 node->parentNode = tmp;
						 tmp->leftNode = node;
						 vec2.push_back(node);
						 tmp = node;
					 }
					 else
					 {
						 tmp = tmp->leftNode;
					 }
				 }
				 else {
					 if (j == codelen - 1)
					 {
						 tmp->rightNode = vec2.at(i);
						 break;
					 }
					 if (tmp->rightNode == nullptr)
					 {
						 MH_Node* node = new MH_Node;
						 node->parentNode = tmp;
						 tmp->rightNode = node;
						 vec2.push_back(node);
						 tmp = node;
					 }
					 else
					 {
						 tmp = tmp->rightNode;
					 }
				 }
			 }
		 }
	//构造完毕
	 }
	 string MH_Encoding(string en)
	 {//从RL->CODE
		 string re;
		 int BW = 0;
		 int i = 0;
		 for (; i <= en.length(); i++)
		 {
			 if (i % 4 == 0)
			 {
				 for (int j = 0; j < vec1.size(); j++)
				 {
					 if (vec1.at(j)->RL == en[i])
					 {
						 re += vec1.at(j)->code;
						 break;
					 }
					 BW = 0;
				 }
			 }
			 else if (i % 4 == 2)
			 {
				 for (int j = 0; j < vec2.size(); j++)
				 {
					 if (vec2.at(j)->RL == en[i])
					 {
						 re += vec2.at(j)->code;
						 break;
					 }
				 }
				 BW = 1;
			 }
		 }
		 if (BW == 0)
		 {
			 //截码方法，加两17
			 for (int m = 0; m < vec1.size(); m++)
			 {
				 if (vec1.at(m)->RL == '@')
				 {
					 re += vec1.at(m)->code;
				 }
			 }
			 for (int m = 0; m < vec2.size(); m++)
			 {
				 if (vec2.at(m)->RL == '@')
				 {
					 re += vec2.at(m)->code;
				 }
			 }
		 }
		 else {
			 for (int m = 0; m < vec2.size(); m++)
			 {
				 if (vec2.at(m)->RL == '@')
				 {
					 re += vec2.at(m)->code;
				 }
			 }
			 for (int m = 0; m < vec1.size(); m++)
			 {
				 if (vec1.at(m)->RL == '@')
				 {
					 re += vec1.at(m)->code;
				 }
			 }
		 }
		 if (re.length() % 4 != 0)
		 {
			 for (int n = 0; n < re.length() % 4; n++)
			 {
				 re += '0';
			}
		 }
		 return re;
	 }
	 string MH_Decoding(string de)
	 {
		 vector<MH_Node*> tmp;
		 string re;
		 int getHead = 1;//判断取头
		 int BorK = 0;//判断黑白
		 for (int i = 0; i < de.length(); i++)
		 {
			if (getHead)
			 {
				if (BorK % 2 == 0)
				 {
					 temp = head1;
				 }
				else
				 {
					 temp = head2;
				 }
				 getHead = 0;
			 }
			 if (de[i] == '0')
			 {
				
				 temp = temp->leftNode;
			 }
			 else
			 {
				 temp = temp->rightNode;
			 }
			 if (!temp)break;
			 if (temp->RL != -1)
			 {
				 if (temp->RL == '@')
					 break;
				 getHead = 1;
				 re += temp->RL;
				 re += " ";
				 BorK++;
			 }
		 }
		 return re;
	 }
	 
 };

 //	//信道编码要求采用(7, 4)系统循环码, 其中, g(x) = x3 + x + 1，译码采用简化的译码表；
	//信道为BSC信道，p = 10 - 2
 string Channel_Encoding(string en)
 {
	string re;
	string en_e;
	int len = en.length() - en.length() % 4;
	for (int i = 0; i < len; i++)
	{
		en_e+=en[i];
	}
	char gx[4][8] = { {"1000101"} ,{"0100111"},{"0010110"},{"0001011"} };
	for (int i = 0; i < en_e.length(); i+=4)
	{
		for (int j = 0; j < 7; j++)
		{
			re += (char)((((int)gx[0][j] - 48) * en_e[i + 0] + ((int)gx[1][j] - 48) * en_e[i + 1] + 
				((int)gx[2][j] - 48) * en_e[i + 2] + ((int)gx[3][j] - 48) * en_e[i + 3]) % 2 + 48);
		}
	}
	 return re;
 }
 //伴随式构造函数
 string Sx(string e)
 {
	 char hx[4][8] = { {"1001110"},{"0100111"},{"0011101"} };
	 string sx;
	 int tmp;
	 for (int i = 0; i < 3;i++ )
	 {
		 tmp = 0;
		 for (int j = 0; j < 7; j++)
		 {
			 tmp += ((int)hx[i][j] - 48) * ((int)e[j] - 48);
		 }
		 sx += char(tmp % 2 + 48);
	 }
	 return sx;
 }
 string Channel_Decoding(string de)
 {
	 string re;
	 //监督矩阵
	 char hx[4][8] = { {"1001110"},{"0100111"},{"0011101"} };
	 //错误图样
	 char ex[8][8] = { {"0000001"},{"0000010"},{"0000100"},{"0001000"},{"0010000"},{"0100000"},{"1000000"},{"0000000"} };
	 //构造错误图样
	 string sx;//伴随式
	 for (int m = 0; m < de.length(); m+=7)
	 {
		 int tmp;
		 for (int i = 0; i < 3; i++)
		 {
			 tmp = 0;
			 for (int j = 0; j < 7; j++)
			 {
				 tmp += ((int)hx[i][j] - 48) * ((int)de[m+j] - 48);
			 }
			 sx += char(tmp % 2 + 48);
		 }
		 for (int i = 0; i < 8; i++)
		 {
			 if (sx == Sx(ex[i]))
			 {
				 for (int j = 0; j < 7; j++)
				 {
					 if ((ex[i][j] == '0' && de[m+j] == '0') || (ex[i][j] == '1' && de[m+j] == '1'))
					 {
						 re += '0';
					 }
					 else
					 {
						 re += '1';
					 }
				 }
			 }
		 }
		 sx.clear();
	 }
	 string result;
	 for (int n = 0; n < re.length(); n++)
	 {
		 if (n % 7 < 4)
		 {
			 result += re[n];
		 }
	 }
	 return result;
 }
