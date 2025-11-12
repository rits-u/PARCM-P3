#pragma once

#include "../ThreadTool/IWorkerAction.h"
#include "../ThreadTool/IExecutionEvent.h"
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
};

