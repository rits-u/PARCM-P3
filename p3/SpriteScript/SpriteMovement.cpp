#include "SpriteMovement.h"


std::counting_semaphore<2> spriteRoom(1);
SpriteMovement::SpriteMovement(std::string _name) 
{
	this->Name = _name;
}

void SpriteMovement::OnStartTask()
{
	spriteRoom.acquire();

	//Get the sprite frame

	//Move it

	std::cout << "Task working" << std::endl;

	spriteRoom.release();
}