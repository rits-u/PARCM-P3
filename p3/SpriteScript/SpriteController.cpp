#include "SpriteController.h"
#include "../BaseRunner.h"

SpriteController::SpriteController(std::string name) : AGameObject(name)
{
    this->characterNames = { "Suisei", "Pekora" };
    this->currentIndex = 0;

    spawnX = 0.f;
    spawnY = BaseRunner::WINDOW_HEIGHT * 0.25f;
    switchX = (float)BaseRunner::WINDOW_WIDTH / 2.f;
}

void SpriteController::initialize()
{
    spawnNextActor();
}

void SpriteController::processInput(sf::Event event)
{
}

void SpriteController::update(sf::Time deltaTime)
{
    if (currentActor) {
        sf::Vector2f pos = currentActor->getPosition();
        if (pos.x >= switchX) {

            //swap actors when target position is reached
            currentIndex++;
            if (currentIndex >= (int)characterNames.size())
                currentIndex = 0;
            spawnNextActor();
        }
    }
    else {
        //no current actor
        spawnNextActor();
    }
}

void SpriteController::spawnNextActor()
{
    removeCurrentActor();

    std::string name = characterNames[currentIndex];
    SpriteActor* actor = new SpriteActor(name, numFrames);
    actor->setPosition(spawnX, spawnY);
    actor->setSpeed(defaultSpeed);
    actor->setScale(defaultScale, defaultScale);
    actor->setSwitchTimer(0.1f);

    //register actor
    actor->initialize();
    GameObjectManager::getInstance()->addObject(actor);

    currentActor = actor;
}

void SpriteController::removeCurrentActor()
{
    if (currentActor != nullptr) {
        GameObjectManager::getInstance()->deleteObject(currentActor);
        currentActor = nullptr;
    }
}
