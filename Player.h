#pragma once
#include "Entity.h"
#include "Maps.h"
class Player:public Entity
{
private:

	int damage;
	int health;
public:
	Player();
	~Player();
	Player(const Type enumtype, int locx, int locy);
	void Move(int X, int Y);
	Type getenumType()const;
	void Attack(Entity &entity);
	Entity* clone()const ;
	void Interact();
	void HuntPlayer(Entity &entity);
	void Spawn();
	bool isAlive();
};