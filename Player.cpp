#include "Player.h"
//  _ O |      
// | |V\+      
//  '/ \   

int Coins;
Player::Player()
{

}
Player::~Player()
{
}
void Draw(int x, int y, char map[20][120])
{	map[x - 1][y - 2] = '_';
	map[x - 1][y + 2] = '|';
	map[x - 1][y] = 'O';
	map[x][y] = '|';
	map[x][y - 1] = '|';
	map[x + 1][y - 2] = '\'';
	map[x][y - 3] = '|';
	map[x][y + 1] = char(92);
	map[x + 1][y + 1] = char(92);
	map[x + 1][y - 1] = '/';
	map[x][y - 2] = ' ';
	map[x + 1][y] = '`';
	map[x][y + 2] = '+';
}
void DrawAttack(int x, int y, char map[20][120])
{
	//todo
}
void EmptySpaceP(int x, int y, char map[20][120])
{
	map[x - 1][y - 2] = ' ';
	map[x - 1][y + 2] = ' ';
	map[x - 1][y] = ' ';
	map[x][y] = ' ';
	map[x][y - 1] = ' ';
	map[x + 1][y - 2] = ' ';
	map[x][y - 3] = ' ';
	map[x][y + 1] = ' ';
	map[x + 1][y + 1] = ' ';
	map[x + 1][y - 1] = ' ';
	map[x][y - 2] = ' ';
	map[x + 1][y] = ' ';
	map[x][y + 2] = ' ';
}
void clearAround(int x, int y)
{
	map[x][y - 1] = ' '; map[x + 1][y - 1] = ' ';
	map[x - 1][y] = ' '; map[x][y] = ' ';
	map[x][y + 1] = ' '; map[x + 1][y + 1] = ' ';
	map[x + 1][y] = ' '; map[x - 1][y + 1] = ' '; map[x - 1][y - 1] = ' ';

}
bool CanMoveP(int x, int y, int MX, int MY, char map[20][120])
{
	if (MX == 1)//moving down
	{
		if (map[x + 2][y] == ' ' &&
			map[x + 2][y + 2] == ' ' &&
			map[x + 2][y - 2] == ' ' &&
			map[x + 2][y - 1] == ' ' &&
			map[x + 2][y + 1] == ' ' &&
			map[x + 2][y - 3] == ' ')
			return true; else return false;
	}
	else if (MX == -1)//moving up 
	{
		if (map[x - 2][y] == ' ' &&
			map[x - 2][y - 1] == ' ' &&
			map[x - 2][y - 2] == ' ' &&
			map[x - 2][y + 1] == ' ' &&
			map[x - 2][y + 2] == ' ' &&
			map[x - 2][y - 3] == ' ') 
			return true; else  return false;
	}
	if (MY == 1)//moving right
	{
		if (map[x][y + 3] == ' ' &&
			map[x + 1][y + 3] == ' ' &&
			map[x - 1][y + 3] == ' ') 
			return true; else return false;
	}
	else if (MY == -1) //moving left 
	{
		if (map[x][y - 4] == ' ' &&
			map[x + 1][y - 4] == ' ' &&
			map[x - 1][y - 4] == ' ') 
			return true; else return false;
	}
}
Player::Player( int locx, int locy) :Entity( locx, locy)
{
	setDMG(50);
	setHP(1000);
	setType(Type::Player);
}
void Player::Move(int X, int Y)
{
	if (CanMoveP(locX, locY, X, Y, map))
	{
		EmptySpaceP(locX, locY, map);
		this->locX = locX + X;
		this->locY = locY + Y;
		Draw(locX, locY, map);
	}
}
Type Player::getenumType() const
{
	return Type::Player;
}
void Player::Attack(Entity& entity)
{
	if (entity.getenumType() == Type::Boss || entity.getenumType() == Type::Fatman)
	{
		if (getDistanceTo(entity) <= 6)
		{
			entity.setHP(entity.getHP() - (int(rand() % getDMG() / 2) + int(getDMG() / 2)));
		}
	}
}

void Player::Interact()
{
	bool doorUp = false;
	bool doorDown = false;
	bool doorLeft = false;
	bool doorRight = false;
	if (map[locX][locY + 3] == '|' && map[locX + 1][locY + 3] == '|' && map[locX - 1][locY + 3] == '|')doorRight = true;
	else if (map[locX][locY - 3] == '|' && map[locX + 1][locY - 3] == '|' && map[locX - 1][locY - 3] == '|') doorLeft = true;
	else if (map[locX - 2][locY] == '_' && map[locX - 2][locY + 1] == '_' && map[locX - 2][locY - 1] == '_' && map[locX - 2][locY + 2] == '_' && map[locX - 2][locY - 2] == '_' && map[locX - 2][locY - 3] == '_') doorUp = true;
	else if (map[locX + 2][locY] == '_' && map[locX + 2][locY + 1] == '_' && map[locX + 2][locY - 1] == '_' && map[locX + 2][locY + 2] == '_' && map[locX + 2][locY - 2] == '_' && map[locX + 2][locY - 3] == '_') doorDown = true;

	map[doorUp * (locX - 2) + doorDown * (locX + 2) + doorLeft * (locX)+doorRight * (locX)]
		[doorUp * (locY)+doorDown * (locY)+doorLeft * (locY - 3) + doorRight * (locY + 3)] = ' ';

	map[doorUp * (locX - 2) + doorDown * (locX + 2) + doorLeft * (locX + 1) + doorRight * (locX + 1)]
		[doorUp * (locY + 1) + doorDown * (locY + 1) + doorLeft * (locY - 3) + doorRight * (locY + 3)] = ' ';

	map[doorUp * (locX - 2) + doorDown * (locX + 2) + doorLeft * (locX - 1) + doorRight * (locX - 1)]
		[doorUp * (locY - 1) + doorDown * (locY - 1) + doorLeft * (locY - 3) + doorRight * (locY + 3)] = ' ';

	map[doorUp * (locX - 2) + doorDown * (locX + 2)]
		[doorUp * (locY - 2) + doorDown * (locY - 2)] = ' ';

	map[doorUp * (locX - 2) + doorDown * (locX + 2)]
		[doorUp * (locY + 2) + doorDown * (locY + 2)] = ' ';

	map[doorUp * (locX - 2) + doorDown * (locX + 2)]
		[doorUp * (locY - 3) + doorDown * (locY - 3)] = ' ';

	if (doorRight == true || doorLeft == true || doorDown == true || doorUp == true)
	{
		//PlaySound(TEXT("OpenDoor.wav.wav"), NULL, SND_FILENAME);
		//PlaySound(TEXT("OpenDoor.wav.wav"), NULL, SND_FILENAME);
	}

	//CHESTS
	if (map[locX + 3][locY] == '!' && map[locX + 2][locY] != '#')//UP
	{
		clearAround(locX + 3, locY);// Coins += 10;
	}
	if (map[locX - 3][locY] == '!' && map[locX - 2][locY] != '#')//Down
	{
		clearAround(locX - 3, locY);// Coins += 10;
	}
	if (map[locX][locY + 4] == '!' && map[locX][locY + 3] != '#')//Right
	{
		clearAround(locX, locY + 4);// Coins += 10;
	}
	if (map[locX][locY - 4] == '!' && map[locX][locY - 3] != '#')//Left
	{
		clearAround(locX, locY - 4);// Coins += 10;
	}
}
void Player::HuntPlayer(Entity& entity)
{
	assert(false);
}
void Player::Spawn()
{
	Draw(locX, locY, map);
}
bool Player::isAlive()
{
	if (getHP() <= 0)
	{
		return false;
		EmptySpaceP(locX, locY, map);
	}
	else return true;
}