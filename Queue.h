#pragma once
#include <iostream>
#include "Being.h"
using namespace std;
class Queue
{
private:
	Being* mass;
	int count; //���������� ������� ��������� � ������� � ��������� ������
	int size;  //����� ������ �������
public:
	Queue();
	~Queue();
	bool Isempty();
	bool Isfool();
	int Queuequantity();
	bool Additem(const Being& item);
	bool Delitem(int numb);
	void Show();
	void RestoreHealth(int howmany);
	int ShowHealth();
	void AddMoral(int);
	void LessMoral(int);
	void AddHealth(int add); // �������� �������� �� �������
	void LessHealth(int less); //��������� �������� ��� ���, ��� � �������
	void Injure(int less);
	void GostInjure(int);
	int Attack();
	
};

