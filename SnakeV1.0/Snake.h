#pragma once
#include "BodyPart.h"
#include "GameBoard.h"

class Snake {
private:
	BodyPart* Head;
public:
	Snake(int CornerX = 19, int CornerY = 19);
	BodyPart* GetHead();
	void EatApple(int appleX, int AppleY);
	void SetHead(BodyPart* newHead);
	void Move(Direction to);
	void UpdateMovement(Direction newDirection, BodyPart* bodyPart);
	void KeepMoving();
};