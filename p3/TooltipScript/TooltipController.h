#pragma once
#include "../AGameObject.h"
#include "../Manager/GameObjectManager.h"
#include "Tooltip.h"

#include <vector>
#include <string>
#include <iostream>

class TooltipController : public AGameObject
{
public:
	TooltipController(std::string name);

	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

private:
	void spawnNextActor();
	void removeCurrentActor();

	int currentIndex = 0;

	Tooltip* currentTip = nullptr;

	bool bClick = false;
	bool bReleased = true;

	int tipCounter = 0;

	float spawnX = 0.f, spawnY = 0.f;
	float switchX = 0.f;
	float defaultSpeed = 200.f;
	float defaultScale = 0.5f;
	int numFrames = 1;

};

