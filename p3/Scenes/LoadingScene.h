#pragma once
#include "AScene.h"
#include "../SpriteScript/SpriteRunner.h"

class LoadingScene : public AScene
{
public:
	LoadingScene();

	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
};

