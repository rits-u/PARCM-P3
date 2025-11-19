#pragma once
#include "../AGameObject.h"
#include "../Manager/TextureManager.h"

class Tooltip : public AGameObject
{
public:
	Tooltip(const std::string& baseName);

	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

	void setSwitchTimer(float timer);

	bool bSwitch = false;

private:
	void updateSpriteTexture();
	void applyScale();

	std::string baseName;
	int maxFrames = 4;
	int frameIndex = 0;

	float switchTimer = 1.0f;
	float frameTime = 0.0f;

	float scale = 0.5f;




};

