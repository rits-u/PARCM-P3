#include "LoadingScene.h"


LoadingScene::LoadingScene() : AScene("LoadingScene") {}


void LoadingScene::onLoadResources() {}

void LoadingScene::onLoadObjects()
{
    SpriteRunner* runner = new SpriteRunner();
    this->registerObject(runner);

    FPSCounter* fpsCounter = new FPSCounter();
    GameObjectManager::getInstance()->addObject(fpsCounter);
}

void LoadingScene::onUnloadResources() {}
