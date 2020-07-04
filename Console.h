#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include "Entity.h"
#include "Fatman.h"
#include "Boss.h"
#include "Player.h"
#include "Maps.h"


class Console
{
public:
	Console();
	~Console();
	void add(Entity* entity);
	Entity* getAt(int index);
	void removeAt(int index);
	int getSize() const;
	void ReplaceMap(int index);
	void PrintMap();
	void PrintMenu();
	void SpawnEntities(int Map);
	void ClearDeadEntities();
	void EntitiesAttackPlayer();
	void SpawnBoss(int Map);
private:
	vector<Entity*> entities;
#endif // !CONSOLE_H
};