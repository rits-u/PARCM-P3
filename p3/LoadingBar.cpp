#include "LoadingBar.h"
#include "Manager/TextureManager.h"

#include <iostream>
#include <algorithm>

LoadingBar::LoadingBar(String name, int totalAssets) : AGameObject(name)
{
	this->barBorder = new sf::Sprite();
	this->barProgress = new sf::Sprite();
}

void LoadingBar::initialize()
{ 
	std::cout << "Declared as " << this->getName() << "\n";

	sf::Texture* borderTex = TextureManager::getInstance()->getFromTextureMap("bar_border", 0);
	this->barBorder->setTexture(*borderTex);

	sf::Texture* progressTex = TextureManager::getInstance()->getFromTextureMap("bar_progress", 0);
	this->barProgress->setTexture(*progressTex);
	this->barBorder->setPosition(230.0f, 644.f);
	this->barProgress->setPosition(239.0f, 650.f);

	this->changeFadeMode(FADE_OUT);
}

void LoadingBar::processInput(sf::Event event)
{
}

void LoadingBar::update(sf::Time deltaTime)
{
	if (this->isFading) {
		this->barBorder->setColor(sf::Color(255, 255, 255, this->alphaValue));
		this->barProgress->setColor(sf::Color(255, 255, 255, this->alphaValue));
	}
}

void LoadingBar::draw(sf::RenderWindow* targetWindow)
{
	targetWindow->draw(*this->barBorder);
	targetWindow->draw(*this->barProgress);
}

void LoadingBar::updateLoadingBar(float percentage)
{
	this->progress = std::clamp(percentage, 0.0f, 1.0f);
	sf::IntRect rect = this->barProgress->getTextureRect();
	rect.width = this->barProgress->getTexture()->getSize().x * this->progress;
	this->barProgress->setTextureRect(rect);
}
