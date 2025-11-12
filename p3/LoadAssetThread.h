#pragma once

#include <iostream>
#include "ThreadTool/IETThread.h"
#include "ThreadTool/IExecutionEvent.h"
#include "Manager/TextureManager.h"
#include "ThreadTool/IWorkerAction.h"
#include <semaphore>

class LoadAssetThread : public IWorkerAction 
{
public:
	LoadAssetThread() {}
	~LoadAssetThread() {}

	LoadAssetThread(int id, IExecutionEvent* callback);

	void SetBatchSize(int size);
	void SetMode(bool isBatch);
	void SetNumAsset(int num);

private:

	int id = 0;
	int batchSize;
	int numAssets;
	bool isBatch;
	//void run() override;
	void OnStartTask() override;
	IExecutionEvent* OnFinished;
};

