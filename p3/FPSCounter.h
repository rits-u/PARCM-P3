#pragma once
#include "AGameObject.h"
#include "Utils/SettingsUtils.h"
class FPSCounter :    public AGameObject
{
	public:
		FPSCounter();
		~FPSCounter();
		void initialize() override;
		void processInput(sf::Event event) override;
		void update(sf::Time deltaTime) override;
		void draw(sf::RenderWindow* targetWindow) override;
	
	private:
		sf::Time updateTime;
		sf::Text* statsText;
		int framesPassed = 0;
		float interval = 500;

		void updateFPS(sf::Time elapsedTime);
		
};

