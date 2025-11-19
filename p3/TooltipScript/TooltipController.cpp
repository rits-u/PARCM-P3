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
    //MOUSE INPUT
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && bReleased)
    {
        bClick = true;
        bReleased = false;
    } else if (event.type == event.MouseButtonReleased)
    {
        bReleased = true;
    }
}

void TooltipController::update(sf::Time deltaTime)
{
    if (bClick) 
        {
            if (tipCounter >= 3)tipCounter = 0;
            else tipCounter++;
            bClick = false;
            spawnNextActor();
          
        }
 
}

Tooltip* TooltipController::getCurrentTip()
{
    return this->currentTip;
}

void TooltipController::hideTooltip()
{
    this->disabledTip = true;
}

void TooltipController::spawnNextActor()
{
    removeCurrentActor();

    Tooltip* actor = new Tooltip(name,tipCounter);
    actor->setScale(defaultScale, defaultScale);
    actor->setSwitchTimer(3.0f);

    //register actor
    actor->initialize();
    GameObjectManager::getInstance()->addObject(actor);

   this->currentTip = actor;    
}

void TooltipController::removeCurrentActor()
{
    if (this->currentTip != nullptr) {
        GameObjectManager::getInstance()->deleteObject(this->currentTip);
        this->currentTip = nullptr;
    }
}
