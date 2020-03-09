#include "Being.h" 

Being::Being()
{
	type = 1;
	health = 10;
	moral = 0;
	strenght = 2;
}

Being::Being(int typ)
{
	if (typ == 6)
	{
		type = typ; //тип 6 это Дракон
		health = 100;
		moral = 5;
		strenght = 50;
	}
	else if (typ == 7)
	{
		type = typ; //тип 7 это призрак
		health = 100;
		moral = 5;
		strenght = 5;
	}
	else if (typ == 1)
	{
		type = typ; //спартанец 1-го уровня
		health = 10;
		moral = 0;
		strenght = 2;
	}
	else if (typ == 2)
	{
		type = typ;//спартанец второго уровня
		health = 15;
		moral = 0;
		strenght = 4;
	}
	else if (typ == 3)
	{
		type = typ; //спартанец третьего уровня
		health = 25;
		moral = 1;
		strenght = 6;
	}
	else if (typ == 4)
	{
		type = typ; //спартанец 4-го уровня
		health = 50;
		moral = 4;
		strenght = 10;
	}
	else if (typ == 5)
	{
		type = typ; //спартанец 5-го уровня
		health = 60;
		moral = 5;
		strenght = 15;
	}
	else
	{
		cout << "Wrong type of Being\n";
		return;
	}
}

int Being::GetType()
{
	return type;
}

void Being::Restore()
{
	if (type == 6)
	{
		health = 100;
		moral = 5;
		strenght = 50;
	}
	else if (type == 7)
	{
		health = 100;
		moral = 5;
		strenght = 5;
	}
	else if(type == 1)
	{
		health = 10;
		moral = 0;
		strenght = 2;
	}
	else if (type == 2)
	{
		type = 2;
		health = 15;
		moral = 0;
		strenght = 4;
	}
	else if (type == 3)
	{
		type = 3;
		health = 25;
		moral = 1;
		strenght = 6;
	}
	else if (type == 4)
	{
		type = 4;
		health = 50;
		moral = 4;
		strenght = 10;
	}
	else if (type == 5)
	{
		type = 5;
		health = 60;
		moral = 5;
		strenght = 15;
	}
	else
	{
		cout << "Wrong type of Being\n";
		return;
	}
	
}

void Being::AddHealth(int add)
{
	health += add;
}

void Being::AddMoral(int add)
{
	moral += add;
}

void Being::AddStrenght(int add)
{
	strenght += add;
}

void Being::LessMoral(int less)
{
	moral -= less;
}

void Being::LessHealth(int less)
{
	if (less > GetHelth())
		health = 0;
	else
		health -= less;
}

void Being::Show()
{
	cout << "health is " << health << "\t";
	cout << "moral is " << moral << "\t";
	cout << "strenght is " << strenght << endl;
}

int Being::GetHelth()
{
	return health;
}

int Being::Attack()
{
	int attack;
	attack = strenght + moral;
	return attack;
}

//Being& Being::operator=(Being& obj)
//{
//	type = obj.type;
//	health = obj.health;
//	moral = obj.moral;
//	strenght = obj.strenght;
//	return *this;
//}
