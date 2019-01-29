// serialize.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
	Person(char* name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}
	void showInfo()
	{
		cout << name << " " << age << endl;
	}
public:
	char name[10]{ 0 };
	int age = 0;
};
//二进制文件 进行写
void WriteBinaryFile()
{
	ofstream file("./binary.txt", ios::out | ios::binary);
	if (!file.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	Person p1("Lay1", 11);
	Person p2("Lay2", 2);
	Person p3("Lay3", 151);
	Person p4("Lay4", 5);
	Person p5("Lay5", 9);
	file.write((char*)&p1, sizeof(p1));
	file.write((char*)&p2, sizeof(p2));
	file.write((char*)&p3, sizeof(p3));
	file.write((char*)&p4, sizeof(p4));
	file.write((char*)&p5, sizeof(p5));

	file.close();
}
//二进制文件 进行读
void ReadBinaryFile()
{
	ifstream file("./binary.txt", ios::in | ios::binary);
	if (!file.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	//开辟一块空间 存放读取的数据
	char* temp = new char[sizeof(Person)];
	//或者 Person p;开辟的空间肯定合适

	//将数据读入的 temp对应的空间
	while (file.read(temp, sizeof(Person)))
	{
		Person p = *(Person*)(temp);
		p.showInfo();
	}
	file.close();
}


//写文件
void WriteFile()
{
	ofstream file("./text.txt", ios::out);
	if (!file.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	file << "姓名：laymond" << endl;
	file << "年龄：18" << endl;
	file.close();
	return;
}
//读文件
void ReadFile()
{
	ifstream file("./text.txt", ios::in);
	if (!file.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	char temp[1024] = { 0 };
	//读取文件3种方式
	//1、read  file.eof() 作为判断条件 会慢一拍
	while (file >> temp)
		//while (!file.eof())
	{
		//file.read(temp, 1024); //这样会读取到\n
		//cout << temp

		// >>按行读取，不会读换行符
		cout << temp << endl;
	}

	//2、get 一个一个字符的读取
	//char c;
	//while ( (c=file.get()) != EOF )
	//{
	//	cout << c;
	//}

	//3、一行一样读取 getline 会把\n 舍弃掉....
	//while (file.getline(temp,1024))
	//{
	//	cout << temp << endl;
	//}
	file.close();
}


int main(int argc, char *argv[])
{
	//演示读写 字符文件
	//WriteFile();
	ReadFile();

	//演示序列化与反序列化 读写 二进制文件
	//WriteBinaryFile();
	//ReadBinaryFile();

	getchar();
	return EXIT_SUCCESS;
}
