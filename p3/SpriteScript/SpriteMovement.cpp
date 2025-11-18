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

	//std::cout << currTime << std::endl;
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
		{		/*Sprite Rendering*/
			this->sprite = new sf::Sprite();
			this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Suisei_" + std::to_string(counter)));
			sf::Vector2u textureSize = this->sprite->getTexture()->getSize();

			bSwitch = false;

		}
		//Move it
		this->setPosition(100.0f * deltaTime.asSeconds(), 0.0f);
	}

}

std::vector<int> SpriteMovement::traverseList(int counter)
{
	auto i = tuberList.find(counter)->second;
	return i;

}

void SpriteMovement::processInput(sf::Event event) {}
