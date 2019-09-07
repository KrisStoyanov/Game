#include "Fatman.h"
//   @       @ /
// /[0]\ --v[0]
//  /`\     < \ 
Fatman::Fatman(){}
Fatman::~Fatman(){}
double CompatableDistanceF(int locx, int locy, int X, int Y)
{
	return(sqrt(((locx - X)*(locx - X)) + ((locy -Y)*(locy - Y))));
}
void DrawFatman(int X, int Y, char map[20][120])
{
	map[X - 1][Y] = '@';
	map[X][Y - 2] = '/'; map[X][Y - 1] = '[';   map[X][Y] = '0';   map[X][Y + 1] = ']'; map[X][Y + 2] = char(92);
	map[X + 1][Y - 1] = '/'; map[X + 1][Y] = '`'; map[X + 1][Y + 1] = char(92);
}
void EmptySpaceF(int x, int y, char map[20][120])
{
						     map[x    ][y - 2] = ' ';
							 map[x    ][y - 1] = ' '; map[x + 1][y - 1] = ' ';
	map[x - 1][y    ] = ' '; map[x    ][y    ] = ' '; map[x + 1][y    ] = ' ';
							 map[x    ][y + 1] = ' '; map[x + 1][y + 1] = ' ';
						     map[x    ][y + 2] = ' ';
}
Fatman::Fatman(const Type enumtype, int locx, int locy):Entity(enumtype,locx,locy)
{
	setDMG(5);
	setHP(500);
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
			entity.setHP(entity.getHP() - (int(rand() % getDMG() / 2) + int(getDMG() / 2)));
		}
	}
}
Entity * Fatman::clone() const
{
	return new Fatman(*this);
}
bool CanMoveF(int x, int y, int MX, int MY,char map[20][120])
{
	if (MX == 1)//moving down
	{
		if (map[x + 2][y] == ' ' &&
			map[x + 2][y + 2] == ' ' &&
			map[x + 2][y - 2] == ' ' &&
			map[x + 2][y - 1] == ' ' &&
			map[x + 2][y + 1] == ' '
			) return true; else return false;
	}
	else if (MX == -1)//moving up 
	{
		if (map[x - 2][y] == ' ' &&
			map[x - 2][y - 1] == ' ' &&
			map[x - 2][y - 2] == ' ' &&
			map[x - 2][y + 1] == ' ' &&
			map[x - 2][y + 2] == ' '
			) return true; else  return false;
	}
	if (MY == 1)//moving right
	{
		if (map[x][y + 3] == ' ' &&
			map[x + 1][y + 3] == ' ' &&
			map[x - 1][y + 3] == ' '
			) return true; else return false;
	}
	else if (MY == -1) //moving left 
	{
		if (map[x][y - 3] == ' ' &&
			map[x + 1][y - 3] == ' ' &&
			map[x - 1][y - 3] == ' '
			) return true; else  return false;
	}
}
void Fatman::Move(int x, int y)
{
	if (CanMoveF(locX, locY, x, y,map))
	{
		EmptySpaceF(locX, locY,map);
		this->locX = locX + x;
		this->locY = locY + y;
		DrawFatman(locX, locY,map);
	}
}
void Fatman::HuntPlayer(Entity &entity)
{
	
	if (getDistanceTo(entity)<=15)
	{
	double starting_distance = getDistanceTo(entity);
	while (isAlive())
	{
		if (starting_distance >CompatableDistanceF(locX+1,locY,entity.getX(),entity.getY()) )
		{
			Move(1, 0);
			break;
			//movement++;
		}
		else if (starting_distance > CompatableDistanceF(locX - 1, locY, entity.getX(), entity.getY()) )
		{
			Move(-1, 0);
			break;
			//movement++;
		}
		else if (starting_distance > CompatableDistanceF(locX , locY+1, entity.getX(), entity.getY()) )
		{
			Move(0, 1);
			break;
			//movement++;
		}
		else
		{	Move(0, -1);
			break;
		}
	}
	}
		Attack(entity);
}
void Fatman::Spawn()
{
	DrawFatman(locX, locY,map);
}
bool Fatman::isAlive()
{
	if (getHP() <= 0)
	{
		PlaySound(TEXT("Dying.wav.wav"), NULL, SND_FILENAME);
		Coins += 50;
		EmptySpaceF(locX, locY,map);//clearing where the enemy was
		return false;
	}
	else return true;
}