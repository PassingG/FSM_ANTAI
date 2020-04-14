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
		cout << "\n\n\t\t{[ 깊은 숲 ]}" << endl;
		Sleep(1000);
		ant->Set_Location(Outside);
	}
}

void OutsideState::S_Execute(Ant *ant)
{
	mt19937 engine((unsigned int)time(NULL));					// MT19937 난수 엔진
	uniform_int_distribution<int> distribution(0, 99);			// 생성 범위
	auto generator = bind(distribution, engine);

	int rand = generator();

	// 공격당할 확률 10%
	if (rand < 10)
	{
		cout << "\n\t[ 적에게 공격 당했다!  HP -1]" << endl;
		ant->Add_HP(-1);
	}

	// 먹이를 찾을 확률 50%
	else if (rand >= 10 && rand < 60)
	{
		cout << "\n\t[ 먹이를 찾았다! FOOD +1 ]" << endl;
		ant->Add_FoodCarry(1);
	}

	// 먹이를 못 찾을 확률 40%
	else
	{
		cout << "\n\t[ 아무것도 찾지 못했다... ]" << endl;
	}

	cout << "\n\t[ 체력 " << ant->Get_HP() << " / " << MaxHP << " ]" << endl;
	cout << "\n\t[ 운반 " << ant->Get_FoodCarry() << " / " << MaxWeight << " ]" << endl;
	cout << "\n\t[ 허기 " << ant->Get_Hunger() << " / " << MaxHunger << " ]\n" << endl;
	Sleep(1000);

	if (ant->isLowHP())
	{
		cout << "\n\t개미 : 너무 아프다... 일단 돌아가자..." << endl;
		Sleep(1000);
		ant->ChangeState(AntcaveState::Instance());
	}
	else if (ant->isLowHunger())
	{
		cout << "\n\t개미 : 배가 너무 고파. 집으로 돌아가자." << endl;
		Sleep(1000);
		ant->ChangeState(AntcaveState::Instance());
	}
	else if (ant->isFullWeight())
	{
		cout << "\n\t개미 : 너무 무거워!! 어서 돌아가자!!!" << endl;
		Sleep(1000);
		ant->ChangeState(AntcaveState::Instance());
	}
}

void OutsideState::S_Exit(Ant *ant)
{
	cout << "\n\n\t[ 이동 중...... ]\n" << endl;
	Sleep(1000);
}
