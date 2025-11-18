#pragma once

#include "AGameObject.h"

class LoadingBar : public AGameObject
{
public:
	LoadingBar(String name);
	LoadingBar(String name, String textureMap);
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

private:
	String textureMap;
};

