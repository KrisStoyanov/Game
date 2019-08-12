#include <Windows.h>
#include <iostream>
#include "Console.h"
using namespace std;
int main()
{
	Player P(Type::Player, 9, 9);
	Fatman F1(Type::Fatman, 15, 15);
	Fatman F2(Type::Fatman, 4, 22);
	Fatman F3(Type::Fatman, 14, 36);
	Fatman F4(Type::Fatman, 15, 15);
	Boss B(Type::Boss, 10, 100);
	Console console;
	bool gamerunning = true;
	while (gamerunning)
	{	
		system("cls");
		cout << "Your Health: " << P.getHP() << endl;;
		/*for (int i = 0; i < characterHP/10; i++)
		{
			cout << "% ";
		}*/

		cout << endl;
		cout << endl;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 120; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;
		cout << "Coins : " << Coins << endl;
		system("pause>nul");
		if (GetAsyncKeyState(0x45))
		{
			P.Interact();
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
			P.Move(0,-1);
		}
		if (GetAsyncKeyState(VK_RIGHT)) 
		{
			P.Move(0, 1);
		}
		if (GetAsyncKeyState(0x41))
		{
			for (int i = 0; i < console.getSize(); i++)
			{
				P.Attack(*console.getAt(i));
			}
		}
		if (!P.isAlive)
		{
			gamerunning = false;
		}

		console.add(&P);
		console.add(&F1);
		console.add(&F2);
		console.add(&F3);
		console.add(&F4);
		for (int i = 1; i < console.getSize(); i++)
		{
			console.getAt(i)->HuntPlayer(P);
		}
		if (console.getSize()==2)
		{
			console.add(&B);
		}
	}
		system("pause");
}

