#pragma once
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <cassert>
#include <thread>
#include "Maps.h"
extern char map[20][120];
extern int Coins;
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
	int locX;
	int locY;
	int health = 0;
	int damage = 0;
	Type enumtype;

public:
	Entity();
	Entity( int locx, int locy);
	~Entity();
	virtual bool isAlive() = 0;
	double getDistanceTo(const Entity& entity);
	const void setType(Type GivenType);
	const void setDMG(int _damage);
	const void setHP(int _health);
	virtual void Move(int x, int y);
	int getDMG();
	int getHP();
	int getX();
	int getY();
	void setX(int locx);
	void setY(int locy);
	virtual void HuntPlayer(Entity& entity) = 0;
	virtual void Interact() = 0;
	virtual void Attack(Entity& entity) = 0;
	virtual Type getenumType()const = 0;
	virtual void Spawn() = 0;
};

