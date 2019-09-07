#pragma once
#include "Entity.h"
#include "Maps.h"
class Boss:public Entity
{
private:
	int damage;
	int health;
public:
	Boss();
	~Boss();
	Boss(const Type enumtype, int locx, int locy);
	Type getenumType()const ;
	void Attack(Entity &entity);
	Entity* clone()const ;
	void Move(int x, int y);
	void HuntPlayer(Entity &entity);
	void Spawn();
	bool isAlive();
};

