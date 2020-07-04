#include "Entity.h"
char map[20][120];
Entity::Entity()
{
	health = 1;
	damage = 0;
}
Entity::Entity( int locx, int locy)
{
	locX = locx;
	locY = locy;
}
Entity::~Entity()
{
}
double Entity::getDistanceTo(const Entity& entity)
{
	if (entity.locX != NULL && entity.locY != NULL)
	{
		return(sqrt(((locX - entity.locX) * (locX - entity.locX)) + ((locY - entity.locY) * (locY - entity.locY))));
	}
}
const void Entity::setType(Type GivenType)
{
	enumtype=GivenType;
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
	if (locx > 1 && locx < 20)locX = locx;
}
void Entity::setY(int locy)
{
	if (locy > 1 && locy < 120)locY = locy;
}

int Entity::getDMG()
{
	return damage;
}
int Entity::getHP()
{
	return health;
}