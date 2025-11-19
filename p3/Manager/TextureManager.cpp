#include <fstream>
#include <iostream>
#include <filesystem>
#include "../Manager/TextureManager.h"
#include "../Utils/StringUtils.h"
#include "../ThreadTool/IETThread.h"

//a singleton class
TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance() {
	if (sharedInstance == NULL) {
		//initialize
		sharedInstance = new TextureManager();
	}

	return sharedInstance;
}

TextureManager::TextureManager()
{
	this->countStreamingAssets();

}

void TextureManager::loadFromAssetList()
{
	std::cout << "[TextureManager] Reading from asset list" << std::endl;
	std::ifstream stream("Media/P3-assets.txt");
	String path;

	while(std::getline(stream, path))
	{
		std::vector<String> tokens = StringUtils::split(path, '/');
		String assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
		this->instantiateAsTexture(path, assetName, false);
		//std::cout << "[TextureManager] Loaded texture: " << assetName << std::endl;
	}
}

void TextureManager::loadSprites()
{
	//Media / Characters / Suisei_sheet.png

	//Sprite Loading
	for (int i = 0; i < 6; i++)
	{
		storeTexture("Suisei" + std::to_string(i) , "Media/Characters/suisei_frames/Suisei" + std::to_string(i) + ".gif");
		storeTexture("Pekora" + std::to_string(i), "Media/Characters/pekora_frames/Pekora" + std::to_string(i) + ".gif");
		storeTexture("Ollie" + std::to_string(i), "Media/Characters/ollie_frames/Ollie" + std::to_string(i) + ".gif");
		storeTexture("Fauna" + std::to_string(i), "Media/Characters/fauna_frames/Fauna" + std::to_string(i) + ".gif");
		storeTexture("Aqua" + std::to_string(i), "Media/Characters/auqa_frames/Aqua" + std::to_string(i) + ".gif");
	}


}

void TextureManager::storeTexture(std::string name, std::string path)
{
	loadTexture(name, path);
	sf::Texture* assetTex;
	assetTex = getTexture(name);
}

void TextureManager::loadTexture(std::string key, std::string path)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	VtuberMap[key] = texture;
}

sf::Texture* TextureManager::getTexture(std::string key)
{
	if (VtuberMap[key] != nullptr)
	{
		//std::cout << key << " found" << std::endl;
		return VtuberMap[key];
	}

	else
	{
		std::cout << "No texture found for " << key << std::endl;
		return nullptr;
	}
}












void TextureManager::loadSingleStreamAsset(int index)
{
	std::vector<std::filesystem::directory_entry> files;

	//get all images
	for (const auto& entry : std::filesystem::directory_iterator(STREAMING_PATH)) {
		files.push_back(entry);
	}

	//sort by numbers
	std::sort(files.begin(), files.end(), [](const auto& a, const auto& b) {
		int numA = std::stoi(a.path().stem().string());
		int numB = std::stoi(b.path().stem().string());
		return numA < numB;
	});

	//instantiate as texture
	if (index < files.size()) {
		std::string filepath = files[index].path().string();
		std::string assetName = files[index].path().stem().string(); // filename without extension
		this->instantiateAsTexture(filepath, assetName, true);
	}

}

sf::Texture* TextureManager::getFromTextureMap(const String assetName, int frameIndex)
{
	if (!this->textureMap[assetName].empty()) {
		return this->textureMap[assetName][frameIndex];
	}
	else {
		std::cout << "[TextureManager] No texture found for " << assetName << std::endl;
		return NULL;
	}
}



int TextureManager::getNumFrames(const String assetName)
{
	if (!this->textureMap[assetName].empty()) {
		return this->textureMap[assetName].size();
	}
	else {
		std::cout << "[TextureManager] No texture found for " << assetName << std::endl;
		return 0;
	}
}

sf::Texture* TextureManager::getStreamTextureFromList(const int index)
{
	return this->streamTextureList[index];
}

int TextureManager::getNumLoadedStreamTextures() const
{
	return this->streamTextureList.size();
}

sf::Texture* TextureManager::getByIndex(int index)
{
	if (index >= 0 && index < this->streamTextureList.size()) {
		return this->streamTextureList[index];
	}
	return nullptr;
}

void TextureManager::countStreamingAssets()
{
	this->streamingAssetCount = 0;
	for (const auto& entry : std::filesystem::directory_iterator(STREAMING_PATH)) {
		this->streamingAssetCount++;
	}
	std::cout << "[TextureManager] Number of streaming assets: " << this->streamingAssetCount << std::endl;
}

void TextureManager::instantiateAsTexture(String path, String assetName, bool isStreaming)
{
	//std::cout << "instantiate" << std::endl;
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	this->textureMap[assetName].push_back(texture);

	if(isStreaming)
	{
		this->streamTextureList.push_back(texture);
	}
	else
	{
		this->baseTextureList.push_back(texture);
	}
	
}
