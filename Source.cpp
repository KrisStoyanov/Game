#include <iostream>
#include "Console.h"
#include <thread>
#include <windows.h>
using namespace std;

int main()
{	bool gamerunning = false;
	bool bossISspawned = false;
	cout << "Welcome to my new game!" << endl;
	cout << "Please press a number between 1 and 4." << endl;
	cout << "1.Start game" << endl;
	cout << "2.Load saved game" << endl;
	cout << "3.Options" << endl;
	cout << "4.Exit" << endl;
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 1: {gamerunning = true; break; }
	case 2: //in progress
	case 3: {}
	case 4: {system("cls"); cout << "Thank you for playing !" << endl; Sleep(2000); return 0; break; }
	}
	Console console;
	console.ReplaceMap(1);
	Player  P(Type::Player,  9,   6);
	//Fatman F1(Type::Fatman, 15,  15);
	//Fatman F2(Type::Fatman,  4,  22);
	//Fatman F3(Type::Fatman, 14,  55);
	//Fatman F4(Type::Fatman, 15,  75);
	//Boss    B(Type::Boss  , 10, 100);
	console.add(&P );
	//console.add(&F1);
	//console.add(&F2);
	//console.add(&F3);
	//console.add(&F4);
	for (int i = 0; i < console.getSize(); i++)
	{
		console.getAt(i)->Spawn();
	}
	bool map_ = false;
	while (gamerunning)
	{

		system("cls");
		cout << "Your Health: " << P.getHP() << endl;
		cout << endl;
		cout << endl;
		console.PrintMap();
		cout << endl;
		cout << endl;
		cout << "$ " << Coins << endl;
		if (!P.isAlive())
		{
			gamerunning = false;
			break;
		}
		if (GetAsyncKeyState(0x45))
		{
			P.Interact();
		}
		if (GetAsyncKeyState(0x41))//attack
		{
			for (int i = 0; i < console.getSize(); i++)
			{
				P.Attack(*console.getAt(i));
			}
		}
		if (GetAsyncKeyState(VK_UP))
		{
			P.Move(-1, 0);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			P.Move(1, 0);
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			P.Move(0, -1);
			//P.Move(0, -1);
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			P.Move(0, 1);
			//P.Move(0, 1);
		}
		for (int i = 1; i < console.getSize(); i++)
		{
			if (console.getAt(i)->isAlive() == false)
			{
				console.removeAt(i);
			}
		}
		for (int i = 1; i < console.getSize(); i++)
		{
			  console.getAt(i)->HuntPlayer(P);
		}
		if (console.getSize() == 1 && bossISspawned == false)
		{

			bossISspawned = true;
			//console.add(&B);
		}
		/*if (console.getSize() == 1)
		{
			gamerunning = false;
			cout << "Level Completed!" << endl;
		}
		Sleep(16);*/
	}
	system("pause");
}