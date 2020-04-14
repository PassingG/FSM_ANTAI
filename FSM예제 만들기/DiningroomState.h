#pragma once
#include "IState.h"

class DiningroomState : public IState
{
public:
	static DiningroomState* Instance();

	virtual void S_Enter(Ant* ant);
	virtual void S_Execute(Ant* ant);
	virtual void S_Exit(Ant* ant);
};