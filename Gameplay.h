#pragma once
#include <iostream>
#include "Being.h"
#include "Queue.h"
#include "Barraks.h"
#include "Hospital.h"
#include <ctime>;
using namespace std;
class Gameplay
{
private:
	Queue spartans;
	Barraks barraks;
	Hospital hospital;
	int temple;
	int money;
public:
	Gameplay();
	void Start();
	void Menu();
	int FightDragon();
	int FightGost();
	void Build();
	void MakeHospital();
	void MakeBarraks();
	void GoodLuck();
};

