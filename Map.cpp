﻿#include "Map.h"



Map::Map()
{
	char map[20][120] = {
	   //0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		"+---------------------------------------------------------------------------------------------------------------------+",//0corpses
		"|                                     #                                        #                                      |",//1_(*~*)_
		"|                                     #                                        #                                      |",//2 enemy1:    enemy2:         
		"|                                     #                                        #                                      |",//3   @          _            (')
		"|                                     #                                        #                                      |",//4 /[0]\     //(^)\\      /`"|`\\ 
		"|                                     # #########################_____##########                                      |",//5  /`\     //(:":)\\    '   `  ``
		"|                                     |                                                                               |",//6splash hero2.0  hero1.0       
		"|                                     |                                                                               |",//7 ,^,    _ O |     O          /|\   
		"|                                     |                                                                               |",//8<#*#>  | ||\+   0/|\/       (|#|)  
		"|                                     #######_____##############################                                      |",//9 `v`    V/`\     / \         \|/    
		"|                                     #                                        #                                      |",//0    boss1.0 boss 2.0_                                              _
		"|                                     #                                        #                                      |",//1    (^_^)|\      _-|0|-_ |) ______    ___                     ___ |@| _   /
		"|                                     #                                        #                                      |",//2   |[# #]|-->   //\_|_/\\|  \KILL/   |HIT|  |     |)         |   |_|_/\\ /    
		"|                                     #                                        #                                      |",//3   | [,] |/     || |+|  \|   \ME/    |   |  |     |       /  |   ||+|  \X
		"|                                     #                                        #                                      |",//4    |   |         //`\\       \/      \_/  -+-    |      /   |___|/`\\      
		"|                                     #                                        #                                      |",//5    |   |        ||   ||                    '                   ||   ||
		"|                                     #                                        #                                      |",//6   ^^           ^^^   ^^^                  chest:              ^^^   ^^^
		"|                                     #                                        #                                      |",//7   _    |\   (|) <=] [_] <=> {=}  |\_  Ш     ___  
		"|                                     #                                        #                                      |",//8  |H|   | )   |   |   |   |   |   |/   |     | |  
		"+---------------------------------------------------------------------------------------------------------------------+"};//9  V    |/    |   |   |   |   |        |     |_|    
}


Map::~Map()
{
}