#include "Tooltip.h"
#include "../BaseRunner.h"
#include <iostream>

Tooltip::Tooltip(const std::string& baseName) : AGameObject(baseName)
{
    this->baseName = baseName;
}

void Tooltip::initialize()
{
    this->sprite = new sf::Sprite();
    updateSpriteTexture();
    applyScale();

    this->setPosition(BaseRunner::WINDOW_WIDTH/2.0f, 0);

    //if (this->getPosition().x == 0 && this->getPosition().y == 0) {
      //  this->setPosition(BaseRunner::WINDOW_WIDTH/2.0f, (float)BaseRunner::WINDOW_HEIGHT * 0.25f);
   // }
}

void Tooltip::processInput(sf::Event event)
{
}

void Tooltip::update(sf::Time deltaTime)
{
    //frame switch update
    frameTime += deltaTime.asSeconds();
    if (frameTime >= switchTimer) {
        frameTime = 0.0f;
        frameIndex++;
        if (frameIndex >= maxFrames) frameIndex = 0;
        updateSpriteTexture();
        bSwitch = true;

    }
}

void Tooltip::setSwitchTimer(float timer)
{
    this->switchTimer = timer;
}

void Tooltip::updateSpriteTexture()
{

    std::string texName = "Tooltip" + std::to_string(frameIndex);
    sf::Texture* tex = TextureManager::getInstance()->getTooltip(texName);
    if (tex != nullptr) {
        this->sprite->setTexture(*tex);
    }
    else {
        //missing texture
        std::cout << "Missing texture for " << texName << std::endl;
    }
}

void Tooltip::applyScale()
{
    if (this->sprite)
        this->sprite->setScale(scale, scale);
}
