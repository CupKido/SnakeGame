#pragma once
#include <iostream>
#include "BodyPart.h"

using namespace std;

class GameBoard {
public:

	GameBoard(int Width = 20, int Height = 20, char Empty='.', char AppleChar = 'A');

	void PrintBoard(BodyPart* Head);
	void ClearBoard();

	void GenerateApple();
	int GetAppleX();
	int GetAppleY();
	void SetPlayerChar(char p);
	void SetHeadChar(char h);
	int GetWidth();
	int GetHeight();
private:
	char** board;
	char empty;
	int width;
	int height;

	char playerChar = 'O';
	char headChar = '0';

	int appleX;
	int appleY;
	char appleChar;

	void prepareBoardForPrint(BodyPart* head);
};