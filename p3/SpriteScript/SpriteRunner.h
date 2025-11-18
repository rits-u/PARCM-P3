#pragma once

#include "../ThreadTool/IExecutionEvent.h"
#include "../ThreadTool/ThreadPool.h"
#include "SpriteMovement.h"
#include "../AGameObject.h"
#include "../Manager/GameObjectManager.h"

class SpriteRunner : public AGameObject, public IExecutionEvent
{
public:

	//Holds sprites for Suisei, Pekora, Ollie, Fauna and Aqua 5 Threads
	ThreadPool spritePool = ThreadPool(1);
	std::string VtuberNames[2] = { "Suisei","Pekora" };

	SpriteMovement* currSprite;

	SpriteRunner();

	//Starts the pool for the sprites
	void startPool();

	//When they are done running in screen
	void OnFinishedExecution() override;

	//AGameObject overrides
	~SpriteRunner();
	void initialize() override;
	void processInput(sf::Event event) override;
	void update(sf::Time deltaTime) override;

	/*For sprite visual movement*/
	float switchTimer = 0.1f, currTime = 0.0f;
	float speedRate = 0.0f;
	bool bSwitch = false;
	bool bStart = false;
	int frameCounter = 0, threadCounter = 0;
};

