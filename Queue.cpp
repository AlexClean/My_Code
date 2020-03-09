#include "Queue.h"

Queue::Queue()
{
	size = 300;
	mass = new Being[size];
	count = 300;
}

Queue::~Queue()
{
	if (mass != nullptr)
		delete[]mass;
}

bool Queue::Isempty()
{
	if (count == 0)
		return true;
	else
		return false;
}

bool Queue::Isfool()
{
	if (count == size)
		return true;
	else
		return false;
	
}

int Queue::Queuequantity()
{
	return count;
}

bool Queue::Additem(const Being& item)
{
	if (Isfool())
		return false;
	else
	{
		int position = Queuequantity();
		mass[position] = item;
		count++;
		return true;
	}
	
}

//удаляет заданное количество элементов массива из очереди,начиная с начала
bool Queue::Delitem(int numb)
{
	if (Isempty())
		return false;
	else
	{
		for (int j = 0; j < numb; j++)
		{
			for (int i = 1; i < count; i++)
			{
				mass[i - 1] = mass[i];
			}
			count--;//мы просто уменьшаем переменную count, но в массиве они реально есть
		}
		return true;
	}
}

void Queue::Show()
{
	for (int i = 0; i < count; i++)
	{
		mass[i].Show();
	}
	
}

//восстанавливает существ в зависимости от их уровня и типа до исходного состояния
void Queue::RestoreHealth(int howmany)
{
	if (howmany > size)
		howmany = size;
	if (howmany < 0)
	{
		cout << "Wrong value in RestoreHealth, it cannot be < 0\n";
		return;
	}
	for (int i = 0; i < howmany; i++)
	{
		mass[i].Restore();
	}
}

int Queue::ShowHealth()
{
	return mass[1].GetHelth();
}

void Queue::AddMoral(int add)
{
	for (int i = 0; i < count; i++)
	{
		mass[i].AddMoral(add);
	}
}

void Queue::LessMoral(int less)
{
	for (int i = 0; i < count; i++)
	{
		mass[i].LessMoral(less);
	}
}
//добавляет здоровья всем(это для больницы)
void Queue::AddHealth(int add)
{
	for (int i = 0; i < count; i++)
	{
		mass[i].AddHealth(add);
	}
}
//уменьшает здоровье первого элемента в очереди
void Queue::LessHealth(int less)
{
	//проверка,чтобы здоровье не уходило в минус
	if (less > mass[0].GetHelth())
		mass[0].LessHealth(mass[0].GetHelth());
	else
		mass[0].LessHealth(less);
	//если урон забрал здоровья до 0, то убираем бойца из массива сразу
	if (mass[0].GetHelth() == 0)
		Delitem(1);
}
//Функция, которая забирает здоровья у солдат пропорционально урону и с учётом остатков
void Queue::Injure(int less)
{
	int rest = 0;
	int sum = 0;
	int i;
	for (i = 0; i < count; i++)
	{
		sum = sum + mass[i].GetHelth();
		if (sum >= less)
			break;
	}
	if (sum == less)
		i++;
	 //добавляем единицу, чтобы удаляло правильное количество
	
	if (sum > less)
	{
		sum = sum - mass[i].GetHelth();
	}
	rest = less - sum; //вычисляем остаток здоровья, который отнимется у оставшегося бойца
	//количество бойцов, которые погибнут это i
	Delitem(i);
	if (rest == 0)
		return;
	LessHealth(rest);
}

void Queue::GostInjure(int less)
{
	int size = Queuequantity();
	for (int i = 0; i < size; i++)
	{
		if (less > mass[i].GetHelth())
			mass[i].LessHealth(mass[i].GetHelth());
		else
			mass[i].LessHealth(less);
	}
	int j = 0; // считает количество солдат с здоровьем 0, чтобы передать в фукнцию DelItem()
	for (int i = 0; i < size; i++)
	{
		if (mass[i].GetHelth() == 0)
		{
			j++;
		}
	}
	Delitem(j);
}

int Queue::Attack()
{
	int attack = 0;
	for (int i = 0; i < 3; i++)
	{
		attack = attack + mass[i].Attack();
	}
	return attack;
}


