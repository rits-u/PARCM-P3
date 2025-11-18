#include "SpriteMovement.h"



SpriteMovement::SpriteMovement(std::string _name, IExecutionEvent* _callback) : AGameObject(_name)
{
	this->Name = _name;
	this->OnFinished = _callback;
}

void SpriteMovement::initialize()
{
	//assign texture
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Suisei_" + std::to_string(counter)));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
}

void SpriteMovement::OnStartTask()
{
	//Start the running
	bStart = true;
	//FInished the thread
	this->OnFinished->OnFinishedExecution();
}

void SpriteMovement::update(sf::Time deltaTime) 
{
	currTime += deltaTime.asSeconds();
	if (currTime >= switchTimer)
	{
		this->bSwitch = true;
		currTime = 0.0f;

		counter++;
		if (counter >= 6) counter = 0;
		std::cout << "SWITCH! to counter " << counter << std::endl;
	}

	if (bStart)
	{
		if (this->bSwitch)
		{		
			/*Sprite Rendering*/
			this->sprite = new sf::Sprite();
			this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Suisei_" + std::to_string(counter)));
			sf::Vector2u textureSize = this->sprite->getTexture()->getSize();

			bSwitch = false;

		}
		//Move it
		speedRate += (200.0f * deltaTime.asSeconds());
		this->setPosition(speedRate, 0.0f);
		//std::cout << this->getPosition().x << std::endl;
	}

}

std::vector<int> SpriteMovement::traverseList(int counter)
{
	auto i = tuberList.find(counter)->second;
	return i;

}

void SpriteMovement::processInput(sf::Event event) {}
