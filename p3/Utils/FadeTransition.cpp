#include "FadeTransition.h"

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
		this->alphaValue -= 150.f * deltaTime.asSeconds(); //speed of fade
		if (this->alphaValue < 0) {
			this->alphaValue = 0;
			this->isFading = false;
			this->mode = FADE_IN;
		}
		break;
	case FADE_IN:
		this->alphaValue += 150.f * deltaTime.asSeconds(); //speed of fade
		if (this->alphaValue > 255) {
			this->alphaValue = 255;
			this->isFading = false;
			this->mode = FADE_OUT;
		}
		break;
	}
}

void FadeTransition::changeFadeMode()
{
	if (this->mode = FADE_IN)
		this->mode = FADE_OUT;
	else
		this->mode = FADE_IN;
}

void FadeTransition::setIsFading(bool isFading)
{
	this->isFading = isFading;
}

void FadeTransition::setAlphaValue(float alphaValue)
{
	this->alphaValue = alphaValue;
}
