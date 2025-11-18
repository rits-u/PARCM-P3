#include <SFML/Graphics.hpp>
#include <vector>
#include "Utils/SettingsUtils.h"

using namespace std;
class BaseRunner : private sf::NonCopyable
{
public:
	static const sf::Time	TIME_PER_FRAME;


	BaseRunner();
	void run();


private:
	
	sf::RenderWindow		window;

	void render();
	void processEvents();
	void update(sf::Time elapsedTime);
};


