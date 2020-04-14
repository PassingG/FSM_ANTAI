#include <random>
#include <ctime>
#include <functional>

#include "AntcaveState.h"
#include "DiningroomState.h"
#include "HealroomState.h"
#include "OutsideState.h"
#include "StorageroomState.h"

#include "Ant.h"
#include "enum.h"

OutsideState * OutsideState::Instance()
{
	static OutsideState instance;

	return &instance;
}

void OutsideState::S_Enter(Ant *ant)
{
	if (ant->Get_Location() != Outside)
	{
		cout << "\n\n\t\t{[ ���� �� ]}" << endl;
		Sleep(1000);
		ant->Set_Location(Outside);
	}
}

void OutsideState::S_Execute(Ant *ant)
{
	mt19937 engine((unsigned int)time(NULL));					// MT19937 ���� ����
	uniform_int_distribution<int> distribution(0, 99);			// ���� ����
	auto generator = bind(distribution, engine);

	int rand = generator();

	// ���ݴ��� Ȯ�� 10%
	if (rand < 10)
	{
		cout << "\n\t[ ������ ���� ���ߴ�!  HP -1]" << endl;
		ant->Add_HP(-1);
	}

	// ���̸� ã�� Ȯ�� 50%
	else if (rand >= 10 && rand < 60)
	{
		cout << "\n\t[ ���̸� ã�Ҵ�! FOOD +1 ]" << endl;
		ant->Add_FoodCarry(1);
	}

	// ���̸� �� ã�� Ȯ�� 40%
	else
	{
		cout << "\n\t[ �ƹ��͵� ã�� ���ߴ�... ]" << endl;
	}

	cout << "\n\t[ ü�� " << ant->Get_HP() << " / " << MaxHP << " ]" << endl;
	cout << "\n\t[ ��� " << ant->Get_FoodCarry() << " / " << MaxWeight << " ]" << endl;
	cout << "\n\t[ ��� " << ant->Get_Hunger() << " / " << MaxHunger << " ]\n" << endl;
	Sleep(1000);

	if (ant->isLowHP())
	{
		cout << "\n\t���� : �ʹ� ������... �ϴ� ���ư���..." << endl;
		Sleep(1000);
		ant->ChangeState(AntcaveState::Instance());
	}
	else if (ant->isLowHunger())
	{
		cout << "\n\t���� : �谡 �ʹ� ����. ������ ���ư���." << endl;
		Sleep(1000);
		ant->ChangeState(AntcaveState::Instance());
	}
	else if (ant->isFullWeight())
	{
		cout << "\n\t���� : �ʹ� ���ſ�!! � ���ư���!!!" << endl;
		Sleep(1000);
		ant->ChangeState(AntcaveState::Instance());
	}
}

void OutsideState::S_Exit(Ant *ant)
{
	cout << "\n\n\t[ �̵� ��...... ]\n" << endl;
	Sleep(1000);
}
