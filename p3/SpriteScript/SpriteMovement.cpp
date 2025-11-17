#include "SpriteMovement.h"


std::counting_semaphore<1> spriteRoom(1);
SpriteMovement::SpriteMovement(std::string _name, IExecutionEvent* _callback) : AGameObject(_name)
{
	this->Name = _name;
	this->OnFinished = _callback;
}

void SpriteMovement::initialize()
{
	//assign texture
	this->sprite = new sf::Sprite();
	sf::Texture* texture = TextureManager::getInstance()->getTexture("Suisei");
	this->sprite->setTexture(*texture);
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
}

void SpriteMovement::OnStartTask()
{
	spriteRoom.acquire();

	//Get the sprite frame

	if (bSwitch)
	{
		bSwitch = false;
		traverseList(counter);
		counter++;

		/*Sprite Rendering*/
		currSprite = sf::IntRect(coord[0], coord[1], coord[2], coord[3]);
		sprite->setTextureRect(currSprite);
		sprite->setOrigin(currSprite.width / 2.0f, currSprite.height / 2.0f);
	}


	//Move it

	std::cout << "Task working" << std::endl;

	spriteRoom.release();


	this->OnFinished->OnFinishedExecution();
}

void SpriteMovement::update(sf::Time deltaTime) 
{
	currTime += deltaTime.asMilliseconds();

	if (currTime >= switchTimer)
	{
		this->bSwitch = true;
		currTime = 0.0f;
	}
}

//void SpriteMovement::prepareVtuberSpriteSheet()
//{
//	//1. Parse a JSON file
//	FILE* file = fopen("Media/Characters/Suisei_sheet.json", "rb");
//
//	//2. Check if we opened succesfully
//	assert(file != 0);
//
//	char readBuffer[65536];
//	rapidjson::FileReadStream is(file, readBuffer, sizeof(readBuffer));
//	rapidjson::Document doc;
//
//	//3. Parse data here
//	doc.ParseStream(is);
//	fclose(file);
//
//	//4. Read the data
//	assert(doc.IsObject());
//
//	rapidjson::Value& player = doc["frames"];
//	assert(player.IsObject());
//
//	std::vector<int> coords;
//	int counter = 0;
//
//	//accessing all the names and storing the values
//	for (auto& m : player.GetObject())
//	{
//		//std::cout << m.name.GetString() << "\n";
//
//		for (auto& p : player[m.name.GetString()]["frame"].GetObject())
//		{
//			coords.push_back(p.value.GetInt());
//		}
//		tuberList.insert({ counter,coords });
//
//		/*Clear and go to next object*/
//		coords.clear();
//		counter++;
//
//	}
//
//	//"frame": {"x":0, "y" : 0, "w" : 58, "h" : 68},
//	coord = { 0,0,58,68};
//}

std::vector<int> SpriteMovement::traverseList(int counter)
{
	auto i = tuberList.find(counter)->second;
	return i;

}

void SpriteMovement::processInput(sf::Event event) {}
