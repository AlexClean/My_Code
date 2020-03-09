#pragma once
#include <iostream>
#include "Being.h"
using namespace std;
class Queue
{
private:
	Being* mass;
	int count; //количество видимых элементов в очереди в настоящий момент
	int size;  //общий размер очереди
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
	void AddHealth(int add); // добавить здоровья из очереди
	void LessHealth(int less); //уменьшить здоровье для тех, кто в очереди
	void Injure(int less);
	void GostInjure(int);
	int Attack();
	
};

