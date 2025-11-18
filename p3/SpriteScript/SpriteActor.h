#pragma once
#include "../AGameObject.h"
#include "../Manager/TextureManager.h"

class SpriteActor : public AGameObject
{
public:
	SpriteActor(const std::string& baseName, int frameCount);

	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

	void setSpeed(float speed);
	void setSwitchTimer(float timer);
	void setScaleFactor(float scale);

private:
	void updateSpriteTexture();
	void applyScale();

    std::string baseName;
    int maxFrames = 1;
    int frameIndex = 0;

    float switchTimer = 0.1f;
    float frameTime = 0.0f;

    float speed = 100.0f; // pixels per second
    float scale = 1.0f;


};

