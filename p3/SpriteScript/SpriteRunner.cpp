#include "SpriteRunner.h"

SpriteRunner::SpriteRunner() : AGameObject("SpriteRunner") 
{
}

SpriteRunner::~SpriteRunner()
{
	/*delete this->statsText->getFont();
	delete this->statsText;*/
	AGameObject::~AGameObject();
}

void SpriteRunner::initialize()
{
	//SPRITES
	
	for (int i = 0; i <= 1; i++)
	{
		//Assign the pool with the task
		SpriteMovement* task = new SpriteMovement(VtuberNames[i], this);
		spritePool.ScheduleTasks(task);
		GameObjectManager::getInstance()->addObject(task);

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

void SpriteRunner::OnFinishedExecution()
{
	std::clog << "Sprite has been released\n";
}

void SpriteRunner::processInput(sf::Event event) {}
void SpriteRunner::update(sf::Time deltaTime) 
{
	
}
//void SpriteRunner::draw(sf::RenderWindow* targetWindow) {}

