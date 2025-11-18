#pragma once
#include "../AGameObject.h"
#include "../Manager/GameObjectManager.h"
#include "SpriteActor.h"

#include <vector>
#include <string>

class SpriteController : public AGameObject
{
public:
	SpriteController(std::string name);

	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

private:
	void spawnNextActor();
	void removeCurrentActor();

	std::vector<std::string> characterNames;
	int currentIndex = 0;

	SpriteActor* currentActor = nullptr;

	float spawnX = 0.f, spawnY = 0.f;
	float switchX = 0.f;
	float defaultSpeed = 200.f;
	float defaultScale = 0.5f;
	int numFrames = 6;

};

