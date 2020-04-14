#include "AntcaveState.h"
#include "DiningroomState.h"
#include "HealroomState.h"
#include "OutsideState.h"
#include "StorageroomState.h"

#include "Ant.h"
#include "enum.h"

DiningroomState * DiningroomState::Instance()
{
	static DiningroomState instance;

	return &instance;
}

void DiningroomState::S_Enter(Ant *ant)
{
	if (ant->Get_Location() != Diningroom)
	{
		cout << "\n\n\t\t{[ 식당 ]}" << endl;
		Sleep(1000);
		ant->Set_Location(Diningroom);
	}
}

void DiningroomState::S_Execute(Ant *ant)
{
	ant->Add_Hunger(4);

	if (ant->Get_Hunger() > 10)
	{
		ant->Set_Hunger(10);
	}

	cout << "\n\t[ 밥을 먹었다. ]" << endl;
	cout << "\n\t허기도 ( " << ant->Get_Hunger() << " / " << MaxHunger << " )" << endl;
	Sleep(1000);
	if (ant->Get_Hunger() >= MaxHunger)
	{
		cout << "\n\n\t개미 : 아 배부르다! 일어나볼까." << endl;
		Sleep(1000);
		ant->ChangeState(AntcaveState::Instance());
	}
}

void DiningroomState::S_Exit(Ant *ant)
{
	cout << "\n\n\t[ 이동 중...... ]\n" << endl;
	Sleep(1000);
}
