#include "Gameplay.h"


Gameplay::Gameplay()
{
	Queue spartans;
	Barraks barraks;
	Hospital hospital;
	money = 0;
	temple = 0;
}

void Gameplay::Start()
{
	cout << "----This is a Game----" << endl;
	cout << "---You have to fight Dragon and stay alive!\n---For each fight you will have 100 coints" << endl;
	cout << "---Use it to build Barraks and Hospital\n";
	cout << "---You can create new spartans in the Barraks and heal them in the Hospital once between fights\n";
	cout << "\n---Press 1 to continue Game or 0 to exit ";
	bool choise;
	cin >> choise;
	if (choise)
	{
		Menu();
		return;
	}
	else if (choise == 0)
	{
		cout << "Game is over" << endl;
		system("PAUSE");
		return;
	}
	else
		return;
		
}

void Gameplay::Menu()
{
	cout << "\n---You have " << money << " coints " << endl;
	cout << "---To fight Dragon or Gost press 1" << endl;
	cout << "---to build Barraks or Hospital press 2 " << endl;
	cout << "---To go to Barraks or Hospital press 3 " << endl;
	cout << "--(To build 1 stage of Hospital or Barraks you need at least 100 coints)--" << endl;
	cout << "---To show you spartans conditions press 4 \n";
	cout << "---Press 0 to exit the game\n ";
	cout << "---Make choise---" << endl;
	int choise;
	cin >> choise;
	if (choise == 1)
	{
		cout << "---If you want to fight Dragon press 1 to fight Gost press 0\n";
		bool ch;
		cin >> ch;
		if (ch)
			money = money + FightDragon();
		else if (!ch)
			money = money + FightGost();
		else
		{
			cout << "\n---Wrong value\n";
			return;
		}
	}
	else if (choise == 2)
	{
		if (money < 100)
		{
			cout << "\n--You don`t have enought money";
			cout << "Go fight the Dragon first\n" << endl;
			system("PAUSE");
			Menu();
		}
		else
			Build();
	}
	else if (choise == 3)
	{

		cout << "\n---To the Barraks press 1 to Hospital press 0 ";
		bool ch;
		cin >> ch;
		if (ch)
			barraks.BarrakIn(spartans);
		else if (!ch)
			hospital.HospitalIn(spartans);
	}
	else if (choise == 4)
		spartans.Show();
	else if (choise == 0)
	{
		cout << "Game is over" << endl;
		system("PAUSE");
		return;
	}
		
	Menu();
}

int Gameplay::FightDragon()
{
	
	Being Dragon(6);
	int chanse = rand() % 2;//переменна€ котора€ определ€ет удачу дл€ подн€ти€ морали
	if (chanse)
	{
		cout << "\n---Dragon have seen your spartans and he is ready for fight!---\n";
		cout << "\n---He can kill more spartans!---\n";
		system("PAUSE");
		Dragon.AddMoral(10);
	}
	else
	{
		cout << "\n---Spartans meat a wizard!---\n";
		cout << "\n---He is geting up moral to your spartans!---\n";
		system("PAUSE");
		spartans.AddMoral(5);
	}
	
	int shanse = rand() % 2;//переменна€ определ€ет кто первый атакует
	if (shanse)
	{
		cout << "\n----Your spartans will attack first!----\n";
		while (spartans.Queuequantity())
		{
			cout << "--Spartans attacking! " << endl;
			cout << "--Spartans make " << spartans.Attack() << " injure!\n";
			Dragon.LessHealth(spartans.Attack());
			cout << "--Dragon has " << Dragon.GetHelth() << " of health " << endl;
			if (Dragon.GetHelth() <= 0)
			{
				cout << "\n---Dragon is death!---" << endl;
				barraks.StatusTrue();
				hospital.StausTrue();
				system("PAUSE");
				break;
			}
			cout << "--Dragon`s attack!" << endl;
			spartans.Injure(Dragon.Attack());
			cout << "--Dragon make " << Dragon.Attack() << " injure!\n";
			cout << "You have " << spartans.Queuequantity() << " spartans left " << endl;
			system("PAUSE");
		}
	}
	else
	{
		while (spartans.Queuequantity())
		{
			cout << "--Dragon`s attack!" << endl;
			spartans.Injure(Dragon.Attack());
			cout << "--Dragon make " << Dragon.Attack() << " injure!\n";
			cout << "You have " << spartans.Queuequantity() << " spartans left " << endl;
			if (spartans.Queuequantity())
			{
				cout << "--Spartans attacking! " << endl;
				cout << "--Spartans make " << spartans.Attack() << " injure!\n";
				Dragon.LessHealth(spartans.Attack());
				cout << "--Dragon has " << Dragon.GetHelth() << " of health " << endl;
			}
			if (Dragon.GetHelth() <= 0)
			{
				cout << "\n---Dragon is death!---" << endl;
				barraks.StatusTrue();
				hospital.StausTrue();
				system("PAUSE");
				break;
			}
			system("PAUSE");
		}
	}
	
	if (Dragon.GetHelth() <= 0)
	{
		cout << "\n---Congratulations!You have kill the Dragon!---" << endl;
		cout << "---!!You won 100 coints!!---" << endl;
		if (!chanse)
			spartans.LessMoral(5);
		system("PAUSE");
		return 100;
	}
	else if (!spartans.Queuequantity())
	{
		cout << "\n---You loose!All your spartans is dead---" << endl;
		if (chanse)
			Dragon.LessMoral(10);
		system("PAUSE");
		return 0;
	}
	else
	{
		cout << "Error!!" << endl;
		return -1;
	}
	
}
	
int Gameplay::FightGost()
{
	Being Gost(7);
	int chanse = rand() % 2;//кому добавит удачи на бой
	if (chanse)
	{
		cout << "\n---Gost have seen your spartans and he is ready for fight!---\n";
		cout << "\n---He can make more injure!---\n";
		system("PAUSE");
		Gost.AddMoral(5);
	}
	else
	{
		cout << "\n---There is a day and Gost is weak---\n";
		cout << "\n---You can defeat him easily---\n";
		system("PAUSE");
		spartans.AddMoral(5);
	}
	int shanse = rand() % 2;//кто первый пойдЄт в атаку
	if (shanse)
	{
		while (spartans.Queuequantity())
		{
			cout << "--Spartans attacking! " << endl;
			cout << "--Spartans make " << spartans.Attack() << " injure!\n";
			Gost.LessHealth(spartans.Attack());
			cout << "--Gost has " << Gost.GetHelth() << " of health " << endl;
			if (Gost.GetHelth() <= 0)
			{
				cout << "\n---Gost is death!---" << endl;
				hospital.StausTrue(); //открываем доступ в Ѕольницу
				barraks.StatusTrue(); //открываем доступ в Ѕарак
				system("PAUSE");
				break;
			}
			cout << "--Gost attack!" << endl;
			spartans.GostInjure(Gost.Attack());
			cout << "spartans condition is ";
			spartans.Show();
			cout << endl;
			cout << "--Gost make " << Gost.Attack() << " injure to each spartans!\n";
			cout << "You have " << spartans.Queuequantity() << " spartans left " << endl;
		}
		
	}
	else
	{
		while (spartans.Queuequantity())
		{
			cout << "--Gost attack!" << endl;
			spartans.GostInjure(Gost.Attack());
			cout << "spartans condition is ";
			spartans.Show();
			cout << endl;
			cout << "--Gost make " << Gost.Attack() << " injure to each spartans!\n";
			cout << "You have " << spartans.Queuequantity() << " spartans left " << endl;
			if (spartans.Queuequantity())
			{
				cout << "---Gost kill`s all your Spartans! " << endl;
				system("PAUSE");
				break;
			}
			cout << "--Spartans attacking! " << endl;
			cout << "--Spartans make " << spartans.Attack() << " injure!\n";
			Gost.LessHealth(spartans.Attack());
			cout << "--Gost has " << Gost.GetHelth() << " of health " << endl;
			if (Gost.GetHelth() <= 0)
			{
				cout << "\n---Gost is death!---" << endl;
				hospital.StausTrue();  //открываем доступ в Ѕольницу
				barraks.StatusTrue();  //открываем доступ в Ѕарак
				system("PAUSE");
				break;
			}
			system("PAUSE");
		}
	}
	
	if (Gost.GetHelth() <= 0)
	{
		cout << "\n---Congratulations!You have kill the Gost!---" << endl;
		cout << "---!!You won 100 coints!!---" << endl;
		if (!chanse)
			spartans.LessMoral(5);
		system("PAUSE");
		return 100;
	}
	else if (spartans.Isempty())
	{
		cout << "\n---You loose!All your spartans is dead---" << endl;
		if (chanse)
			Gost.LessMoral(5);
		system("PAUSE");
		return 0;
	}
	else
	{
		cout << "Error!!" << endl;
		return -1;
	}
	
}

void Gameplay::Build()
{
	cout << "----If you want to build Barraks press 1 if Hospital press 0---- ";
	int choise;
	cin >> choise;
	if (choise == 1)
		MakeBarraks();
	else if (choise == 0)
		MakeHospital(); 
	else
	{
		cout << "Wrong value\n";
		Build();
	}
		
}

void Gameplay::MakeHospital()
{
	if (money >= 100)
	{
		cout << "\n---You have " << money << " of money and you can build ";
		cout << "one stage of hospital " << endl;
		cout << "---Do you want to build it? y/n ";
		char choise;
		cin >> choise;
		if (choise == 'y')
		{
			cout << "\n---You just made one stage of Hospital" << endl;
			hospital.LevelUp();
			money = money - 100;
			system("PAUSE");
			return;
		}
		else if (choise == 'n')
		{
			cout << "\n---Do you want to go back to main Menu? y/n ";
			cin >> choise;
			if (choise == 'y')
				return;
			else
				MakeHospital();
		}
		else
		{
			cout << "\nWrong value ";
			MakeHospital();
		}
	}
	else
	{
		cout << "\n--You don`t have enought money to build--\n";
		system("PAUSE");
		return;
	}
}

void Gameplay::MakeBarraks()
{
	if (money >= 100)
	{
		cout << "\n---You have " << money << " of money ";
		cout << "and you can build 1 stage of barraks" << endl;
		cout << "---Do you want to build it? y/n ";
		char choise;
		cin >> choise;
		if (choise == 'y')
		{
			barraks.LevelUp();
			money = money - 100;
			cout << "\n----You just build 1 srage of barraks----" << endl;
			system("PAUSE");
			return;
		}
		else
			return;
	}
	else
	{
		cout << "\n--You don`t have enought money to build--\n";
		system("PAUSE");
		return;
	}
}

void Gameplay::GoodLuck()
{
	srand(time(0));
	int luck = rand() % 3;
		
}
