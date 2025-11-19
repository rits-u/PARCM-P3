#include "FadeTransition.h"
#include <iostream>

FadeTransition::FadeTransition()
{
}

float FadeTransition::getAlphaValue()
{
	return this->alphaValue;
}

void FadeTransition::applyFadeTransition(sf::Time deltaTime)
{
	switch (this->mode) {
	case FADE_OUT:
		this->alphaValue -= this->fadeSpeed * deltaTime.asSeconds(); //speed of fade
		if (this->alphaValue < 0) {
			this->alphaValue = 0;
			this->isFading = false;
			this->mode = FADE_IN;
		}
		break;
	case FADE_IN:
		this->alphaValue += this->fadeSpeed * deltaTime.asSeconds(); //speed of fade
		if (this->alphaValue > 255) {
			this->alphaValue = 255;
			this->isFading = false;
			this->mode = FADE_OUT;
		}
		break;
	}
}

void FadeTransition::changeFadeMode(FadeMode mode)
{
	this->mode = mode;
}

void FadeTransition::setIsFading(bool isFading)
{
	this->isFading = isFading;
}

void FadeTransition::setAlphaValue(float alphaValue)
{
	this->alphaValue = alphaValue;
}

void FadeTransition::setFadeSpeed(float speed)
{
	this->fadeSpeed = speed;
}
