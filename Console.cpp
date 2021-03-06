#include "Console.h"
char map1[20][120] = {
	//0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
	 "#######################################################################################################################",//0corpses
	 "#                                                                                                                     #",//1_(*~*)_
	 "#                                                                                                                     #",//2 enemy1:    enemy2:                        
	 "#                                                                                                                     #",//3   @              _            (')        
	 "#         ##############            #################             ##################              ###############     #",//4 /[_]\         //(^)\\      /`"|`\\     
	 "#         #            #            #               #             #                #              |             #     #",//5  /`\         //(:":)\\    `   `  ``     
	 "#         #            #            #               #             #                #              |             #     #",//6splash hero2.0  hero1.0       _     ___      
	 "#         #            #            #               #             #                #              |             #     #",//7 ,^,    _ O |   _ O  /       /|\     O/       
	 "#         ##_______#####            ##_______########             ###_______########              ###############     #",//8<#*#>  | ||\+  | ||\x       (|#|)  0/|        
	 "#                                                                                                                     #",//9 `v`    `/`\    '/`\         \|/    /`\       
	 "#                                                                                                                     #",//0    boss1.0 boss 2.0_         '                                    _
	 "#                                                                                                                     #",//1    (^_^)|\      __|"|__ |) ______    ___                     ___ |"| _   /      ^ 
	 "#                                                                ###################               #         #        #",//2   |[# #]|-->   //\_|_/\\|  \KILL/   |HIT|  |     |)         |###|_|_/\\ /     <=|=> 
	 "#            #############           ###______#######            #                 |               #         #        #",//3   | [,] |/     || |+|  \|   \ME/    |   |  |     |          |###||+|  \X        |
	 "#            #           |           #              #            #                 |               #         #        #",//4    |   |         //`\\       \/      \_/  -+-    |          |___|/`\\           |
	 "#            #           |           #              #            #                 |               #         #        #",//5    |   |        ||   ||                    '                   ||   ||          |
	 "#            #           |           #              #            ###################               ###########        #",//6   ^^           ^^^   ^^^                  chest:              ^^^   ^^^
	 "#            #############           ################                                                                 #",//7   _    |\   (|) <=] [_] <=> {=}  |\_  ?     ___    <=]
	 "#                                                                                                                     #",//8  |H|   | )   |   |   |   |   |   |/   |     | |     | 
	 "#######################################################################################################################"};//9  V    |/    |   |   |   |   |        |     |_|     |     
char map2[20][120] = {
	//0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
	 "#######################################################################################################################",
	 "#                                     #                                        #                                      #",
	 "#                                     #                                        #                                      #",
	 "#                                     #                                        #                                      #",
	 "#                                     #                                        #                                      #",
	 "#                                     ##########################______##########                                      #",
	 "#                                     |                                                                               #",
	 "#                                     |                                                                               #",
	 "#                                     |                                                                               #",
	 "#                                     #######______#############################                                      #",
	 "#                                     #                                        #                                      #",
	 "#                                     #                                        #                                      #",
	 "#                                     #                                        #                                      #",
	 "#                                     #                                        #                                      #",
	 "#                                     #                                        #                                      #",
	 "#                                     #                                        #                                      #",
	 "#                                     #                                        #                                      #",
	 "#                                     #                                        #                                      #",
	 "#                                     #                                        #                                      #",
	 "#######################################################################################################################" };
char map3[20][120] = {
	//0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
	 "#######################################################################################################################",
	 "#                                             #####                                        |          #######         #",
	 "#                                             #####                                        |          #######         #",
	 "#                                             #####                                        |          #######         #",
	 "#       ################################      ###############################______#########          #######         #",
	 "#       ################################      ###############################      #########          #######         #",
	 "#       ################################______###############################      #########          #######         #",
	 "#       ####         #####                                             ######      #########          #######         #",
	 "#       ####         #####                                             ######      #########          #######         #",
	 "#       ####         #####                                             ######      #########          #######         #",
	 "#       ####         #####          ##########      ###########        ######      #########          #######         #",
	 "#       ####         #####          ##########      ###########        ######      #########          #######         #",
	 "#       ####         #####          ##########______###########        ######      #########          #######         #",
	 "#       ####         #####          ###                     ###        ######      #########          #######         #",
	 "#       ####         #####          ###                     ###        ######      #########          #######         #",
	 "#       ####                        ###                     ###                    #########          #######         #",
	 "#       ####                        ###                     ###                    #########                |         #",
	 "#       ####                        ###                     ###                    #########                |         #",
	 "#       ####                        ###                     ###                    #########                |         #",
	 "#######################################################################################################################" };
Console::Console()
{
	
}
Console::~Console()
{
	for (int i = 0; i < entities.size(); i++)
	{
		entities.erase(entities.begin() + i);
	}
}
void Console::add(Entity* entity)
{
	entities.push_back(entity);
}

Entity* Console::getAt(int index)
{
	return entities[index];
}

void Console::removeAt(int index)
{
	entities.erase(entities.begin() + index);
}

int Console::getSize() const
{
	return entities.size();
}



void Console::PrintMenu()
{
	cout << "1.Resume" << endl;
	cout << "2.Options" << endl;
	cout << "3.Exit" << endl;
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
		case 1:
		{
			system("cls");
		}
		case 2:
		{
			system("cls");
			printf("Use Arrow Keys for mooving on the map\n For Interact press E\n For Attack press A");
			Sleep(2000);
			break;
		}
		case 3:
		{
			system("cls");
			cout << "Thank you for playing !" << endl;
			Sleep(2000);
			break;
		}
	}
}


void Console::ClearDeadEntities()
{
	for (int i = 1; i < entities.size(); i++)
	{
		if (getAt(i)->isAlive() == false)
		{
			removeAt(i);
		}
	}
}

void Console::EntitiesAttackPlayer()
{
	for (int i = 1; i < entities.size(); i++)
	{

		getAt(i)->HuntPlayer(*getAt(0));
	}
}

void Console::SpawnBoss(int Map)
{
	switch (Map)
	{
		case 1:
		{
			Boss boss(50, 50);
			add(&boss);
			break;
		}
		case 2:
		{
			Boss boss(50, 50);
			add(&boss);
			break;
		}
		case 3:
		{
			Boss boss(50, 50);
			add(&boss);
			break;
		}
	}
}


void Console::ReplaceMap(int index)
{
	switch (index)
	{
		case 1:
		{		
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 120; j++)
				{
					map[i][j] = map1[i][j];
				}
			}
			break;

		}
		case 2:
		{
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 120; j++)
				{
					map[i][j] = map2[i][j];
				}
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 120; j++)
				{
					map[i][j] = map3[i][j];
				}
			}
			break;
		}
	}	
}

void Console::PrintMap()
{
	for (int i = 0; i <= 20; i++)
	{
		printf(&map[i][0]);printf("\n");
	} 
}



