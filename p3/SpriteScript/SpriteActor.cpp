#include "SpriteActor.h"
#include "../BaseRunner.h"
#include <iostream>

SpriteActor::SpriteActor(const std::string& baseName, int frameCount) : AGameObject(baseName)
{
	this->baseName = baseName;
	this->maxFrames = frameCount;
    this->alphaValue = 255.0f;
    this->mode = FADE_OUT;
}

void SpriteActor::initialize()
{
	this->sprite = new sf::Sprite();
    this->setPosition(-20.0f, 370.0f);
    this->setScale(2.5f, 2.5f);
    this->speed = 300.0f;
    updateSpriteTexture();
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

    if (isFading) {
        applyFadeTransition(deltaTime);
        this->sprite->setColor(sf::Color(255, 255, 255, this->alphaValue));

        if (this->alphaValue <= 0)
            this->isActive = false;

    }
}

void SpriteActor::setSpeed(float speed)
{
    this->speed = speed;
}

void SpriteActor::setSwitchTimer(float timer)
{
    this->switchTimer = timer;
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

int SpriteActor::generateRNG(int min, int max)
{
    return min + rand() % (max - min + 1);
}


