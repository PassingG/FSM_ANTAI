#pragma once
#include "IState.h"

class AntcaveState : public IState
{
public:
	static AntcaveState* Instance();

	virtual void S_Enter(Ant* ant);
	virtual void S_Execute(Ant* ant);
	virtual void S_Exit(Ant* ant);
};