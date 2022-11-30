#pragma once

#include "Snake.h"
#include "GameBoard.h"

class Game
{
private:
	Snake* Player;

	GameBoard* gameBoard;

	char input = 'w';

	bool isGameOver();
	bool ErrorOccured = false;

	bool isNextIsApple();

	void receiveInput();

	void sleep();
public: 
	void StartGame();
};