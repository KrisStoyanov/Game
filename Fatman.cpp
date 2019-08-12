#include "Fatman.h"
//   @   
// /[0]\ 
//  /`\  
Fatman::Fatman(){}
Fatman::~Fatman(){}

Fatman::Fatman(const Type enumtype, int locx, int locy):Entity(enumtype,locx,locy)
{
	damage = 5;
	health = 50;
}

Type Fatman::getenumType() const
{
	return Type::Fatman;
}

void Fatman::Attack(Entity &entity)
{
	if (entity.getenumType()==Type::Player)
	{
		if (getDistanceTo(entity)<=5)
		{
			entity.setHP(entity.getHP() - rand() % damage / 2 + int(damage / 2));
		}
	}
}

const Entity * Fatman::clone() const
{
	return new Fatman(*this);
}

void Fatman::Move(int x, int y)
{
	if (CanMove)
	{
		EmptySpace(locX, locY);
		this->locX = locX + x;
		this->locY = locY + y;
		DrawFatman(locX, locY);
	}
}
bool CanMove(int x, int y, int MX, int MY)
{

	if (MX > 0)//moving down
	{
		if (map[x + 2][y    ] == ' ' &&
			map[x + 2][y + 2] == ' ' &&
			map[x + 2][y - 2] == ' ' &&
			map[x + 2][y - 1] == ' ' &&
			map[x + 2][y + 1] == ' ' &&
			map[x + 2][y    ] == ' '
			) return true;
	}
	else//moving up 
	{
		if (map[x - 2][y    ] == ' ' &&
			map[x - 2][y - 1] == ' ' &&
			map[x - 2][y - 2] == ' ' &&
			map[x - 2][y + 1] == ' ' &&
			map[x - 2][y + 2] == ' '
			) return true;
	}
	if (MY > 0)//moving right
	{
		if (map[x    ][y + 3] == ' ' &&
			map[x + 1][y + 3] == ' ' &&
			map[x - 1][y + 3] == ' '
			) return true;
	}
	else //moving left 
	{
		if (map[x    ][y - 3] == ' ' &&
			map[x + 1][y - 3] == ' ' &&
			map[x - 1][y - 3] == ' '
			) return true;
	}
}
void Fatman::HuntPlayer(Entity &entity)
{
	int playerX = entity.getX();
	int playerY = entity.getY();
	while (isAlive()!=0)
	{
		if (playerY > locY)
		{
			Move(0, 1);
			break;
		}
		else {
			Move(0, -1);
			break;
		}
		if (playerX > locX)
		{
		Move(1, 0);
		break;
		}
		else 
		{
		Move(-1, 0);
		break;
		}
	}
		Attack(entity);
}

void DrawFatman(int X, int Y)
{
	map[X - 1][Y] = '@';
	map[X][Y - 2] = '/'; map[X][Y - 1] = '[';   map[X][Y] = '0';   map[X][Y + 1] = ']'; map[X][Y + 2] = char(92);
	map[X + 1][Y - 1] = '/'; map[X + 1][Y] = '`'; map[X + 1][Y + 1] = char(92);
}
void EmptySpace(int x, int y)
{
	map[x][y - 2] = ' ';
	map[x][y - 1] = ' '; map[x + 1][y - 1] = ' ';
	map[x - 1][y] = ' ';   map[x][y] = ' ';
	map[x][y + 1] = ' '; map[x + 1][y + 1] = ' ';
	map[x][y + 2] = ' ';
}

