#pragma once
#include "../AGameObject.h"
#include "../Manager/GameObjectManager.h"
#include "SpriteActor.h"

#include <vector>
#include <string>
#include <cstdlib> 
#include <ctime>

class SpriteController : public AGameObject
{
public:
	SpriteController(std::string name);

	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

	SpriteActor* getActor();

private:
	void spawnNextActor();
	void removeCurrentActor();
	int generateRNG(int min, int max);

	std::vector<std::string> characterNames;
	std::unordered_map<int, std::string> characterMap;
	SpriteActor* currentActor = nullptr;

	float spawnX, spawnY;
	float switchX;
	float speed = 200.f;
	float defaultScale = 2.0f;
	int numFrames = 6;
	int currentIndex = 0;
	bool isFading;
	int prevIndex = 0;
	int numCharacters = 5;

};

