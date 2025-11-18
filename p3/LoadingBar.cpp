#include "LoadingBar.h"
#include "Manager/TextureManager.h"

#include <iostream>

LoadingBar::LoadingBar(String name) : AGameObject(name)
{
}

LoadingBar::LoadingBar(String name, String textureMap) : AGameObject(name)
{
	this->textureMap = textureMap;
}

void LoadingBar::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	//assign texture
	this->sprite = new sf::Sprite();
	//sf::Texture* texture = TextureManager::getInstance()->getFromTextureMap("Desert", 0);
	sf::Texture* texture = TextureManager::getInstance()->getFromTextureMap(this->textureMap, 0);
//	texture->setRepeated(true);
	this->sprite->setTexture(*texture);
//	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	//make BG height x k to emulate repeating BG.
	//this->sprite->setTextureRect(sf::IntRect(0, 0, BaseRunner::WINDOW_WIDTH, BaseRunner::WINDOW_HEIGHT * 8));
	//this->setPosition(0, -BaseRunner::WINDOW_HEIGHT * 7);
}

void LoadingBar::processInput(sf::Event event)
{
}

void LoadingBar::update(sf::Time deltaTime)
{
}
