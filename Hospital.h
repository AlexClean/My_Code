#pragma once
#include "Queue.h"
#include <iostream>

class Hospital
{
	int hosplevel;
	bool status;
public:
	Hospital();
	bool StausTrue();
	bool StatusFalse();
	void LevelUp();
	void HospitalIn(Queue& obj);
};

