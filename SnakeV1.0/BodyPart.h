#pragma once
#include "Direction.h"


class BodyPart
{
private:
	int X;
	int Y;
	Direction direction;
	BodyPart* nextPart = nullptr;
public:
	BodyPart(int newX, int newY, Direction newDirection);
	BodyPart* GetNextPart();
	Direction GetDirection();
	void SetLocation(int newX, int newY);
	void SetDirection(Direction newDirection);
	void SetNextPart(BodyPart* NextPart);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Move(Direction newDirection);
	int GetX();
	int GetY();
};