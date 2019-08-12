#include "Player.h"
//    O     
//  0/|\/   
//   / \    
Player::Player()
{
}
Player::~Player()
{
}
Player::Player(const Type enumtype, int locx, int locy):Entity(enumtype, locx,locy)
{
	damage = 50;
	health = 1000;
}
void Player::Move(int X, int Y)
{
	EmptySpace(locX,locY);
	this->locX = locX + X;
	this->locY = locY + Y;
	Draw(locX, locY);
}
bool CanMove(int x, int y, int MX,int MY)
{
	if (MX > 0)//moving down
	{
		if (map[x + 1][y] == ' ' &&
			map[x + 1][y + 2] == ' ' &&
			map[x + 1][y - 2] == ' ' &&
			map[x + 2][y - 1] == ' ' &&
			map[x + 2][y + 1] == ' ' &&
			map[x + 2][y] == ' '
			) return true;
	}
	else//moving up 
	{
		if (map[x - 2][y] == ' ' &&
			map[x - 1][y - 1] == ' ' &&
			map[x - 1][y - 2] == ' ' &&
			map[x - 1][y + 1] == ' ' &&
			map[x - 1][y + 2] == ' '
			) return true;
	}
	if (MY>0)//moving right
	{
		if (map[x][y + 3] == ' ' &&
			map[x + 1][y + 2] == ' ' &&
			map[x - 1][y + 2] == ' '
			) return true;
	}
	else //moving left 
	{
		if (map[x][y - 3] == ' ' &&
			map[x + 1][y - 2] == ' ' &&
			map[x - 1][y - 2] == ' '
			) return true;
	}
}
Type Player::getenumType() const
{
	return Type::Player;
}
void Player::Attack(const Entity &entity)
{
	if (entity.getenumType()==Type::Boss || entity.getenumType()==Type::Fatman)
	{
		if (getDistanceTo(entity)<=3)
		{
			entity.setHP(entity.getHP() - rand() % damage / 2 + int(damage / 2));
		}
	}

}
const Entity * Player::clone() const
{
	return new Player(*this);
}
void Player::Interact()
{
	bool doorUp = false;
	bool doorDown = false;
	bool doorLeft = false;
	bool doorRight = false;
	if (map[locX][locY + 3] == '|'&& map[locX+1][locY+3]=='|' && map[locX-1][locY+3]=='|')doorRight = true;
	else if (map[locX][locY - 3] == '|'&& map[locX + 1][locY - 3] == '|' && map[locX - 1][locY - 3] == '|') doorLeft = true;
	else if (map[locX - 2][locY] == '_'&& map[locX - 2][locY + 1] == '_' &&  map[locX - 2][locY - 1] == '_' && map[locX - 2][locY + 2] == '_' && map[locX - 2][locY - 2] == '_') doorUp = true;
	else if (map[locX + 2][locY] == '_'&& map[locX + 2][locY + 1] == '_' &&  map[locX + 2][locY - 1] == '_' && map[locX + 2][locY + 2] == '_' && map[locX + 2][locY - 2] == '_') doorDown = true;

	map[doorUp*(locX - 2) + doorDown * (locX + 2) + doorLeft * (locX)+doorRight * (locX)]
		[doorUp*(locY)+doorDown * (locY)+doorLeft * (locY - 3) + doorRight * (locY + 3)] = ' ';

	map[doorUp*(locX - 2) + doorDown * (locX + 2) + doorLeft * (locX + 1) + doorRight * (locX + 1)]
		[doorUp*(locY + 1) + doorDown * (locY + 1) + doorLeft * (locY - 3) + doorRight * (locY + 3)] = ' ';

	map[doorUp*(locX - 2) + doorDown * (locX + 2) + doorLeft * (locX - 1) + doorRight * (locX - 1)]
		[doorUp*(locY - 1) + doorDown * (locY - 1) + doorLeft * (locY - 3) + doorRight * (locY + 3)] = ' ';

	map[doorUp*(locX - 2) + doorDown * (locX + 2)]
		[doorUp*(locY - 2) + doorDown * (locY - 2)] = ' ';

	map[doorUp*(locX - 2) + doorDown * (locX + 2)]
		[doorUp*(locY + 2) + doorDown * (locY + 2)] = ' ';
	if (doorRight == true || doorLeft == true || doorDown == true || doorUp == true)
	{
		PlaySound(TEXT("OpenDoor.wav.wav"), NULL, SND_FILENAME);
	}

	//CHESTS
	if (map[locX + 3][locY] == '!'&&map[locX + 2][locY] != '#')//UP
	{
		clearAround(locX + 3, locY); Coins += 10;
	}
	if (map[locX - 3][locY] == '!'&&map[locX - 2][locY] != '#')//Down
	{
		clearAround(locX - 3, locY); Coins += 10;
	}
	if (map[locX][locY + 4] == '!'&&map[locX][locY + 3] != '#')//Right
	{
		clearAround(locX, locY + 4); Coins += 10;
	}
	if (map[locX][locY - 4] == '!'&&map[locX][locY - 3] != '#')//Left
	{
		clearAround(locX, locY - 4); Coins += 10;
	}
}
void Draw(int x, int y)
{
	map[x - 1][y] = 'O';
	map[x][y] = '|';
	map[x][y - 1] = '/';
	map[x][y + 1] = char(92);
	map[x + 1][y + 1] = char(92);
	map[x + 1][y - 1] = '/';
	map[x][y - 2] = '0';
	map[x][y + 2] = '/';
}
void EmptySpace(int x, int y)
{
	map[x][y - 2] = ' ';
	map[x][y - 1] = ' '; map[x + 1][y - 1] = ' ';
	map[x - 1][y] = ' ';   map[x][y] = ' ';
	map[x][y + 1] = ' '; map[x + 1][y + 1] = ' ';
	map[x][y + 2] = ' ';
}
void clearAround(int x, int y)
{
	map[x][y - 1] = ' '; map[x + 1][y - 1] = ' ';
	map[x - 1][y] = ' '; map[x][y] = ' ';
	map[x][y + 1] = ' '; map[x + 1][y + 1] = ' ';
	map[x + 1][y] = ' '; map[x - 1][y + 1] = ' '; map[x - 1][y - 1] = ' ';

}