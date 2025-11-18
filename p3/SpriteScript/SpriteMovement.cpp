#include "SpriteMovement.h"



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
		//std::cout << "SWITCH! to counter " << counter << std::endl;
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

		//if it reaches the "end", destroy GameObject and remove it from Manager
		if (this->getPosition().x >= (SettingsUtils::WINDOW_WIDTH/2))
		{
			bStart = false;

			GameObjectManager::getInstance()->deleteObject(this);
		}
	}

}
void SpriteMovement::processInput(sf::Event event) {}
