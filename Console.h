#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include "Entity.h"
#include "Fatman.h"
#include   "Boss.h"
#include "Player.h"
class Console
{
public:
	Console();
	~Console();
	void add(Entity* entity);
	Entity* getAt(int index);
	void removeAt(int index);
	int getSize() const;
private:
	vector<Entity*> entities;
};
#endif // !CONSOLE_H
