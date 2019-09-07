#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Maps
{
private:
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
public:
	char getcharfromMap(int index,int x, int y);
	Maps();
	~Maps();
};
