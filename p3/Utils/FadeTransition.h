#pragma once
#include "SFML/Graphics.hpp"

class FadeTransition 
{
public:
	FadeTransition();
	enum FadeMode { FADE_OUT = 0, FADE_IN = 1 };

	virtual float getAlphaValue();
	virtual void applyFadeTransition(sf::Time deltaTime);
	virtual void changeFadeMode(FadeMode mode);
	virtual void setIsFading(bool isFading);
	virtual void setAlphaValue(float alphaValue);
	virtual void setFadeSpeed(float speed);

protected:
	bool isFading = false;
	FadeMode mode = FADE_OUT;
	float alphaValue;
	float fadeSpeed = 150.0f;

};

