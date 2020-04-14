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
		cout << "\n\n\t\t{[ �Ĵ� ]}" << endl;
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

	cout << "\n\t[ ���� �Ծ���. ]" << endl;
	cout << "\n\t��⵵ ( " << ant->Get_Hunger() << " / " << MaxHunger << " )" << endl;
	Sleep(1000);
	if (ant->Get_Hunger() >= MaxHunger)
	{
		cout << "\n\n\t���� : �� ��θ���! �Ͼ����." << endl;
		Sleep(1000);
		ant->ChangeState(AntcaveState::Instance());
	}
}

void DiningroomState::S_Exit(Ant *ant)
{
	cout << "\n\n\t[ �̵� ��...... ]\n" << endl;
	Sleep(1000);
}
