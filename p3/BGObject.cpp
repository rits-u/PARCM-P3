#include "BGObject.h"
#include <iostream>
#include "Manager/TextureManager.h"
#include "BaseRunner.h"

BGObject::BGObject(string name) : AGameObject(name)
{
}

void BGObject::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	//assign texture
	this->sprite = new sf::Sprite();
	//sf::Texture* texture = TextureManager::getInstance()->getFromTextureMap("Desert", 0);
	sf::Texture* texture = TextureManager::getInstance()->getFromTextureMap("HoloCureBG", 0);
	texture->setRepeated(true);
	this->sprite->setTexture(*texture);
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	//make BG height x k to emulate repeating BG.
	this->sprite->setTextureRect(sf::IntRect(0,0,BaseRunner::WINDOW_WIDTH, BaseRunner::WINDOW_HEIGHT * 8)); 
	this->setPosition(0, -BaseRunner::WINDOW_HEIGHT * 7);
}

void BGObject::processInput(sf::Event event)
{
}

void BGObject::update(sf::Time deltaTime)
{
	//make BG scroll slowly
	//sf::Vector2f position = this->getPosition();
	//position.y += this->SPEED_MULTIPLIER * deltaTime.asSeconds();
	//this->setPosition(position.x, position.y);

	//sf::Vector2f localPos = this->sprite->getPosition();
	//if (localPos.y * deltaTime.asSeconds() > 0) {
	//	//reset position
	//	this->setPosition(0, -BaseRunner::WINDOW_HEIGHT * 7);
	//
	//}
	//else {
	//	
	//}

	//make BG scroll slowly
	scrollOffset += SPEED_MULTIPLIER * deltaTime.asSeconds();

	//wrap around when offset exceeds texture width
	float textureWidth = (float)this->sprite->getTexture()->getSize().x;
	if (scrollOffset > textureWidth) scrollOffset -= textureWidth;

	// simulate scrolling
	sf::IntRect rect = this->sprite->getTextureRect();
	rect.left = (int)scrollOffset;   
	this->sprite->setTextureRect(rect);
}
