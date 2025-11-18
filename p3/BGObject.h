#pragma once
#include "AGameObject.h"
class BGObject : public AGameObject
{
	public: 
		BGObject(String name);
		BGObject(String name, String textureMap);
		void initialize();
		void processInput(sf::Event event);
		void update(sf::Time deltaTime);
	private:
		String textureMap;
		const float SPEED_MULTIPLIER = 200.0f;
		float scrollOffset = 0.0f;
};

