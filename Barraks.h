#pragma once
#include "Queue.h"
#include <iostream>

class Barraks
{
	int barlevel;
	bool barstatus;
public:
	Barraks();
	bool StatusFalse();
	bool StatusTrue();
	void LevelUp();
	void BarrakIn(Queue& obj);
};

