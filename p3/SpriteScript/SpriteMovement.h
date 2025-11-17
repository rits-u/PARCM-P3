#pragma once
#include <iostream>
#include  "../ThreadTool/IWorkerAction.h"
#include "../ThreadTool/IExecutionEvent.h"
#include <semaphore>
#include <SFML/Graphics.hpp>
#include "../Manager/TextureManager.h"
#include "../AGameObject.h"

class SpriteMovement : public AGameObject, public IWorkerAction
{
public:
	SpriteMovement(std::string _spriteName, IExecutionEvent* callback);

private:
	std::string Name;
	IExecutionEvent* OnFinished;
	void OnStartTask() override;
	void initialize() override;
	void processInput(sf::Event event) override;
	void update(sf::Time deltaTime) override;
	//void draw(sf::RenderWindow* targetWindow) override;
};

