#include "BodyPart.h"

BodyPart::BodyPart(int newX, int newY, Direction newDirection)
{
    X = newX;
    Y = newY;
    direction = newDirection;
}

BodyPart* BodyPart::GetNextPart()
{
    return nextPart;
}

Direction BodyPart::GetDirection()
{
    return direction;
}

void BodyPart::SetLocation(int newX, int newY)
{
    X = newX;
    Y = newY;
}

void BodyPart::SetDirection(Direction newDirection)
{
    direction = newDirection;
}

void BodyPart::SetNextPart(BodyPart* NextPart)
{
    nextPart = NextPart;
}

void BodyPart::MoveUp()
{
    Y--;
}

void BodyPart::MoveDown()
{
    Y++;
}

void BodyPart::MoveLeft()
{
    X--;
}

void BodyPart::MoveRight()
{
    X++;
}

void BodyPart::Move(Direction newDirection)
{
    switch (direction)
    {
    case UP:
        Y--;
        break;
    case DOWN:
        Y++;
        break;
    case LEFT:
        X--;
        break;
    case RIGHT:
        X++;
        break;
    default:
        break;
    }
    direction = newDirection;
}

int BodyPart::GetX() {
    return X;
}
int BodyPart::GetY() {
    return Y;
}