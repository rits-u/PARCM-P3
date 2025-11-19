#pragma once

#include "AGameObject.h"
#include "Utils/FadeTransition.h"

class LoadingBar : public AGameObject, public FadeTransition
{
public:
	LoadingBar(String name, int totalAssets);
	//LoadingBar(String name,);
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow* targetWindow);
	void updateLoadingBar(float percentage);

private:
	String textureMap;
	//int totalAssets = 1;
	sf::Sprite* barBorder;
	sf::Sprite* barProgress;
	float progress;
};

