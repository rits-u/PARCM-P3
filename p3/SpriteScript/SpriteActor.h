#pragma once
#include "../AGameObject.h"
#include "../Manager/TextureManager.h"
#include "../Utils/FadeTransition.h"

class SpriteActor : public AGameObject, public FadeTransition
{
public:
	SpriteActor(const std::string& baseName, int frameCount);

	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

	void setSpeed(float speed);
	void setSwitchTimer(float timer);
	//void 

private:
	void updateSpriteTexture();
	int generateRNG(int min, int max);

    std::string baseName;
    int maxFrames = 1;
    int frameIndex = 0;

    float switchTimer = 0.5f;
    float frameTime = 0.0f;

    float speed = 100.0f; //pixels per second
	//bool isAvailable = true;
};



