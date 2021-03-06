// lisan.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include <iostream>
#include <string>
#include <cmath>
#define x 6
using namespace std;
int j;
int distinct(char sign, int next, int result)   //判断运算符号
{
	switch (sign)
	{
	case '&':
		return (result == 1 && next == 1) * 2 - 1;  //T为1，F为-1
		break;
	case '|':
		return (result == 1 || next == 1) * 2 - 1;
		break;
	case '->':
		return (result != 1 || next != -1) * 2 - 1;
		break;
	case '<->':
		return (result == next) * 2 - 1;
		break;
	}
	return next;
}

void GetF(string f, char* n, int num)
{
	int k = 0;
	for (int i = 0; i < f.size(); i++)   //分离出命题变元，存入数组
	{
		if ((f.at(i) >= 'A' && f.at(i) <= 'Z') || (f.at(i) >= 'a' && f.at(i) <= 'z'))
		{
			n[k++] = f.at(i);
		}
		if (k == num) break;
	}
}

void Tips()
{
	cout << "  利用真值表法求主析取范式和主合取范式    " << endl;
	cout << endl;
	cout << "  请以" << endl;
	cout << "  ! 表示否定" << endl;
	cout << "  | 表示析取" << endl;
	cout << "  & 表示合取" << endl;
	cout << "  -> 表示条件" << endl;
	cout << "  <->表示双条件" << endl;
	cout << " " << endl;
	cout << "  请输入变元数量 " << endl;
	cout << " " << endl;
}

void TruthTable(int num, char* n, string f, int* result, int a[][x])
{
	cout << "真值表如下： " << endl;
	for (int i = 0; i < num; i++)     //输出命题变元
	{
		cout << "\t" << n[i] << "   ";
	}
	cout << "A" << endl;
	for (i = 0; i < (int)pow(2.0, num); i++)  //i为真值表对应列数
	{
		for (j = 0; j < num; j++)           //循环得出每一列对应变元取值
		{
			int m = (int)pow(2.0, j);
			a[i][j] = (i / m % 2) * 2 - 1;
		}
		char sign = ' ';                    //初始化符号变量
		int next = 1;                         //初始化迭代子
		for (j = 0; j < f.size(); j++)       //循环得到第i列的结果
		{
			if (f.at(j) == '!')
			{
				next = -1;
			}
			else if (f.at(j) != '!'&&f.at(j) != '&'&&f.at(j) != '|'&&f.at(j) != '-'&&f.at(j) != '>')
			{
				for (int k = 0; k < num; k++)
				{
					if (f.at(j) == n[k])
					{
						next = next * a[i][k];          //变元取反则为-1
						result[i] = distinct(sign, next, result[i]);  //若遍历至式子的左变元，sign为' '则result与next一致；若sign已有实义则计算公式
						next = 1;
					}
				}
			}
			else
			{
				sign = f.at(j);//读取符号
			}
		}
		for (j = 0; j < num; j++)
		{
			cout << "\t";
			if (a[i][j] == -1)
				cout << "F   ";  //变元的真值
			if (a[i][j] == 1)
				cout << "T   ";
		}
		if (result[i] == 1)
			cout << "T" << endl;   //A的真值
		if (result[i] == -1)
			cout << "F" << endl;
	}
}

void Result(string f, int* result, int num, char* n, int a[][x])
{
	string s[2];  //存储范式
	s[0] = ' ';
	s[1] = s[0];
	for (int i = 0; i < (int)pow(2.0, num); i++)
	{
		if (result[i] == 1)  //主析取
		{
			if (s[0] != " ")
				s[0] = s[0] + "∨";
			s[0] = s[0] + '(';
			for (int j = 0; j < num; j++)
			{
				if (a[i][j] == 1)  //为真
				{
					s[0] += n[j];
				}
				else
				{
					s[0] += "┓ ";
					s[0] += n[j];
				}
				if (j != num - 1)
				{
					s[0] += "∧";
				}
			}
			s[0] += ')';
		}
		else   //主合取
		{
			if (s[1] != " ")
				s[1] = s[1] + "∧";
			s[1] = s[1] + '(';
			for (int j = 0; j < num; j++)
			{
				if (a[i][j] == 1)
				{
					s[1] += n[j];
				}
				else
				{
					s[1] += "┓ ";
					s[1] += n[j];
				}
				if (j != num - 1)
				{
					s[1] += "∨";
				}
			}
			s[1] += ')';
		}
	}
	cout << "主析取范式为：" << s[0] << endl;
	cout << endl;
	cout << "主合取范式为：" << s[1] << endl;
	cout << " " << endl;
}

int main()
{
	int a[64][x] = { 0 };
	char n[x];
	int result[64] = { 0 };
	string formula;
	int num;
	Tips();
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		n[i] = ' ';
	}
	cout << " " << endl;
	cout << "请输入命题公式:" << endl;
	cout << " " << endl;
	cin >> formula;
	cout << " " << endl;
	GetF(formula, n, num);
	TruthTable(num, n, formula, result, a);
	Result(formula, result, num, n, a);
	return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
