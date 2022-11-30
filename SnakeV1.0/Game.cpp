#include <chrono>
#include <thread>
#include "Game.h"
#include "Snake.h"
#include "GameBoard.h"
#include <windows.h>
#include <stdio.h>

bool Game::isGameOver()
{
	int x = Player->GetHead()->GetX();
	int y = Player->GetHead()->GetY();

	if (ErrorOccured || x < 0 || x >= gameBoard->GetWidth() || y < 0 || y >= gameBoard->GetHeight())
		return true;

	for (BodyPart* b = Player->GetHead()->GetNextPart(); b != nullptr; b = b->GetNextPart()) {
		if (b->GetX() == x && b->GetY() == y) {
			return true;
		}
	}
	return false;
}

bool Game::isNextIsApple()
{
	int x = Player->GetHead()->GetX();
	int y = Player->GetHead()->GetY();
	switch (Player->GetHead()->GetDirection())
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	default:
		break;
	}

	return gameBoard->GetAppleX() == x && gameBoard->GetAppleY() == y;
}

void Game::receiveInput()
{
	
	if (GetAsyncKeyState(VK_LEFT)) {
		input = 'a';
	}
	else if(GetAsyncKeyState(VK_RIGHT)) {
		input = 'd';
	}
	else if (GetAsyncKeyState(VK_UP)) {
		input = 'w';
	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		input = 's';
	}
	else if (GetAsyncKeyState(VK_ESCAPE)) {
		input = 'x';
	}
}

void Game::sleep()
{
	receiveInput();
	std::this_thread::sleep_for(std::chrono::milliseconds(25));
	receiveInput();
	std::this_thread::sleep_for(std::chrono::milliseconds(25));
	receiveInput();
	std::this_thread::sleep_for(std::chrono::milliseconds(25));
	receiveInput();
	std::this_thread::sleep_for(std::chrono::milliseconds(25));
	receiveInput();
	std::this_thread::sleep_for(std::chrono::milliseconds(25));
	receiveInput();
	std::this_thread::sleep_for(std::chrono::milliseconds(25));
	receiveInput();
	std::this_thread::sleep_for(std::chrono::milliseconds(25));
	receiveInput();
}

void Game::StartGame()
{
	cout << "Enter default board size: (Width x Height)\n";
	cin >> defaultWidth;
	cin >> defaultHeight;
	gameBoard = new GameBoard(defaultWidth, defaultHeight);
	Player = new Snake(gameBoard->GetWidth(), gameBoard->GetHeight());
	Direction nextDirecton = Direction::UP;
	while (input != 'x') {
		try {
			gameBoard->PrintBoard(Player->GetHead());
			sleep();
			switch (input)
			{
			case 'w':
				
				nextDirecton = nextDirecton != Direction::DOWN ? Direction::UP : nextDirecton;
				break;
			case 's':
				nextDirecton = nextDirecton != Direction::UP ? Direction::DOWN : nextDirecton;
				break;
			case 'a':
				nextDirecton = nextDirecton != Direction::RIGHT ? Direction::LEFT : nextDirecton;
				break;
			case 'd':
				nextDirecton = nextDirecton != Direction::LEFT ? Direction::RIGHT : nextDirecton;
				break;
			default:
				break;
			}
		}
		catch (exception ex) {
			ErrorOccured = true;
		}
		Player->GetHead()->SetDirection(nextDirecton);
		if (isNextIsApple()) {
			Player->EatApple(gameBoard->GetAppleX(), gameBoard->GetAppleY());
			gameBoard->GenerateApple();
		}
		else {
			Player->KeepMoving();
		}
		if (isGameOver()) {
			system("cls");
			cout << "Game over!";
			return;
		}
	}
}
