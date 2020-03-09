#include "Hospital.h"
#include <ctime>

Hospital::Hospital()
{
	hosplevel = 0;
	status = false;
}

bool Hospital::StausTrue()
{
	status = true;
	return status;
}

bool Hospital::StatusFalse()
{
	status = false;
	return status;
}

void Hospital::LevelUp()
{
	if (hosplevel < 0)
	{
		cout << "Hospital level cannot be < 0\n";
		return;
	}
	else if (hosplevel > 5)
	{
		cout << "Hospital level cannot be > 5\n";
		return;
	}
	hosplevel++;
}

void Hospital::HospitalIn(Queue& obj)
{
	if (hosplevel == 0)
	{
		cout << "\n--You don`t have Hospital yet!\n--Build at least one level of it first\n";
		system("PAUSE");
		return;
	}
	if (!status)
	{
		cout << "\n--You can use Hospital one time between fights\n";
		cout << "--Go fight to use Hospital again\n ";
		system("PAUSE");
		return;
	}
	if (hosplevel == 1)
	{
		cout << "\n---You have First hospital level\n";
		int shance = rand() % 4;
		if (!shance)
		{
			cout << "---Your Spartans will restore they health" << endl;
			obj.RestoreHealth(15);
			StatusFalse();
			system("PAUSE");
			return;
		}
		else
		{
			cout << "You will get chanse another time\n";
			StatusFalse();
			system("PAUSE");
			return;
		}
		
	}
	if (hosplevel == 2)
	{

		cout << "\n---You have Second hospital level\n";
		cout << "---Your Spartans will get full health with 50% of chanse" << endl;
		int chanse = rand() % 2;
		if (!chanse)
		{
			cout << "You have health your Spartans!\n";
			obj.RestoreHealth(40);
			StatusFalse();
			system("PAUSE");
			return;
		}
		else
		{
			cout << "---You will get luck another time\n";
			StatusFalse();
			system("PAUSE");
			return;
		}
		
	}
	else if (hosplevel == 3)
	{
		cout << "\n---You have Third hospital level\n";
		cout << "---your Spartans will get health with 75% of chanse\n";
		int chanse = rand() % 100;
		if (chanse < 75)
		{
			cout << "---You have heal your Spartans!\n";
			obj.RestoreHealth(70);
			StatusFalse();
			system("PAUSE");
			return;
		}
		else
		{
			cout << "---You will have your chanse again\n";
			StatusFalse();
			system("PAUSE");
			return;
		}
	}
	else if (hosplevel == 4)
	{
		cout << "\n---You have Four hospital level\n";
		cout << "---your Spartans will get health with 50% of chanse all of your Spartans\n";
		int chanse = rand() % 2;
		if (!chanse)
		{
			cout << "You have heal all your Spartans!\n";
			obj.RestoreHealth(300);
			StatusFalse();
			system("PAUSE");
			return;
		}
		else
		{
			cout << "You will have your chanse again\n";
			StatusFalse();
			system("PAUSE");
			return;
		}
	}
	else if (hosplevel == 5)
	{
		cout << "\n---You have Fifth hospital level\n";
		cout << "---your Spartans will get health with 80% of chanse all of your Spartans and add Moral 5 points more\n";
		int chanse = rand() % 100;
		if (chanse < 80)
		{
			cout << "You have heal all your Spartans!\n";
			obj.RestoreHealth(300);
			obj.AddMoral(5);
			StatusFalse();
			system("PAUSE");
			return;
		}
		else
		{
			cout << "You will have your chanse again\n";
			StatusFalse();
			system("PAUSE");
			return;
		}
	}
	else
	{
		cout << "Wrong level of Hospital!\n";
		return;
	}
}
