#pragma once
class FadeTransition 
{
private:
	bool isFading = false;
	enum FadeMode { FADE_OUT = 0, FADE_IN = 1 };
	FadeMode mode = FADE_OUT;
	float alphaValue;
};

