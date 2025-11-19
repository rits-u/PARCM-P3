#include "SpriteController.h"
#include "../BaseRunner.h"
#include <iostream>

SpriteController::SpriteController(std::string name) : AGameObject(name)
{
    srand(time(nullptr));
    this->characterNames = { "Suisei", "Pekora", "Ollie", "Fauna", "Aqua", 
                             "Amelia", "Ayame", "Azki", "Fubuki", "Gura",
                             "Korone", "Kronii", "Marine", "Matsuri", "Miko",
                             "Moona", "Mumei", "Subaru", "Towa", "Watame"};
    this->prevIndex = -1;
}

void SpriteController::initialize()
{
    this->switchX = (float)BaseRunner::WINDOW_WIDTH + 5.0f;
    spawnNextActor();
}

void SpriteController::processInput(sf::Event event)
{
}

void SpriteController::update(sf::Time deltaTime)
{
    if (this->currentActor) {
        sf::Vector2f pos = this->currentActor->getPosition();

        //swap actors when target position is reached
        if (pos.x >= switchX) {
            spawnNextActor();
           /* this->currentIndex++;         //in order
            if (this->currentIndex >= (int)this->characterNames.size())
                this->currentIndex = 0;*/

        }
    }
    else {
        //no current actor
        spawnNextActor();
    }
}

SpriteActor* SpriteController::getActor()
{
    return this->currentActor;
}

void SpriteController::spawnNextActor()
{
    removeCurrentActor();

    //int random = 0;
    //do {
    int random = generateRNG(0, this->numCharacters - 1);
    //} while (random != this->prevIndex);

    std::string name = this->characterNames[random];
   // std::string name = this->characterNames[this->currentIndex];
    SpriteActor* actor = new SpriteActor(name, this->numFrames);
    actor->setPosition(this->spawnX, this->spawnY);
    actor->setSwitchTimer(0.1f);

    //register actor
    actor->initialize();
    GameObjectManager::getInstance()->addObject(actor);

    this->currentActor = actor;
}

void SpriteController::removeCurrentActor()
{
    if (this->currentActor != nullptr) {
        GameObjectManager::getInstance()->deleteObject(this->currentActor);
        this->currentActor = nullptr;
    }
}

int SpriteController::generateRNG(int min, int max)
{
    return min + rand() % (max - min + 1);
}
