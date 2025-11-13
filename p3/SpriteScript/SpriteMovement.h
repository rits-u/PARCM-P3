#pragma once
#include <iostream>
#include  "../ThreadTool/IWorkerAction.h"
#include <semaphore>

class SpriteMovement : public IWorkerAction
{
public:
	SpriteMovement(std::string _spriteName);

private:
	std::string Name;
	void OnStartTask() override;
};

