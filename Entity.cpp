#include "Entity.h"
int ID = 0;


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
	if (health==0)
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
