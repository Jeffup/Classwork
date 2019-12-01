#include <iostream>
#include <fstream>
#include "Coding.h"
#include <time.h>
#include<cstdlib>
using namespace  std;


int main()
{

	ifstream fin;
	ofstream fout;
	string str1;
	string str2;
	string tmp;
	////算术编码
	fin.open("in.txt");
	if (!fin.is_open())
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}
	fin >> tmp;
	str1= Arithmetic_coding((char*)tmp.c_str(), '0', '1', 0.25, 0.75);
	fin >> tmp;
	str2= Arithmetic_coding((char*)tmp.c_str(), '0', '1', 0.25, 0.75);
	fin.close();
	ofstream foutn;
	fout.open("out.txt");
	if (!fout.is_open())
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}
	fout << str1 << endl;
	fout << str2 << endl;
	fout << Arithmetic_decoding((char*)str1.c_str(), '0', '1', 0.25, 0.75) << endl;
	fout << Arithmetic_decoding((char*)str2.c_str(), '0', '1', 0.25, 0.75) << endl;
	fout.close();
	//唯一可译码
	fin.open("Judgein.txt");
	if (!fin.is_open())
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}
	vector<string>vec1;
	vector<string>vec2;
	vector<string>* vec_tmp = &vec1;
	while(fin)
	{
		fin >> tmp;
		if (tmp != "$")
		{
			vec_tmp->push_back(tmp);
		}
		else
		{
			vec_tmp = &vec2;
		}
	}
	fin.close();
	fout.open("Judgeout.txt");
	if (!fout.is_open())
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}
	if (Judge_Only_Decoding(vec1))
	{
		fout << "是" << endl;
	}
	else
	{
		fout << "否" << endl;
	}
	if (Judge_Only_Decoding(vec2,3))
	{
		fout << "是" << endl;
	}
	else
	{
		fout << "否" << endl;
	}
	fout.close();
	
	fin.open("RLin.txt");
	if (!fin.is_open())
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}
	fin >> tmp;
	fin.close();
	//	1.游程编码结果，
//	2.类MH编码结果，
//	3.加密编码结果 
//	4. 信道编码结果
//	5. 模拟接收串，
//	6.信道译码结果，
//	7.解密编码结果 
//	8. 类MH译码结果
//	9. 游程译码结果
	str1 = RL_Encoding(tmp);
	MH_Coding mh("MHina.txt", "MHinb.txt");
	str2 = mh.MH_Encoding(str1);
	fout.open("RLout.txt");
	if (!fout.is_open())
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}
	fout << "游程编码：" << str1 << endl;
	fout << "MH编码：" << str2 << endl;
	str1 = Caesar_Encoding(str2);
	fout << "加密：" << str1 << endl;
	str2 = Channel_Encoding(str1);
	fout << "信道编码：" << str2 << endl;
	
	//信道传输：
	for (int tmp = 0; tmp < str2.length(); tmp++)
	{
		if (rand() % 100 == 1)//错误概率
		{
			if (str2[tmp] == '1')
			{
				str2[tmp] = '0';
			}
			else
			{
				str2[tmp] = '1';
			}
		}
	}
	fout << "信道传输：" << str2 << endl;
	str1 = Channel_Decoding(str2);
	fout << "信道译码：" << str1 << endl;
	str2 = Caesar_Decoding(str1);
	fout << "解密：" << str2 << endl;
	str1 = mh.MH_Decoding(str2);
	fout << "MH译码：" << str1 << endl;
	str2 = RL_Decoding(str1);
	fout << "游程译码：" <<str2<< endl;
	fout.close();
	return 0;
}
