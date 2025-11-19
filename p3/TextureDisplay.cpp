#include "TextureDisplay.h"
#include <iostream>
#include "Manager/TextureManager.h"
#include "BaseRunner.h"
#include "Manager/GameObjectManager.h"
#include "IconObject.h"
#include "BGObject.h"
#include "SpriteScript/SpriteController.h"
#include "TooltipScript/TooltipController.h"	


TextureDisplay::TextureDisplay(): AGameObject("TextureDisplay")
{
}

void TextureDisplay::initialize()
{
	this->loadedAsset = 0;
	this->assetsTotal = 47;
	makeLoadingBar();
	this->loadingBar->updateLoadingBar((float)this->loadedAsset / (float)this->assetsTotal);
	this->threadPool.StartScheduling();
}

void TextureDisplay::processInput(sf::Event event)
{
	
}

void TextureDisplay::update(sf::Time deltaTime)
{
	this->ticks += BaseRunner::TIME_PER_FRAME.asMilliseconds();
	//std::cout << "ticks: " << this->ticks << std::endl;

	if (this->ticks >= STREAMING_LOAD_DELAY) {

		int texCount = TextureManager::getInstance()->getNumLoadedStreamTextures();
		//std::cout << "texCount: " << texCount << std::endl;
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
}

void TextureDisplay::OnFinishedExecution()
{
	this->loadedAsset++;
	this->loadingBar->updateLoadingBar((float)this->loadedAsset / (float)this->assetsTotal);
	std::cout << "asset " << this->loadedAsset << std::endl;

	if (this->loadedAsset >= this->assetsTotal) {
		IETThread::sleep(1250);
		spawnAllObjects();
		FadeOutAll();
		IETThread::sleep(3000);
		FadeInAll();
	}
}

void TextureDisplay::spawnObject()
{
	guard.lock();
	String objectName = "Icon_" + to_string(this->iconList.size());
	IconObject* iconObj = new IconObject(objectName, this->iconList.size());
	this->iconList.push_back(iconObj);

	//set scale
	sf::Vector2f scale(0.125f, 0.125f);

	int spacing = 6;

	//set position
	int IMG_WIDTH = 1032 * scale.x + spacing; int IMG_HEIGHT = 912 * scale.y + spacing; //1032 912
	float x = this->columnGrid * IMG_WIDTH;
	float y = this->rowGrid * IMG_HEIGHT;
	iconObj->setPosition(x, y);
	iconObj->setActiveSelf(false);
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
	for (int i = 0; i < this->assetsTotal; i++) {
		this->spawnObject();
	}
}

void TextureDisplay::FadeOutAll()
{
	BGObject* bg = (BGObject*)GameObjectManager::getInstance()->findObjectByName("LoadingScreenBG");
	bg->setIsFading(true);

	BGObject* logo = (BGObject*)GameObjectManager::getInstance()->findObjectByName("GameLogo");
	logo->setIsFading(true);

	SpriteController* sController = (SpriteController*)GameObjectManager::getInstance()->findObjectByName("SpriteController");
	sController->getActor()->setIsFading(true);
	GameObjectManager::getInstance()->deleteObjectByName("SpriteController");

	TooltipController* tController = (TooltipController*)GameObjectManager::getInstance()->findObjectByName("TooltipController");
	GameObjectManager::getInstance()->deleteObjectByName("TooltipController");

	this->loadingBar->setIsFading(true);
}

void TextureDisplay::makeLoadingBar()
{
	this->loadingBar = new LoadingBar("LoadingBar", this->assetsTotal);
	GameObjectManager::getInstance()->addObject(loadingBar);
}

void TextureDisplay::FadeInAll()
{
	BGObject* game = (BGObject*)GameObjectManager::getInstance()->findObjectByName("GameSceneBG");
	game->setActiveSelf(true); game->setIsFading(true);

	IETThread::sleep(1200);

	for (int i = 0; i < this->assetsTotal; i++) {
		this->iconList[i]->setActiveSelf(true);
		this->iconList[i]->setIsFading(true);
	}

}