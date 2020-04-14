#pragma once
#include "Ant.h"

class Ant;

class IState abstract
{
public:
	virtual void S_Enter(Ant*) = 0;
	virtual void S_Execute(Ant*) = 0;
	virtual void S_Exit(Ant*) = 0;
};