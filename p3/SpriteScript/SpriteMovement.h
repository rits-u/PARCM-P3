#pragma once
#include <iostream>
#include  "../IWorkerAction.h"

class SpriteMovement : public IWorkerAction
{
public:
	SpriteMovement();

private:
	void OnStartTask() override;
};

