#include "SpriteRunner.h"
#include "../BaseRunner.h"

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

	/*Starts the first pool*/
	SpriteMovement* task = new SpriteMovement(VtuberNames[threadCounter], this);
	currSprite = task;
	spritePool.ScheduleTasks(task);
	GameObjectManager::getInstance()->addObject(currSprite);
	bStart = true;

	/*Start the pool*/
	startPool();
}

void SpriteRunner::startPool()
{

	//SPRITES
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

	std::cout << "THREAD COUNTER IS " << threadCounter << std::endl;
	currTime += deltaTime.asSeconds();
	if (currTime >= switchTimer)
	{
		this->bSwitch = true;
		currTime = 0.0f;

		frameCounter++;
		if (frameCounter >= 6) frameCounter = 0;
	}

	if (bStart)
	{
		//SWITCH FRAMES
		if (this->bSwitch)
		{
			/*Sprite Rendering*/
			currSprite->sprite = new sf::Sprite();
			currSprite->sprite->setTexture(*TextureManager::getInstance()->getTexture(VtuberNames[threadCounter] + std::to_string(frameCounter)));
			sf::Vector2u textureSize = currSprite->sprite->getTexture()->getSize();

			bSwitch = false;

		}


		//Move it
		speedRate += (200.0f * deltaTime.asSeconds());
		currSprite->setPosition(speedRate, 0.0f);
	}



		//SWITCH CHARACTER
		//if it reaches the "end", destroy GameObject and remove it from Manager
		if (currSprite->getPosition().x >= (SettingsUtils::WINDOW_WIDTH / 2))
		{
			//"Freeze" the old thread pos
			//urrSprite->setPosition(currSprite->getPosition().x, currSprite->getPosition().y);
			

			threadCounter++;
			if (threadCounter >= 2) threadCounter = 0;

			bStart = false;
			GameObjectManager::getInstance()->deleteObject(currSprite);
			SpriteMovement* newtask = new SpriteMovement(VtuberNames[threadCounter], this);
			spritePool.ScheduleTasks(newtask);
			GameObjectManager::getInstance()->addObject(newtask);
			currSprite = newtask;

			speedRate = 0.0f;

			
			

			bStart = true;
			
		}

}


