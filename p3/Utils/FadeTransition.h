#pragma once
#include "SFML/Graphics.hpp"

class FadeTransition 
{
public:
	FadeTransition();

	virtual float getAlphaValue();
	virtual void applyFadeTransition(sf::Time deltaTime);
	virtual void changeFadeMode();
	virtual void setIsFading(bool isFading);
	virtual void setAlphaValue(float alphaValue);

protected:
	bool isFading = false;
	enum FadeMode { FADE_OUT = 0, FADE_IN = 1 };
	FadeMode mode = FADE_OUT;
	float alphaValue;
};

