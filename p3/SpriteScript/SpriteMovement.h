#pragma once
#include <iostream>
#include  "../ThreadTool/IWorkerAction.h"

class SpriteMovement : public IWorkerAction
{
public:
	SpriteMovement();

private:
	void OnStartTask() override;
};

