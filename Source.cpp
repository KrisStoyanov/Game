#include <iostream>
#include "Console.h"
#include <thread>
#include <windows.h>
#include <thread>
#include<fstream>
#include <conio.h>
using namespace std;
#define KEY_MOVE_UP 72
#define KEY_MOVE_DOWN 80
#define KEY_MOVE_LEFT 75
#define KEY_MOVE_RIGHT 77
#define KEY_INTERRACT 101
#define KEY_ATTACK 97
#define KEY_Q 113

void SpawnMenu();
int Choice();
int main()
{
	
	Console console;
	bool gamerunning = false;
	bool bossISspawned = false;
	bool QIsPressed = false;
	int ActiveMap = 1;
	bool MapHasToChange = true;
	SpawnMenu();
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
		case 1:
		{
			//return 1; break;
			gamerunning = true; break;
		}
		case 2:
		{
			system("cls");
			printf("Use Arrow Keys for mooving on the map\n For Interact press E\n For Attack press A");
			//return 0;
			break;
		}
		case 3:
		{
			system("cls");
			cout << "Thank you for playing !" << endl;
			Sleep(2000);
			//return 0;
			break;
		}
	}
	//if (Choice() == 1) ;
	//else return 0;
	while (gamerunning)
	{
		if(MapHasToChange)
		{ 
			switch (ActiveMap)
			{
			case 1:
				{
				console.ReplaceMap(1);
				Player player(9, 6);
				Fatman fat1(15, 15);
				Fatman fat2(4, 22);
				Fatman fat3(14, 55);
				Fatman fat4(15, 75);
				console.add(&player);
				console.add(&fat1);
				console.add(&fat2);
				console.add(&fat3);
				console.add(&fat4);
				MapHasToChange = false;
					break;
				}
			case 2:
				{
				MapHasToChange = false;
				console.ReplaceMap(2);
				Player player(9, 6);
				Fatman fat1(15, 15);
				Fatman fat2(4, 22);
				Fatman fat3(14, 55);
				Fatman fat4(15, 75);
				console.add(&player);
				console.add(&fat1);
				console.add(&fat2);
				console.add(&fat3);
				console.add(&fat4);
					break;
				}

			case 3:
				{
				MapHasToChange = false;
				console.ReplaceMap(3);
				Player player(9, 6);
				Fatman fat1(15, 15);
				Fatman fat2(4, 22);
				Fatman fat3(14, 55);
				Fatman fat4(15, 75);
				console.add(&player);
				console.add(&fat1);
				console.add(&fat2);
				console.add(&fat3);
				console.add(&fat4);
					break;
				}
			}
			for (int i = 0; i < console.getSize(); i++)
			{
				console.getAt(i)->Spawn();
			}
		}
		this_thread::sleep_for(16ms);
		system("cls");
		cout << "Your Health: " << console.getAt(0)->getHP() << endl;
		cout << endl;
		cout << endl;
		console.PrintMap();
		cout << endl;
		cout << endl;
		cout << "$ " << Coins << endl;
		if (!console.getAt(0)->isAlive())
		{
			gamerunning = false;
			break;
		}
			switch (_getch())
			{
				case KEY_MOVE_UP:
				{
					console.getAt(0)->Move(-1, 0);
					break;
				}
				case KEY_MOVE_DOWN:
				{
					console.getAt(0)->Move(1, 0);
					break;
				}
				case KEY_MOVE_LEFT:
				{
					console.getAt(0)->Move(0, -1);
					break;
				}
				case KEY_MOVE_RIGHT:
				{
					console.getAt(0)->Move(0, 1);
					break;
				}
				case KEY_ATTACK:
				{
					for (int i = 0; i < console.getSize(); i++)
					{
						console.getAt(0)->Attack(*console.getAt(i));
					}
					break;
				}
				case KEY_INTERRACT:
				{
					console.getAt(0)->Interact(); break;
				}
				case KEY_Q:
				{
					QIsPressed = true;
					gamerunning = false;
					system("cls");
				}
			}
	
		if(!QIsPressed)
		{
			console.ClearDeadEntities();
			console.EntitiesAttackPlayer();
			if (console.getSize() == 1 && bossISspawned == false)
			{
				switch (ActiveMap)
				{
					case 1:
					{
						Boss b(50, 50);
						console.add(&b);
						bossISspawned = true;
						break;
					}
					case 2:
					{
						Boss b(50, 50);
						console.add(&b);
						bossISspawned = true;
						break;
					}
					case 3:
					{
						Boss b(50, 50);
						console.add(&b);
						bossISspawned = true;
						break;
					}
				}
			}
			else if (console.getSize() == 1 && bossISspawned == true)
			{
				switch (ActiveMap)
				{
				case 1:
				{
					ActiveMap = 2;
					MapHasToChange = true;
					break;
				}
				case 2:
				{
					ActiveMap = 3;
					MapHasToChange = true;
					break;
				}
				case 3:
				{
					printf("Congratulations, you have beat my game!");
					this_thread::sleep_for(2000ms);
					break;
				}
				}
			}
		}
	}
	system("pause");

	
}


void SpawnMenu()
{
	cout << "Welcome to my new game!" << endl;
	cout << "Please press a number between 1 and 3." << endl;
	cout << "1.Start game" << endl;
	cout << "2.Options" << endl;
	cout << "3.Exit" << endl;
}


int Choice()
{
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		return 1; break;
	}
	case 2:
	{
		system("cls");
		printf("Use Arrow Keys for mooving on the map\n For Interact press E\n For Attack press A");
		return 0;
		break;
	}
	case 3:
	{
		system("cls");
		cout << "Thank you for playing !" << endl;
		Sleep(2000);
		return 0;
		break;
	}
	}
}