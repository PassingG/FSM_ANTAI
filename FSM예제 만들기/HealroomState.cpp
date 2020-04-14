#include "AntcaveState.h"
#include "DiningroomState.h"
#include "HealroomState.h"
#include "OutsideState.h"
#include "StorageroomState.h"

#include "Ant.h"
#include "enum.h"

HealroomState * HealroomState::Instance()
{
	static HealroomState instance;

	return &instance;
}

void HealroomState::S_Enter(Ant *ant)
{
	if (ant->Get_Location() != Healroom)
	{
		cout << "\n\n\t\t{[ ġ��� ]}" << endl;
		Sleep(1000);
		ant->Set_Location(Healroom);
	}
}

void HealroomState::S_Execute(Ant *ant)
{
	ant->Add_HP(2);

	cout << "\n\t[ ġ�Ḧ �޾Ҵ�. ]" << endl;
	cout << "\n\t[ ü�� " << ant->Get_HP() << " / " << MaxHP << " ]" << endl;
	Sleep(1000);
	if (ant->Get_HP() >= MaxHP)
	{
		cout << "\n\n\t���� : �� ������ ����. ���� ��������." << endl;
		Sleep(1000);
		ant->ChangeState(AntcaveState::Instance());
	}
}

void HealroomState::S_Exit(Ant *ant)
{
	cout << "\n\n\t[ �̵� ��...... ]\n" << endl;
	Sleep(1000);
}
