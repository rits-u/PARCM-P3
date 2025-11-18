#pragma once
#include <iostream>
#include <string>
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

	/*For sprite visual movement*/
	//void prepareVtuberSpriteSheet();
	std::unordered_map<int, std::vector<int>> tuberList;
	std::vector<int> coord;
	float switchTimer = 0.1f, currTime = 0.0f;
	float speedRate = 0.0f;
	bool bSwitch = false;
	bool bFinishLine = false;
	bool bStart = false;
	sf::IntRect currSprite;
	int counter = 0;
	std::vector<int> traverseList(int counter);
};

