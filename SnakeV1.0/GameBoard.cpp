#include "GameBoard.h"
#include "Snake.h"

GameBoard::GameBoard(int Width, int Height, char Empty, char AppleChar)
{
	width = Width;
	height = Height;
	empty = Empty;
	appleChar = AppleChar;
	board = new char* [width];
	for (int i = 0; i < width; i++) {
		board[i] = new char[height];
	}
	ClearBoard();
	GenerateApple();
}

void GameBoard::PrintBoard(BodyPart* Head)
{
	try {
		prepareBoardForPrint(Head);
	}
	catch (exception ex) {
		throw ex;
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
		{
			cout << board[j][i];
		}
		cout << '\n';
	}
}

void GameBoard::prepareBoardForPrint(BodyPart* Head) {
	ClearBoard();
	system("cls");
	board[appleX][appleY] = appleChar;
	int x, y;
	for (BodyPart* b = Head; b != nullptr; b = b->GetNextPart()) {
		x = b->GetX();
		y = b->GetY();
		try {
			board[x][y] = playerChar;
		}
		catch (exception ex) {
			throw ex;
		}

	}
	board[Head->GetX()][Head->GetY()] = headChar;
}

void GameBoard::ClearBoard() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			board[j][i] = empty;
		}
	}
}

void GameBoard::GenerateApple()
{
	appleX = rand() % width;
	appleY = rand() % height;
	/*appleX = 79;
	appleY = 10;*/
}
int GameBoard::GetAppleX() {
	return appleX;
}
int GameBoard::GetAppleY() {
	return appleY;
}


void GameBoard::SetPlayerChar(char p) {
	playerChar = p;
}
void GameBoard::SetHeadChar(char h) {
	headChar = h;
}

int GameBoard::GetWidth()
{
	return width;
}

int GameBoard::GetHeight()
{
	return height;
}
