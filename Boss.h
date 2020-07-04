#pragma once
#include "Entity.h"
#include "Maps.h"
class Boss :public Entity
{
private:
	int damage;
	int health;
public:
	Boss();
	~Boss();
	Boss( int locx, int locy);
	Type getenumType()const;
	void Attack(Entity& entity);
	void Move(int x, int y);
	void HuntPlayer(Entity& entity);
	void Spawn();
	bool isAlive();
	void Interact();
	//void Attack(Entity& entity);
};

