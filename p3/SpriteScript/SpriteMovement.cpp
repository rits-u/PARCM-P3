#include "SpriteMovement.h"


std::counting_semaphore<1> spriteRoom(1);
SpriteMovement::SpriteMovement(std::string _name, IExecutionEvent* _callback) : AGameObject(_name)
{
	this->Name = _name;
	this->OnFinished = _callback;
}

void SpriteMovement::initialize()
{
	//assign texture
	this->sprite = new sf::Sprite();
	sf::Texture* texture = TextureManager::getInstance()->getTexture("Suisei");
	this->sprite->setTexture(*texture);
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
}

void SpriteMovement::OnStartTask()
{
	spriteRoom.acquire();

	//Get the sprite frame
	


	//Move it

	std::cout << "Task working" << std::endl;

	spriteRoom.release();


	this->OnFinished->OnFinishedExecution();
}


void SpriteMovement::processInput(sf::Event event) {}
void SpriteMovement::update(sf::Time deltaTime) {}