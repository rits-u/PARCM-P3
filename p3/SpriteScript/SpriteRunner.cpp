#include "SpriteRunner.h"

SpriteRunner::SpriteRunner() : AGameObject("SpriteRunner") {}

SpriteRunner::~SpriteRunner()
{
	/*delete this->statsText->getFont();
	delete this->statsText;*/
	AGameObject::~AGameObject();
}

void SpriteRunner::initialize()
{
	// Assigning tasks to each Component

	//SPRITES
	for (int i = 0; i < 1; i++)
	{
		//Assign the pool with the task
		SpriteMovement* task = new SpriteMovement();
		spritePool.ScheduleTasks(task);

	}

	/*Start the pool*/
	startPool();
}

void SpriteRunner::startPool()
{
	/*Starts the first pool*/
	spritePool.StartScheduling();
	spritePool.run();
}

void SpriteRunner::OnFinishedExecution(int _currIdNum)
{
	std::clog << "Sprite Number:  " << _currIdNum << "IS DONE!\n";
}

void SpriteRunner::processInput(sf::Event event) {}
void SpriteRunner::update(sf::Time deltaTime) {}
//void SpriteRunner::draw(sf::RenderWindow* targetWindow) {}