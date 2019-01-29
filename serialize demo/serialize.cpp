// serialize.cpp : �������̨Ӧ�ó������ڵ㡣
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
//�������ļ� ����д
void WriteBinaryFile()
{
	ofstream file("./binary.txt", ios::out | ios::binary);
	if (!file.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
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
//�������ļ� ���ж�
void ReadBinaryFile()
{
	ifstream file("./binary.txt", ios::in | ios::binary);
	if (!file.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	//����һ��ռ� ��Ŷ�ȡ������
	char* temp = new char[sizeof(Person)];
	//���� Person p;���ٵĿռ�϶�����

	//�����ݶ���� temp��Ӧ�Ŀռ�
	while (file.read(temp, sizeof(Person)))
	{
		Person p = *(Person*)(temp);
		p.showInfo();
	}
	file.close();
}


//д�ļ�
void WriteFile()
{
	ofstream file("./text.txt", ios::out);
	if (!file.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	file << "������laymond" << endl;
	file << "���䣺18" << endl;
	file.close();
	return;
}
//���ļ�
void ReadFile()
{
	ifstream file("./text.txt", ios::in);
	if (!file.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	char temp[1024] = { 0 };
	//��ȡ�ļ�3�ַ�ʽ
	//1��read  file.eof() ��Ϊ�ж����� ����һ��
	while (file >> temp)
		//while (!file.eof())
	{
		//file.read(temp, 1024); //�������ȡ��\n
		//cout << temp

		// >>���ж�ȡ����������з�
		cout << temp << endl;
	}

	//2��get һ��һ���ַ��Ķ�ȡ
	//char c;
	//while ( (c=file.get()) != EOF )
	//{
	//	cout << c;
	//}

	//3��һ��һ����ȡ getline ���\n ������....
	//while (file.getline(temp,1024))
	//{
	//	cout << temp << endl;
	//}
	file.close();
}


int main(int argc, char *argv[])
{
	//��ʾ��д �ַ��ļ�
	//WriteFile();
	ReadFile();

	//��ʾ���л��뷴���л� ��д �������ļ�
	//WriteBinaryFile();
	//ReadBinaryFile();

	getchar();
	return EXIT_SUCCESS;
}
