#pragma once
#include "AGameObject.h"
#include "Utils/FadeTransition.h"

class BGObject : public AGameObject, public FadeTransition
{
	public: 
		BGObject(String name);
		BGObject(String name, String textureMap);
		BGObject(String name, String textureMap, FadeMode initialMode);

		void initialize();
		void processInput(sf::Event event);
		void update(sf::Time deltaTime);
	private:
		String textureMap;
		const float SPEED_MULTIPLIER = 180.0f;
		float scrollOffset = 0.0f;
};

