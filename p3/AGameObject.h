#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class AGameObject: sf::NonCopyable
{
	public:
		typedef std::string String;
		AGameObject(String name);
		~AGameObject();
		virtual void initialize() = 0;
		virtual void processInput(sf::Event event) = 0;
		virtual void update(sf::Time deltaTime) = 0;
		virtual void draw(sf::RenderWindow* targetWindow);
		String getName();
		virtual void fadeTransition(sf::Time deltaTime);

		virtual void setPosition(float x, float y);
		virtual void setScale(float x, float y);
		virtual void setActiveSelf(bool isActive);
		virtual void changeFadeMode();
		virtual void setIsFading(bool isFading);
		virtual void setAlphaValue(float alphaValue);
		virtual sf::FloatRect getLocalBounds();
		virtual sf::Vector2f getPosition();
		virtual sf::Vector2f getScale();
		virtual bool getActiveSelf();
		virtual float getAlphaValue();
	

		sf::Sprite* sprite = new sf::Sprite;

	protected:
		String name;
	
		sf::Texture* texture = new sf::Texture;

		float posX = 0.0f; float posY = 0.0f;
		float scaleX = 1.0f; float scaleY = 1.0f;
		bool isActive = true;

		bool isFading = false;
		enum FadeMode { FADE_OUT = 0, FADE_IN = 1 };
		FadeMode mode = FADE_OUT;
		float alphaValue;
};

