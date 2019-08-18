#pragma once
#include "Entity.h"
class Fatman:public Entity
{
private:
	int damage;
	int health;
	void Attack(Entity &entity);
public:
	Fatman();
	~Fatman();
	Fatman(const Type enumtype, int locx, int locy);
	Type getenumType()const;
	Entity* clone()const;
	void Move(int x, int y);
	void HuntPlayer(Entity &entity);
	void Spawn();
	bool isAlive();
};

