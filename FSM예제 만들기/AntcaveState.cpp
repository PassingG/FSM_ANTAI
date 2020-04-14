#include "AntcaveState.h"
#include "DiningroomState.h"
#include "HealroomState.h"
#include "OutsideState.h"
#include "StorageroomState.h"

#include "Ant.h"
#include "enum.h"

AntcaveState * AntcaveState::Instance()
{
	static AntcaveState instance;

	return &instance;
}

void AntcaveState::S_Enter(Ant *ant)
{
	if (ant->Get_Location() != Antcave)
	{
		cout << "\n\n\t\t{[ ���̱� ���� ]}" << endl;
		Sleep(1000);
		ant->Set_Location(Antcave);
	}
}

void AntcaveState::S_Execute(Ant *ant)
{
	// HP�� ������
	if (ant->isLowHP())
	{
		cout << "\n\t���� : ġ��Ұ� ��� �����̾�����..." << endl;
		Sleep(1000);
		ant->ChangeState(HealroomState::Instance());
	}

	// ����� ��ġ�� ������
	else if (ant->isLowHunger())
	{
		cout << "\n\t���� : ����� ������ ���� ��" << endl;
		Sleep(1000);
		ant->ChangeState(DiningroomState::Instance());
	}

	// ���԰� ����á����
	else if (ant->isFullWeight())
	{
		cout << "\n\t���� : �� ������ ���߰ھ�." << endl;
		Sleep(1000);
		ant->ChangeState(StorageroomState::Instance());
	}

	// �Ҵ緮�� �� ä������
	else if (ant->isPerFood())
	{
		ant->SleepAnt();
		ant->Show_Day();
		ant->WakeUpAnt();
	}

	// ���� ��������
	else if (ant->Get_FoodCarry() > 0)
	{
		cout << "\n\t���� : ���� ���� �������� ����." << endl;
		Sleep(1000);
		ant->ChangeState(StorageroomState::Instance());
	}
	else
	{
		cout << "\n\t���� : ���� �Ϸ� ������?" << endl;
		Sleep(1000);
		ant->ChangeState(OutsideState::Instance());
	}
}

void AntcaveState::S_Exit(Ant *ant)
{
	cout << "\n\n\t[ �̵� ��...... ]\n" << endl;
	Sleep(1000);
}
