#pragma once
#include "IState.h"

class HealroomState : public IState
{
public:
	static HealroomState* Instance();

	virtual void S_Enter(Ant* ant);
	virtual void S_Execute(Ant* ant);
	virtual void S_Exit(Ant* ant);
};