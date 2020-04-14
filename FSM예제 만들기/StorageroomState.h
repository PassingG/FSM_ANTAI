#pragma once
#include "IState.h"

class StorageroomState : public IState
{
public:
	static StorageroomState* Instance();

	virtual void S_Enter(Ant* ant);
	virtual void S_Execute(Ant* ant);
	virtual void S_Exit(Ant* ant);
};