#include "AntcaveState.h"
#include "DiningroomState.h"
#include "HealroomState.h"
#include "OutsideState.h"
#include "StorageroomState.h"

#include "Ant.h"
#include "enum.h"

StorageroomState * StorageroomState::Instance()
{
	static StorageroomState instance;

	return &instance;
}

void StorageroomState::S_Enter(Ant *ant)
{
	if (ant->Get_Location() != Storageroom)
	{
		cout << "\n\n\t\t{[ ����� ���� ]}" << endl;
		Sleep(1000);
		ant->Set_Location(Storageroom);
	}
}

void StorageroomState::S_Execute(Ant *ant)
{
	int tmpFoodCarry = ant->Get_FoodCarry();
	int tmpTotal = ant->Get_TotalFood();

	ant->Add_TodayFood(-(ant->Get_FoodCarry()));

	if (ant->Get_TodayFood() < 0)
	{
		ant->Set_FoodCarry(-(ant->Get_TodayFood()));
		ant->Add_TotalFood(tmpFoodCarry - ant->Get_FoodCarry());
		ant->Set_TodayFood(0);
	}
	else 
	{
		ant->Add_TotalFood(ant->Get_FoodCarry());
		ant->Set_FoodCarry(0);
	}

	cout << "\n\t[ ����� ���� �������Ҵ�. Food +" << ant->Get_TotalFood() - tmpTotal << " ]" << endl;
	cout << "\n\t[ �����差 : " << ant->Get_TotalFood() << " �� ]" << endl;
	cout << "\n\t[ ���� �Ҵ緮 " << ant->Get_TodayFood() << " / " << PerDay << " ]" << endl;
	Sleep(1000);

	cout << "\n\n\t���� : ���⼭�� ������ ������." << endl;
	Sleep(1000);
	ant->ChangeState(AntcaveState::Instance());
}

void StorageroomState::S_Exit(Ant *ant)
{
	cout << "\n\n\t[ �̵� ��...... ]\n" << endl;
	Sleep(1000);
}
