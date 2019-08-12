#include "Boss.h"
//    (^_^)|\   
//   |[# #]|--> 
//   | [,] |/   
//    |   |     
//    |   |     
Boss::Boss()
{
}
Boss::~Boss()
{
}
Boss::Boss(const Type enumtype, int locx, int locy):Entity(enumtype,locx,locy)
{
	damage = 40;
	health = 500;
}
Type Boss::getenumType() const 
{
	return Type::Boss;
}
void Boss::Attack(Entity &entity)
{
	if (entity.getenumType() == Type::Player)
	{
		if (getDistanceTo(entity) <= 5)
		{
			entity.setHP(entity.getHP() - rand() % damage/2 + int (damage/2));
		}
	}
}
const Entity * Boss::clone() const 
{
	return new Boss(*this) ;
}
void Boss::Move(int x, int y)
{
	if (CanMove)
	{
		EmptySpace(locX, locY);
		locX += x;
		locY += y;
		DrawBoss(locX, locY);
	}
}
bool CanMove(int x, int y, int MX, int MY)
{
	if (MX > 0)//moving down
	{
		if (map[x + 3][y    ] == ' ' &&
			map[x + 3][y + 2] == ' ' &&
			map[x + 3][y - 2] == ' ' &&
			map[x + 3][y - 1] == ' ' &&
			map[x + 3][y + 1] == ' ' &&
			map[x + 3][y + 3] == ' ' &&
			map[x + 3][y - 3] == ' ' &&
			map[x + 3][y + 4] == ' ' &&
			map[x + 3][y + 5] == ' ' &&
			map[x + 3][y + 6] == ' ' 
			) return true;
	}
	else//moving up 
	{
		if( map[x - 3][y    ] == ' ' &&
			map[x - 3][y + 2] == ' ' &&
			map[x - 3][y - 2] == ' ' &&
			map[x - 3][y - 1] == ' ' &&
			map[x - 3][y + 1] == ' ' &&
			map[x - 3][y + 3] == ' ' &&
			map[x - 3][y - 3] == ' ' &&
			map[x - 3][y + 4] == ' ' &&
			map[x - 3][y + 5] == ' ' &&
			map[x - 3][y + 6] == ' '
			) return true;
	}
	if (MY > 0)//moving right
	{
		if (map[x + 1][y + 7] == ' ' &&
			map[x    ][y + 6] == ' ' &&
			map[x - 1][y + 6] == ' ' &&
			map[x + 2][y + 6] == ' ' &&
			map[x - 2][y + 6] == ' ' 
			) return true;
	}
	else //moving left 
	{
		if (map[x + 1][y -4] == ' ' &&
			map[x    ][y -4] == ' ' &&
			map[x - 1][y -4] == ' ' &&
			map[x + 2][y -4] == ' ' &&
			map[x - 2][y -4] == ' '
			) return true;
	}
}
void Boss::HuntPlayer(Entity & entity)
{
	int playerX = entity.getX();
	int playerY = entity.getY();
	while (isAlive() != 0)
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
void DrawBoss(int Xboss, int Yboss)
{
	map[Xboss - 2][Yboss - 2] = '('; map[Xboss - 2][Yboss - 1] = '^'; map[Xboss - 2][Yboss] = '_'; map[Xboss - 2][Yboss + 1] = '^'; map[Xboss - 2][Yboss + 2] = ')'; map[Xboss - 2][Yboss + 3] = '|'; map[Xboss - 2][Yboss + 4] = char(92);
	map[Xboss - 1][Yboss - 3] = '|'; map[Xboss - 1][Yboss - 2] = '['; map[Xboss - 1][Yboss - 1] = '#'; map[Xboss - 1][Yboss + 1] = '#'; map[Xboss - 1][Yboss + 2] = ']'; map[Xboss - 1][Yboss + 3] = '|'; map[Xboss - 1][Yboss + 4] = '-'; map[Xboss - 1][Yboss + 5] = '-'; map[Xboss - 1][Yboss + 6] = '>';
	map[Xboss][Yboss - 3] = '|'; map[Xboss][Yboss - 1] = '['; map[Xboss][Yboss] = ','; map[Xboss][Yboss + 1] = ']'; map[Xboss][Yboss + 2] = '|'; map[Xboss][Yboss + 3] = '/';
	map[Xboss + 1][Yboss - 2] = '|'; map[Xboss + 1][Yboss + 2] = '|';
	map[Xboss + 2][Yboss - 2] = '|'; map[Xboss + 2][Yboss + 2] = '|';
}
void EmptySpace(int Xboss, int Yboss)
{
	map[Xboss - 2][Yboss - 2] = ' '; map[Xboss - 2][Yboss - 1] = ' '; map[Xboss - 2][Yboss] = ' '; map[Xboss - 2][Yboss + 1] = ' '; map[Xboss - 2][Yboss + 2] = ' '; map[Xboss - 2][Yboss + 3] = ' '; map[Xboss - 2][Yboss + 4] =      ' ';
	map[Xboss - 1][Yboss - 3] = ' '; map[Xboss - 1][Yboss - 2] = ' '; map[Xboss - 1][Yboss - 1] = ' '; map[Xboss - 1][Yboss + 1] = ' '; map[Xboss - 1][Yboss + 2] = ' '; map[Xboss - 1][Yboss + 3] = ' '; map[Xboss - 1][Yboss + 4] = ' '; map[Xboss - 1][Yboss + 5] = ' '; map[Xboss - 1][Yboss + 6] = ' ';
	map[Xboss][Yboss - 3] = ' '; map[Xboss][Yboss - 1] = ' '; map[Xboss][Yboss] = ' '; map[Xboss][Yboss + 1] = ' '; map[Xboss][Yboss + 2] = ' '; map[Xboss][Yboss + 3] = ' ';
	map[Xboss + 1][Yboss - 2] = ' '; map[Xboss + 1][Yboss + 2] = ' ';
	map[Xboss + 2][Yboss - 2] = ' '; map[Xboss + 2][Yboss + 2] = ' ';

}