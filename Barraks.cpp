#include "Barraks.h"

Barraks::Barraks()
{
	barlevel = 0;
	barstatus = false;
}

bool Barraks::StatusFalse()
{
	barstatus = false;
	return barstatus;
}

bool Barraks::StatusTrue()
{
	barstatus = true;
	return barstatus;
}

void Barraks::LevelUp()
{
	if (barlevel < 0 && barlevel>5)
	{
		cout << "Cannot be level in Barraks more than 5 or less 0\n";
		return;
	}
	barlevel++;
}

void Barraks::BarrakIn(Queue& obj)
{
	if (barlevel == 0)
	{
		cout << "\n---You don`t have Barraks yet!\n--Build at least one stage first\n";
		return;
	}
	cout << "\n---You are in the Barraks!---\n";
	if (!barstatus)
	{
		cout << "---You alredy use your chanse to create spartans\n";
		cout << "---You have to fight Dragon first\n";
		system("PAUSE");
		return;
	}

	cout << "\n---Do you want to create a spartans? y/n ";
	char choise;
	cin >> choise;
	if (barlevel == 1)
	{
		if (choise == 'y')
		{
			Being spartan;
			int howmany = 0;
			for (int i = 0; i < 10; i++)
			{
				obj.Additem(spartan);
				howmany++;
				if (obj.Isfool())
					break;
			}
			cout << "\n----You have " << howmany << " more spartans level " << barlevel;
			cout << "\n----Now you are ready for the next fight!----\n";
			barstatus = false;
			system("PAUSE");
			return;
		}
		else
		{
			cout << "Okay!\n";
			return;
		}
	}
	else if (barlevel == 2)
	{
		if (choise == 'y')
		{
			Being spartan(2);
			int howmany = 0;
			for (int i = 0; i < 15; i++)
			{
				obj.Additem(spartan);
				howmany++;
				if (obj.Isfool())
					break;
			}
			cout << "\n----You have " << howmany << " more spartans level " << barlevel;
			cout << "\n----Now you are ready for the next fight!----\n";
			barstatus = false;
			system("PAUSE");
			return;
		}
		else
		{
			cout << "Okay!\n";
			return;
		}
	}
	else if (barlevel == 3)
	{
		if (choise == 'y')
		{
			Being spartan(3);
			int howmany = 0;
			for (int i = 0; i < 20; i++)
			{
				obj.Additem(spartan);
				howmany++;
				if (obj.Isfool())
					break;
			}
			cout << "\n----You have " << howmany << " more spartans level " << barlevel;
			cout << "\n----Now you are ready for the next fight!----\n";
			barstatus = false;
			system("PAUSE");
			return;
		}
		else
		{
			cout << "Okay!\n";
			return;
		}
	}
	else if (barlevel == 4)
	{
		if (choise == 'y')
		{
			Being spartan(4);
			int howmany = 0;
			for (int i = 0; i < 40; i++)
			{
				obj.Additem(spartan);
				howmany++;
				if (obj.Isfool())
					break;
			}
			cout << "\n----You have " << howmany << " more spartans level " << barlevel;
			cout << "\n----Now you are ready for the next fight!----\n";
			barstatus = false;
			system("PAUSE");
			return;
		}
		else
		{
			cout << "Okay!\n";
			return;
		}
	}
	else if (barlevel == 5)
	{
		if (choise == 'y')
		{
			Being spartan(5);
			int howmany = 0;
			for (int i = 0; i < 60; i++)
			{
				obj.Additem(spartan);
				howmany++;
				if (obj.Isfool())
					break;
			}
			cout << "\n----You have " << howmany << " more spartans level " << barlevel;
			cout << "\n----Now you are ready for the next fight!----\n";
			barstatus = false;
			system("PAUSE");
			return;
		}
		else
		{
			cout << "Okay!\n";
			return;
		}
	}
	else
	{
		cout << "There is no such stage for Barraks!\n";
		return;
	}

}
