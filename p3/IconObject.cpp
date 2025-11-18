#include "IconObject.h"
#include <iostream>
#include "BaseRunner.h"
#include "Manager/TextureManager.h"

IconObject::IconObject(String name, int textureIndex): AGameObject(name)
{
	this->textureIndex = textureIndex;
	//this->sprite->setTexture(*TextureManager::getInstance()->getByIndex(textureIndex));
	//this->sprite->setTexture(*TextureManager::getInstance()->getStreamTextureFromList(textureIndex));
}

void IconObject::initialize()
{
	//assign texture
	this->sprite = new sf::Sprite();
	sf::Texture* texture = TextureManager::getInstance()->getStreamTextureFromList(this->textureIndex);
	this->sprite->setTexture(*texture);
	this->sprite->setScale(0.125f, 0.125f);

	//auto tex = TextureManager::getInstance()->getStreamTextureFromList(this->textureIndex);
	//std::cout << "Texture: " << tex->getSize().x << ", " << tex->getSize().y << std::endl;
}

void IconObject::processInput(sf::Event event)
{
}

void IconObject::update(sf::Time deltaTime)
{
}
