#pragma once
#include "Entity.h"
#include "Maps.h"
class Player :public Entity
{
private:

	int damage;
	int health;
public:
	Player();
	~Player();
	Player( int locx, int locy);

	Type getenumType()const;

	void Move(int X, int Y);
	void Attack(Entity& entity);
	void Interact();
	void HuntPlayer(Entity& entity);
	void Spawn();

	bool isAlive();
};

