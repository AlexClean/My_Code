#pragma once
#include "Monster.h"
class Gost :
	public Monster
{
public:
	Gost();
	virtual int Atack();
	virtual void Less_Health(int less);
	virtual int Get_Health();
	virtual void Show();
};

