#include "Snake.h"
#include "BodyPart.h"
Snake::Snake(int CornerX, int CornerY)
{
    Head = new BodyPart(CornerX - 1, CornerY - 1, Direction::UP);
}



BodyPart* Snake::GetHead()
{
    return Head;
}

void Snake::EatApple(int appleX, int appleY)
{
    BodyPart* newHead = new BodyPart(appleX, appleY, Head->GetDirection());
    newHead->SetNextPart(Head);
    Head = newHead;
}

void Snake::SetHead(BodyPart* newHead)
{
    Head = newHead;
}

void Snake::Move(Direction to)
{
    Head->SetDirection(to);
    UpdateMovement(to, Head);
}

void Snake::KeepMoving() {
    UpdateMovement(Head->GetDirection(), Head);
}

void Snake::UpdateMovement(Direction newDirection, BodyPart* bodyPart)
{
    Direction newNextDirection = bodyPart->GetDirection();
    bodyPart->Move(newDirection);
    if (bodyPart->GetNextPart() != nullptr) {
        UpdateMovement(newNextDirection, bodyPart->GetNextPart());
    }
}
