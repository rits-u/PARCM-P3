#pragma once
class IExecutionEvent
{
public: 
	virtual void OnFinishedExecution(int _spriteId) = 0;
};

