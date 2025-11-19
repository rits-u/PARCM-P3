#include "AGameObject.h"

AGameObject::AGameObject(String name)
{
	this->name = name;
}

AGameObject::~AGameObject() {
	delete this->sprite;
	delete this->texture;
}

AGameObject::String AGameObject::getName() {
	return this->name;
}

//void AGameObject::fadeTransition(sf::Time deltaTime)
//{
//	switch (this->mode) {
//	case FADE_IN:
//		this->alphaValue -= 150.f * deltaTime.asSeconds(); //speed of fade
//		if (this->alphaValue < 0) {
//			this->alphaValue = 0;
//			this->isFading = false;
//			this->mode = FADE_OUT;
//		}
//		break;
//	case FADE_OUT:
//		this->alphaValue += 150.f * deltaTime.asSeconds(); //speed of fade
//		if (this->alphaValue > 255) {
//			this->alphaValue = 255;
//			this->isFading = false;
//			this->mode = FADE_IN;
//		}
//		break;
//	}
//}

void AGameObject::draw(sf::RenderWindow* targetWindow) {
	if (this->sprite != NULL) {
		this->sprite->setPosition(this->posX, this->posY);
		//this->sprite->setScale(this->scaleX, this->scaleY);
		targetWindow->draw(*this->sprite);
	}
}

//must be called after being registered to the game object manager or one of the parent game objects
void AGameObject::setPosition(float x, float y)
{
	this->posX = x;
	this->posY = y;

	if(this->sprite != nullptr)
	{
		this->sprite->setPosition(this->posX, this->posY);
	}
}

void AGameObject::setScale(float x, float y)
{
	this->scaleX = x;
	this->scaleY = y;

	if (this->sprite != nullptr)
	{
		this->sprite->setScale(this->scaleX, this->scaleY);
	}
}

void AGameObject::setActiveSelf(bool isActive)
{
	this->isActive = isActive;
}

//void AGameObject::changeFadeMode()
//{
//	if (this->mode = FADE_IN)
//		this->mode = FADE_OUT;
//	else
//		this->mode = FADE_IN;
//}
//
//void AGameObject::setIsFading(bool isFading)
//{
//	this->isFading = isFading;
//}
//
//void AGameObject::setAlphaValue(float alphaValue)
//{
//	this->alphaValue = alphaValue;
//}

sf::Vector2f AGameObject::getPosition()
{
	return this->sprite->getPosition();
}

sf::Vector2f AGameObject::getScale()
{
	return this->sprite->getScale();
}

sf::FloatRect AGameObject::getLocalBounds()
{
	return this->sprite->getLocalBounds();
}

bool AGameObject::getActiveSelf() {
	return this->isActive;
}

//float AGameObject::getAlphaValue()
//{
//	return this->alphaValue;
//}
