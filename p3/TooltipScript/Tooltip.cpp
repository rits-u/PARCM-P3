#include "Tooltip.h"
#include "../BaseRunner.h"
#include <iostream>

Tooltip::Tooltip(const std::string& baseName, const int& tipCounter) : AGameObject(baseName)
{
    this->baseName = baseName;
    this->counterTip = tipCounter;
}

void Tooltip::initialize()
{
    this->sprite = new sf::Sprite();
    updateSpriteTexture();
    applyScale();

    //270.0f
    this->setPosition(BaseRunner::WINDOW_WIDTH/6.62f, 83.0f);
    this->changeFadeMode(FADE_OUT);
}

void Tooltip::processInput(sf::Event event) {}

void Tooltip::update(sf::Time deltaTime) {
    if (isFading) {
        applyFadeTransition(deltaTime);
        this->sprite->setColor(sf::Color(255, 255, 255, this->alphaValue));
    }
}

void Tooltip::setSwitchTimer(float timer)
{
    this->switchTimer = timer;
}

void Tooltip::updateSpriteTexture()
{
    std::string texName = "Tooltip" + std::to_string(counterTip);
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
