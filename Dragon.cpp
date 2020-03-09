#include "Dragon.h"
#include <iostream>
using std::cout;
using std::endl;
Dragon::Dragon()
{
	health = 100;
	damage = 50;
	moral = 2;
}

int Dragon::Atack()
{
	return damage + moral;
}

void Dragon::Less_Health(int less)
{
	health -= less;
}

int Dragon::Get_Health()
{
	return health;
}

void Dragon::Show()
{
	cout << "health is " << health << "\t";
	cout << "moral is " << moral << "\t";
	cout << "strenght is " << damage << endl;
}