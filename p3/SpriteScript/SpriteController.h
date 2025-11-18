#pragma once
#include "../AGameObject.h"
#include "../Manager/GameObjectManager.h"
#include "SpriteActor.h"

#include <vector>
#include <string>

class SpriteController : public AGameObject
{
public:
	SpriteController();

	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
};

