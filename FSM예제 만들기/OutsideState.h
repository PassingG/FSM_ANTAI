#pragma once
#include "IState.h"

class OutsideState : public IState
{
public:
	static OutsideState* Instance();

	virtual void S_Enter(Ant* ant);
	virtual void S_Execute(Ant* ant);
	virtual void S_Exit(Ant* ant);
};