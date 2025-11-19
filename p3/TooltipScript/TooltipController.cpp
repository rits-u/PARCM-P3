#include "TooltipController.h"
#include "../BaseRunner.h"

TooltipController::TooltipController(std::string name) : AGameObject(name)
{
    this->currentIndex = 0;

    spawnX = 0.f;
    spawnY = BaseRunner::WINDOW_HEIGHT * 0.25f;
    switchX = (float)BaseRunner::WINDOW_WIDTH / 2.f;
}

void TooltipController::initialize()
{
    spawnNextActor();
}

void TooltipController::processInput(sf::Event event)
{
}

void TooltipController::update(sf::Time deltaTime)
{
    if (currentTip->bSwitch) 
        {
            spawnNextActor();
            currentTip->bSwitch = false;
        }
 
}

void TooltipController::spawnNextActor()
{
    removeCurrentActor();

    //std::string name = characterNames[currentIndex];
    Tooltip* actor = new Tooltip(name);
    //actor->setPosition(spawnX, spawnY);
    //actor->setSpeed(defaultSpeed);
    actor->setScale(defaultScale, defaultScale);
    actor->setSwitchTimer(3.0f);

    //register actor
    actor->initialize();
    GameObjectManager::getInstance()->addObject(actor);

    currentTip = actor;
}

void TooltipController::removeCurrentActor()
{
    if (currentTip != nullptr) {
        GameObjectManager::getInstance()->deleteObject(currentTip);
        currentTip = nullptr;
    }
}
