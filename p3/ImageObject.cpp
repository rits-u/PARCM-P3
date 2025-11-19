#include "ImageObject.h"
#include "Manager/TextureManager.h"
#include "BaseRunner.h"

#include <iostream>

ImageObject::ImageObject(String name, String textureMap, FadeMode initialMode) : AGameObject(name)
{
	this->textureMap = textureMap;
	this->mode = initialMode;
	switch (initialMode) {
	case FADE_IN:
		this->alphaValue = 0.0f;
		break;
	case FADE_OUT:
		this->alphaValue = 255.0f;
		break;
	}

}

void ImageObject::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	//assign texture
	this->sprite = new sf::Sprite();
	sf::Texture* texture = TextureManager::getInstance()->getFromTextureMap(this->textureMap, 0);
	texture->setRepeated(true);
	this->sprite->setTexture(*texture);
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();

	this->setPosition(BaseRunner::WINDOW_WIDTH * 0.32, BaseRunner::WINDOW_HEIGHT * 0.11);
	this->setScale(0.5f, 0.5f);

}

void ImageObject::processInput(sf::Event event)
{
}

void ImageObject::update(sf::Time deltaTime)
{
	if (isFading) {
		applyFadeTransition(deltaTime);
		this->sprite->setColor(sf::Color(255, 255, 255, this->alphaValue));
	}
}
