#include "Maps.h"



char Maps::getcharfromMap(int index, int x, int y)
{
	switch (index)
	{
	case 1:
	{
		return map1[x][y];
		break;
	}
	case 2:
	{
		return map2[x][y];
		break;
	}
	case 3:
	{
		return map3[x][y];
		break;
	}
	}
}

Maps::Maps()
{
}


Maps::~Maps()
{
}
