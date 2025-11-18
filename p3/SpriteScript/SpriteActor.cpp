#include "SpriteActor.h"
#include "../BaseRunner.h"
#include <iostream>

SpriteActor::SpriteActor(const std::string& baseName, int frameCount) : AGameObject(baseName)
{
	this->baseName = baseName;
	this->maxFrames = frameCount;
}

void SpriteActor::initialize()
{
	this->sprite = new sf::Sprite();
	updateSpriteTexture();
	applyScale();

	if (this->getPosition().x == 0 && this->getPosition().y == 0) {
		this->setPosition(0.f, (float)BaseRunner::WINDOW_HEIGHT * 0.25f);
	}
}

void SpriteActor::processInput(sf::Event event)
{
}

void SpriteActor::update(sf::Time deltaTime)
{
    //frame switch update
    frameTime += deltaTime.asSeconds();
    if (frameTime >= switchTimer) {
        frameTime = 0.0f;
        frameIndex++;
        if (frameIndex >= maxFrames) frameIndex = 0;
        updateSpriteTexture();
    }

    //movement of the sprite
    sf::Vector2f pos = this->getPosition();
    pos.x += speed * deltaTime.asSeconds();
    this->setPosition(pos.x, pos.y);
}

void SpriteActor::setSpeed(float speed)
{
    this->speed = speed;
}

void SpriteActor::setSwitchTimer(float timer)
{
    this->switchTimer = timer;
}

void SpriteActor::setScaleFactor(float scale)
{
    this->scale = scale;
}

void SpriteActor::updateSpriteTexture()
{
    std::string texName = baseName + std::to_string(frameIndex);
    sf::Texture* tex = TextureManager::getInstance()->getTexture(texName);
    if (tex != nullptr) {
        this->sprite->setTexture(*tex);
    }
    else {
        //missing texture
    }
}

void SpriteActor::applyScale()
{
    if (this->sprite)
        this->sprite->setScale(scale, scale);
}

