#pragma once
#include "Being.h"
#include "Queue.h"
#include "Monster.h"
#include "Gost.h"
#include "Dragon.h"
#include <ctime>

class Fight
{
private:
	int luck;
public:
	Fight();
	void Who_Is(Monster* obj);
	void Make_Fight(Monster* monstr, Queue& obj2);
	void Monster_Attack(Monster* monstr, Queue& obj2);
	void Spartans_Attack(Monster* monstr, Queue& obj2);
	int Get_luck();

};



