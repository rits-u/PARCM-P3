#pragma once

#include "../IWorkerAction.h"
#include "../IExecutionEvent.h"
#include <semaphore>


class VtuberSprite : public IWorkerAction
{
public:

	VtuberSprite();
	~VtuberSprite();

	VtuberSprite(int id, IExecutionEvent* callback);

private:
	int id = 0;
	void OnStartTask() override;
	IExecutionEvent* OnFinished;
	std::mutex guard;
};

