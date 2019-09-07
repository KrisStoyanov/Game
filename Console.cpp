#include "Console.h"
Console::Console()
{
	
}
Console::~Console()
{
}
void Console::add(Entity * entity)
{
	entities.push_back(entity);
}

Entity * Console::getAt(int index)
{
	return entities[index];
}

void Console::removeAt(int index)
{
	entities.erase(entities.begin() + index);
}

int Console::getSize() const
{
	return entities.size();
}

void Console::ReplaceMap(int index)
{	Maps m;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			map[i][j] = m.getcharfromMap(index, i, j);
		}
	}
}

void Console::PrintMap()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}


