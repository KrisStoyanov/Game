#include "Console.h"
int x = 9;
int y = 9;
int Coins = 0;
Console::Console()
{
	
}
Console::~Console()
{
}

void Console::add(const Entity * entity)
{
	entities.push_back(entity->clone());
}

const Entity * Console::getAt(int index)const 
{
	return entities[index];
}

void Console::removeAt(int index)
{
	delete entities[index];
	entities.erase(entities.begin() + index);
}

int Console::getSize() const
{
	return entities.size();
}
