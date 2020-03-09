#pragma once
class Monster
{
public:
	int health;
	int damage;
	int moral;
public:
	virtual int Atack() = 0;
	virtual void Less_Health(int) = 0;
	virtual int Get_Health() = 0;
	virtual void Show() = 0;
	virtual ~Monster();
};

