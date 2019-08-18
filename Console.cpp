#include "Console.h"
Console::Console()
{
	
}
Console::~Console()
{
}

void Console::add(Entity * entity)
{
	entities.push_back(entity->clone());
}

Entity * Console::getAt(int index)
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
