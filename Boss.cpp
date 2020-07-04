#include "Boss.h"
//    (^_^)|\   
//   |[# #]|--> 
//   | [,] |/   
//    |   |     
//    |   |     
//char boss[5][12]={"  (^_^)|\\ ",
//				  " |[# #]|-->",
//				  " | [,] |/  ",
//				  "  | \" |   ",
//				  "  |   |    " };
Boss::Boss()
{
	health = 0;
	damage = 0;
}
Boss::~Boss()
{
}
double CompatableDistanceB(int locx, int locy, int X, int Y)
{
	return(sqrt(((locx - X) * (locx - X)) + ((locy - Y) * (locy - Y))));
}
void DrawBoss(int Xboss, int Yboss, char map[20][120])
{
	map[Xboss - 2][Yboss - 2] = '('; map[Xboss - 2][Yboss - 1] = '^'; map[Xboss - 2][Yboss] = '_'; map[Xboss - 2][Yboss + 1] = '^'; map[Xboss - 2][Yboss + 2] = ')'; map[Xboss - 2][Yboss + 3] = '|'; map[Xboss - 2][Yboss + 4] = char(92);
	map[Xboss - 1][Yboss - 3] = '|'; map[Xboss - 1][Yboss - 2] = '['; map[Xboss - 1][Yboss - 1] = '#'; map[Xboss - 1][Yboss + 1] = '#'; map[Xboss - 1][Yboss + 2] = ']'; map[Xboss - 1][Yboss + 3] = '|'; map[Xboss - 1][Yboss + 4] = '-'; map[Xboss - 1][Yboss + 5] = '-'; map[Xboss - 1][Yboss + 6] = '>';
	map[Xboss][Yboss - 3] = '|'; map[Xboss][Yboss - 1] = '['; map[Xboss][Yboss] = ','; map[Xboss][Yboss + 1] = ']'; map[Xboss][Yboss + 2] = '|'; map[Xboss][Yboss + 3] = '/';
	map[Xboss + 1][Yboss - 2] = '|'; map[Xboss + 1][Yboss + 2] = '|';
	map[Xboss + 2][Yboss - 2] = '|'; map[Xboss + 2][Yboss + 2] = '|';
}
void EmptySpaceB(int Xboss, int Yboss, char map[20][120])
{
	map[Xboss - 2][Yboss - 2] = ' '; map[Xboss - 2][Yboss - 1] = ' '; map[Xboss - 2][Yboss] = ' '; map[Xboss - 2][Yboss + 1] = ' '; map[Xboss - 2][Yboss + 2] = ' '; map[Xboss - 2][Yboss + 3] = ' '; map[Xboss - 2][Yboss + 4] = ' ';
	map[Xboss - 1][Yboss - 3] = ' '; map[Xboss - 1][Yboss - 2] = ' '; map[Xboss - 1][Yboss - 1] = ' '; map[Xboss - 1][Yboss + 1] = ' '; map[Xboss - 1][Yboss + 2] = ' '; map[Xboss - 1][Yboss + 3] = ' '; map[Xboss - 1][Yboss + 4] = ' '; map[Xboss - 1][Yboss + 5] = ' '; map[Xboss - 1][Yboss + 6] = ' ';
	map[Xboss][Yboss - 3] = ' '; map[Xboss][Yboss - 1] = ' '; map[Xboss][Yboss] = ' '; map[Xboss][Yboss + 1] = ' '; map[Xboss][Yboss + 2] = ' '; map[Xboss][Yboss + 3] = ' ';
	map[Xboss + 1][Yboss - 2] = ' '; map[Xboss + 1][Yboss + 2] = ' ';
	map[Xboss + 2][Yboss - 2] = ' '; map[Xboss + 2][Yboss + 2] = ' ';

}
Boss::Boss( int locx, int locy) :Entity( locx, locy)
{
	setDMG(40);
	setHP(500);
	setType(Type::Boss);
}
Type Boss::getenumType() const
{
	return Type::Boss;
}
void Boss::Attack(Entity& entity)
{
	if (entity.getenumType() == Type::Player)
	{
		if (getDistanceTo(entity) <= 5)
		{
			entity.setHP(entity.getHP() - (int(rand() % getDMG() / 2) + int(getDMG() / 2)));
		}
	}
}
bool CanMoveB(int x, int y, int MX, int MY, char map[20][120])
{
	if (MX == 1)//moving down
	{
		if (map[x + 3][y] == ' ' &&
			map[x + 3][y + 2] == ' ' &&
			map[x + 3][y - 2] == ' ' &&
			map[x + 3][y - 1] == ' ' &&
			map[x + 3][y + 1] == ' ' &&
			map[x + 3][y + 3] == ' ' &&
			map[x + 3][y - 3] == ' ' &&
			map[x + 3][y + 4] == ' ' &&
			map[x + 3][y + 5] == ' ' &&
			map[x + 3][y + 6] == ' '
			) return true; else return false;
	}
	else if (MX == -1)//moving up 
	{
		if (map[x - 3][y] == ' ' &&
			map[x - 3][y + 2] == ' ' &&
			map[x - 3][y - 2] == ' ' &&
			map[x - 3][y - 1] == ' ' &&
			map[x - 3][y + 1] == ' ' &&
			map[x - 3][y + 3] == ' ' &&
			map[x - 3][y - 3] == ' ' &&
			map[x - 3][y + 4] == ' ' &&
			map[x - 3][y + 5] == ' ' &&
			map[x - 3][y + 6] == ' '
			) return true; else  return false;
	}
	if (MY == 1)//moving right
	{
		if (map[x + 1][y + 7] == ' ' &&
			map[x][y + 6] == ' ' &&
			map[x - 1][y + 6] == ' ' &&
			map[x + 2][y + 6] == ' ' &&
			map[x - 2][y + 6] == ' '
			) return true; else return false;
	}
	else if (MY == -1) //moving left 
	{
		if (map[x + 1][y - 4] == ' ' &&
			map[x][y - 4] == ' ' &&
			map[x - 1][y - 4] == ' ' &&
			map[x + 2][y - 4] == ' ' &&
			map[x - 2][y - 4] == ' '
			) return true; else  return false;
	}

}
void Boss::Move(int x, int y)
{
	if (CanMoveB(locX, locY, x, y, map) == true)
	{
		EmptySpaceB(locX, locY, map);
		locX += x;
		locY += y;
		DrawBoss(locX, locY, map);
	}
}
void Boss::HuntPlayer(Entity& entity)
{
	if (getDistanceTo(entity) <= 15)
	{
		int playerX = entity.getX();
		int playerY = entity.getY();
		double starting_distance = getDistanceTo(entity);
		while (isAlive())
		{
			if (starting_distance > CompatableDistanceB(locX + 1, locY, entity.getX(), entity.getY()))
			{
				Move(1, 0);
				break;
			}
			else if (starting_distance > CompatableDistanceB(locX - 1, locY, entity.getX(), entity.getY()))
			{
				Move(-1, 0);
				break;
			}
			else if (starting_distance > CompatableDistanceB(locX, locY + 1, entity.getX(), entity.getY()))
			{
				Move(0, 1);
				break;
			}
			else
			{
				Move(0, -1);
				break;
			}
		}
	}
	Attack(entity);
}
void Boss::Spawn()
{
	DrawBoss(locX, locY, map);
}
bool Boss::isAlive()
{
	if (getHP() <= 0)
	{
		EmptySpaceB(locX, locY, map);
		return false;
	}
	else return true;
}

void Boss::Interact()
{
	assert(false);
}
/*
void Boss::Attack(Entity& entity)
{
	assert(false);
}*/
