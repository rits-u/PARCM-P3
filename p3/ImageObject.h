#pragma once
#include "AGameObject.h"
#include "Utils/FadeTransition.h"


class ImageObject : public AGameObject, public FadeTransition
{
public:
	ImageObject(String name, String textureMap, FadeMode initialMode);

	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
private:
	String textureMap;
};

