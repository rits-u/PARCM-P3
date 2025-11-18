#include "TextureDisplay.h"
#include <iostream>
#include "Manager/TextureManager.h"
#include "BaseRunner.h"
#include "Manager/GameObjectManager.h"
#include "IconObject.h"


TextureDisplay::TextureDisplay(): AGameObject("TextureDisplay")
{
	this->loadedAsset = 0;
	this->assetsTotal = 47;
	this->mode = FADE_OUT;
}

void TextureDisplay::initialize()
{
	this->threadPool.StartScheduling();
}

void TextureDisplay::processInput(sf::Event event)
{
	
}

void TextureDisplay::update(sf::Time deltaTime)
{
	//int assetsTotal = 47;
	this->ticks += BaseRunner::TIME_PER_FRAME.asMilliseconds();
	//std::cout << "ticks: " << this->ticks << std::endl;

	if (this->ticks >= STREAMING_LOAD_DELAY) {

		int texCount = TextureManager::getInstance()->getNumLoadedStreamTextures();
	//	std::cout << "texCount: " << texCount << std::endl;
		if (texCount < this->assetsTotal) {
			LoadAssetThread* asset = new LoadAssetThread(texCount, this);
			asset->SetNumAsset(this->assetsTotal);

			switch (this->streamingType) {
				case SINGLE_STREAM:
					asset->SetMode(false);
					break;
				case BATCH_LOAD:
					asset->SetMode(true);
					asset->SetBatchSize(5);
					break;
			}

			this->threadPool.ScheduleTasks(asset);
		}

		this->ticks = 0;
		
	}

	if (this->isFading)
		fadeTransition(deltaTime);

}

void TextureDisplay::draw(sf::RenderWindow* targetWindow)
{
	sf::RectangleShape fadeRect;
	fadeRect.setSize(sf::Vector2f(BaseRunner::WINDOW_WIDTH, BaseRunner::WINDOW_HEIGHT));
	fadeRect.setFillColor(sf::Color(0, 0, 0, this->alphaValue));
	targetWindow->draw(fadeRect);
}



void TextureDisplay::OnFinishedExecution(int _id)
{
	
	this->loadedAsset++;
	std::cout << "asset " << this->loadedAsset << std::endl;
	
	if (this->loadedAsset >= this->assetsTotal) {
		this->isFading = true; 
		IETThread::sleep(3000);

		spawnAllObjects();
		
	}
}

void TextureDisplay::spawnObject()
{
	//std::cout << "hello" << std::endl;
	guard.lock();
	String objectName = "Icon_" + to_string(this->iconList.size());
	IconObject* iconObj = new IconObject(objectName, this->iconList.size());
	this->iconList.push_back(iconObj);

	//set scale
	sf::Vector2f scale(0.125f, 0.125f);

	int spacing = 6;

	//set position
	//int IMG_WIDTH = 68; int IMG_HEIGHT = 68;
	int IMG_WIDTH = 1032 * scale.x + spacing; int IMG_HEIGHT = 912 * scale.y + spacing; //1032 912
	float x = this->columnGrid * IMG_WIDTH;
	float y = this->rowGrid * IMG_HEIGHT;
	iconObj->setPosition(x, y);
	guard.unlock();

	this->columnGrid++;
	if(this->columnGrid == this->MAX_COLUMN)
	{
		this->columnGrid = 0;
		this->rowGrid++;
	}
	GameObjectManager::getInstance()->addObject(iconObj);
}

void TextureDisplay::spawnAllObjects()
{
	this->isFading = true;
	//IETThread::sleep(3000);

	GameObjectManager::getInstance()->findObjectByName("LoadingScreenBG")->setActiveSelf(false);
	GameObjectManager::getInstance()->findObjectByName("GameSceneBG")->setActiveSelf(true);

	for (int i = 0; i < this->assetsTotal; i++) {
		this->spawnObject();
		this->iconList[i]->setIsFading(true);
	}


}