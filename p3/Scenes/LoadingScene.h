#pragma once
#include "AScene.h"
#include "../SpriteScript/SpriteRunner.h"
#include "../FPSCounter.h"

class LoadingScene : public AScene
{
public:
	LoadingScene();

	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
};

