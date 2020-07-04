#pragma once
#include "Entity.h"
class Fatman :public Entity
{
private:
	int damage;
	int health;
	void Attack(Entity& entity);
public:
	Fatman();
	~Fatman();
	Fatman( int locx, int locy);
	Type getenumType()const;
	void Move(int x, int y);
	void HuntPlayer(Entity& entity);
	void Spawn();
	bool isAlive();
	void Interact();
	//void Attack(Entity& entity);
};
