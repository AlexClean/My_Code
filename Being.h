#pragma once
#include <iostream>
using namespace std;
class Being
{
private:
	int type;
	int health;
	int moral;
	int strenght;
public:
	Being();
	Being(int typ);
	int GetType();
	void Restore();
	void AddHealth(int add);
	void AddMoral(int);
	void AddStrenght(int);
	void LessMoral(int);
	void LessHealth(int);
	void Show();
	int GetHelth();
	int Attack();//
	//Being& operator=(Being& obj);
};

