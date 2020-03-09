#include "Fight.h"

Fight::Fight()
{
	luck = 0;
}

void Fight::Who_Is(Monster* obj)
{
	if (typeid(*obj) == typeid(Dragon))
		cout << "Dragon ";
	else if (typeid(*obj) == typeid(Gost))
		cout << "Gost ";
	else
		cout << "Spartans ";
}


void Fight::Make_Fight(Monster* monstr, Queue& spartan)//этот переделал вроде
{
	cout << "\nLet`s fight begin!\n";
	luck = Get_luck();
	if (luck)
	{
		cout << "You are lucky today! ";
		cout << "Spartans will atack first!\n";
	}
	else
	{
		cout << "Luck is not on your side today ";
		Who_Is(monstr);
		cout << " will atack first!\n";
	}
	while (true)
	{
		if (luck)
		{
			Spartans_Attack(monstr, spartan);
			if (monstr->Get_Health() <= 0)
			{
				Who_Is(monstr);//показывает имя монстра
				cout << "is dead\n";
				break;
			}

			Monster_Attack(monstr, spartan);
			if (spartan.Queuequantity())//нужно менять методы на методы, которые есть в очереди
			{
				cout << "Spartans is dead\n";
				break;
			}
		}
		else
		{

			Monster_Attack(monstr, spartan);
			if (spartan.Queuequantity())
			{
				cout << "Spartans is dead\n";
				break;
			}
			Spartans_Attack(monstr, spartan);
			if (monstr->Get_Health() <= 0)
			{
				Who_Is(monstr);//показывает имя монстра
				cout << "is dead\n";
				break;
			}
		}

	}


}

void Fight::Monster_Attack(Monster* monstr, Queue& spartans)
{
	cout << "Now ";
	Who_Is(monstr); 
	cout << " attack!\n";
	system("PAUSE");
	spartans->Less_Health(monstr->Atack());

	
	cout << "Spartans has a ";
	spartans->Show();
	cout << "\nNow ";
	system("Pause");
}

void Fight::Spartans_Attack(Monster* monstr, Queue& spartans)
{
	
	cout << "Spartans attack \n";
	monstr->Less_Health(spartans->Atack());

	Who_Is(monstr);
	cout << " has a ";
	monstr->Show();
}

int Fight::Get_luck()
{
	luck = rand() % 2;
	return luck;
}
