#include "Entity.h"
int ID = 0;
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
	 "|                                     #                                        #                                      |",//1    (^_^)|\      _-|0|-_ |) ______    ___                     ___ |@| _   /      ^ 
	 "|                                     #                                        #                                      |",//2   |[# #]|-->   //\_|_/\\|  \KILL/   |HIT|  |     |)         |   |_|_/\\ /     C=|=] 
	 "|                                     #                                        #                                      |",//3   | [,] |/     || |+|  \|   \ME/    |   |  |     |       /  |   ||+|  \X        |
	 "|                                     #                                        #                                      |",//4    |   |         //`\\       \/      \_/  -+-    |      /   |___|/`\\           |
	 "|                                     #                                        #                                      |",//5    |   |        ||   ||                    '                   ||   ||          |
	 "|                                     #                                        #                                      |",//6   ^^           ^^^   ^^^                  chest:              ^^^   ^^^
	 "|                                     #                                        #                                      |",//7   _    |\   (|) <=] [_] <=> {=}  |\_  ?     ___    <=]
	 "|                                     #                                        #                                      |",//8  |H|   | )   |   |   |   |   |   |/   |     | |     |
	 "+---------------------------------------------------------------------------------------------------------------------+"};//9  V                                                 |
Entity::Entity()
{
	health = 1;
	damage = 0;
}
Entity::Entity(const Type _enumtype, int locx, int locy)
{
	id = ID; ID++;
	locX = locx;
	locY = locy;
	enumtype = _enumtype;
}
Entity::~Entity()
{
}
bool Entity::isAlive()
{
	if (health<=0)
	{
		return false;
	}
	else return true;
}
double Entity::getDistanceTo(const Entity &entity)
{
	if (entity.locX!=NULL && entity.locY!=NULL)
	{
		return(sqrt(((locX - entity.locX)*(locX - entity.locX)) + ((locY - entity.locY)*(locY - entity.locY))));
	}
}
const void Entity::setDMG(int _damage)
{
	damage = _damage;
}
const void Entity::setHP(int _health)
{
	health = _health;
}
void Entity::Move(int x, int y)
{
	this->locX = locX + x;
	this->locY = locY + y;
}
int Entity::getX()
{
	return locX;
}
int Entity::getY()
{
	return locY;
}
void Entity::setX(int locx)
{
	if (locx>1 && locx<20)locX = locx;
}
void Entity::setY(int locy)
{
	if(locy>1 && locy<120)locY = locy;
}
int Entity::getDMG()
{
	return damage;
}
int Entity::getHP()
{
	return health;
}