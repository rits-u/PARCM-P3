#pragma once

#include "../IExecutionEvent.h"
#include "../ThreadPool.h"
#include "SpriteMovement.h"
#include "../AGameObject.h"


class SpriteRunner : public AGameObject, public IExecutionEvent
{
public:

	//Holds sprites for Suisei, Pekora, Ollie, Fauna and Aqua 5 Threads
	ThreadPool spritePool = ThreadPool(1);

	SpriteRunner();

	//Starts the pool for the sprites
	void startPool();

	//When they are done running in screen
	void OnFinishedExecution(int _spriteId) override;

	//AGameObject overrides
	~SpriteRunner();
	void initialize() override;
	void processInput(sf::Event event) override;
	void update(sf::Time deltaTime) override;
	//void draw(sf::RenderWindow* targetWindow) override;
};

