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
		cout << "\n\n\t\t{[ 개미굴 내부 ]}" << endl;
		Sleep(1000);
		ant->Set_Location(Antcave);
	}
}

void AntcaveState::S_Execute(Ant *ant)
{
	// HP가 낮을때
	if (ant->isLowHP())
	{
		cout << "\n\t개미 : 치료소가 어느 방향이었더라..." << endl;
		Sleep(1000);
		ant->ChangeState(HealroomState::Instance());
	}

	// 배고픔 수치가 낮을때
	else if (ant->isLowHunger())
	{
		cout << "\n\t개미 : 배고파 죽을거 같아 ㅠ" << endl;
		Sleep(1000);
		ant->ChangeState(DiningroomState::Instance());
	}

	// 무게가 가득찼을때
	else if (ant->isFullWeight())
	{
		cout << "\n\t개미 : 얼른 저장고로 가야겠어." << endl;
		Sleep(1000);
		ant->ChangeState(StorageroomState::Instance());
	}

	// 할당량을 다 채웠을때
	else if (ant->isPerFood())
	{
		ant->SleepAnt();
		ant->Show_Day();
		ant->WakeUpAnt();
	}

	// 짐이 남았을때
	else if (ant->Get_FoodCarry() > 0)
	{
		cout << "\n\t개미 : 짐을 마저 내려놓고 오자." << endl;
		Sleep(1000);
		ant->ChangeState(StorageroomState::Instance());
	}
	else
	{
		cout << "\n\t개미 : 일을 하러 가볼까?" << endl;
		Sleep(1000);
		ant->ChangeState(OutsideState::Instance());
	}
}

void AntcaveState::S_Exit(Ant *ant)
{
	cout << "\n\n\t[ 이동 중...... ]\n" << endl;
	Sleep(1000);
}
