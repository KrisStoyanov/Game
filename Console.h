#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <vector>
#include "Entity.h"
#include "Fatman.h"
#include "Boss.h"
#include "Player.h"

class Console
{
public:
	Console();
	~Console();
	void add(const Entity* entity);
	const Entity* getAt(int index) const;
	void removeAt(int index);
	int getSize() const;
private:
	vector<const Entity*> entities;
};
#endif // !CONSOLE_H
