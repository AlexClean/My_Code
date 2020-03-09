#pragma once
#include "Monster.h"
class Dragon :
	public Monster
{
public:
	Dragon();
	virtual int Atack();
	virtual void Less_Health(int less);
	virtual int Get_Health();
	virtual void Show();

};

