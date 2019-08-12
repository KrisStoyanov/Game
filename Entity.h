#pragma once
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include "Map.h"
using namespace std;
enum class Type
{
	Fatman,
	Boss,
	Player
};
class Entity
{
protected:
	int id = 0;
	int locX;
	int locY;
	int health=0;
	int damage = 0;
	Type enumtype;

public:
	Entity();
	Entity(const Type enumtype, int locx, int locy);
	~Entity();
	bool isAlive();
	double getDistanceTo(const Entity &entity);
	const void setDMG(int _damage);
	const void setHP(int _health);
	virtual void Move(int x, int y);
	int getDMG();
	int getHP();
	int getX();
	int getY();
	void setX(int locx);
	void setY(int locy);
	virtual void HuntPlayer(Entity &entity);
	virtual Type getenumType()const = 0;
	virtual const Entity* clone()const = 0;
};

