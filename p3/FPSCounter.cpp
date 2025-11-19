#include "FPSCounter.h"
#include "BaseRunner.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

FPSCounter::FPSCounter(): AGameObject("FPSCounter")
{
}

FPSCounter::~FPSCounter()
{
	delete this->statsText->getFont();
	delete this->statsText;
	AGameObject::~AGameObject();
}

void FPSCounter::initialize()
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("Media/Sansation.ttf");

	this->statsText = new sf::Text();
	this->statsText->setFont(*font);
	this->statsText->setFillColor(sf::Color(177, 117, 255));
	this->statsText->setPosition(SettingsUtils::WINDOW_WIDTH - 145, SettingsUtils::WINDOW_HEIGHT - 600);
	this->statsText->setOutlineColor(sf::Color(1.0f, 1.0f, 1.0f));
	this->statsText->setOutlineThickness(2.5f);
	this->statsText->setCharacterSize(24);

	this->updateTime = sf::Time::Zero;
}

void FPSCounter::processInput(sf::Event event)
{
}

void FPSCounter::update(sf::Time deltaTime)
{
	//std::cout << deltaTime.asMicroseconds() << std::endl;
	this->updateFPS(deltaTime);
}

void FPSCounter::draw(sf::RenderWindow* targetWindow)
{
	AGameObject::draw(targetWindow);

	if(this->statsText != nullptr)
		targetWindow->draw(*this->statsText);
}

void FPSCounter::updateFPS(sf::Time elapsedTime)
{
	static float fps = 60.f;
	static float smoothing = 0.9f;

	float currentFPS = 1.f / elapsedTime.asSeconds();
	fps = fps * smoothing + currentFPS * (1.0f - smoothing);

	this->updateTime += elapsedTime;
	
	if (this->updateTime.asSeconds() >= 0.5f) {
		std::stringstream ss;
		ss << "FPS: " << std::fixed << std::setprecision(2) << fps;
		this->statsText->setString(ss.str());
		this->updateTime = sf::Time::Zero;
	}

	if (fps <= 50) {
		std::cout << "FPS dropped below 50" << std::endl;
	}
}
