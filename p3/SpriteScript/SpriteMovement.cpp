#include "SpriteMovement.h"


std::counting_semaphore<1> spriteRoom(1);
SpriteMovement::SpriteMovement(std::string _name, IExecutionEvent* _callback) : AGameObject(_name)
{
	this->Name = _name;
	this->OnFinished = _callback;
}

SpriteMovement::~SpriteMovement()
{
	std::cout << "DESTYORR" << std::endl;
	AGameObject::~AGameObject();
	
}

void SpriteMovement::initialize()
{
	//assign texture
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture(this->Name  + '0'));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();

	this->setPosition(0,0);
}

void SpriteMovement::OnStartTask()
{
	spriteRoom.acquire();
	//FInished the thread
		//if all sprites are done call this
	this->OnFinished->OnFinishedExecution();
	spriteRoom.release();

}

void SpriteMovement::update(sf::Time deltaTime)  {}
void SpriteMovement::processInput(sf::Event event) {}
