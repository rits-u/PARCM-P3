#include "VtuberSprite.h"

VtuberSprite::VtuberSprite() {}

VtuberSprite::~VtuberSprite() {}

VtuberSprite::VtuberSprite(int _id, IExecutionEvent* _callback)
{
	this->id = _id;
	this->OnFinished = _callback;
}

std::counting_semaphore<2> spriteOrder(1);
void VtuberSprite::OnStartTask()
{
	spriteOrder.acquire();

	//Add tasks here

	spriteOrder.release();
}


