#include "Gost.h"
#include <iostream>
using std::cout;
using std::endl;

Gost::Gost()
{
	health = 100;
	damage = 8;
	moral = 2;
}

int Gost::Atack()
{
	return damage + moral;
}

void Gost::Less_Health(int less)
{
	health -= less;
}

int Gost::Get_Health()
{
	return health;
}

void Gost::Show()
{
	cout << "health is " << health << "\t";
	cout << "moral is " << moral << "\t";
	cout << "strenght is " << damage << endl;
}