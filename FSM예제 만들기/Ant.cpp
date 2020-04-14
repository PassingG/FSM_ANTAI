#include "Ant.h"

Ant::Ant() :
	Current_Locate(Antcave),
	Current_Hunger(MaxHunger),
	Current_HP(MaxHP),
	Current_FoodCarry(0),
	totalSaveFood(0),
	todayFood(PerDay),
	day(1),
	Current_State(AntcaveState::Instance())
{

}

void Ant::Update()
{
	Current_Hunger -= 1;

	if (Current_State)
	{
		Current_State->S_Execute(this);
	}
}

void Ant::Show_Day()
{
	cout << "\n\n\t[ " << day << " ��° ]" << endl;
	Sleep(1000);
}

void Ant::SleepAnt()
{
	cout << "\n\t���� : ���� �Ҵ緮�� �� ä����. �׷� �ں���?" << endl;
	Sleep(1000);
	cout << "\n\t���� : ( ���� �ܴ�... )" << endl;
	Sleep(1000);
	cout << "\n\t[ HP�� ȸ���Ǿ����ϴ� ]" << endl;
	Sleep(1000);

	Current_HP = MaxHP;
	todayFood = PerDay; 
	day += 1;
}

void Ant::WakeUpAnt()
{
	cout << "\n\t���� : ������ ��ħ�̾�. ���õ� ������ ���غ���." << endl;
	Sleep(1000);
	cout << "\n\t������ �Ҵ緮 : " << todayFood << " ��" << endl;
	Sleep(1000);
}

void Ant::ChangeState(IState* new_State)
{
	// ���� ���¸� ������
	Current_State->S_Exit(this);

	// ���� ���¸� new_State�� �����Ѵ�.
	Current_State = new_State;

	// ���� ���¸� �����Ѵ�.
	Current_State->S_Enter(this);
}


void Ant::Add_Hunger(int add)
{
	Current_Hunger += add;

	if (Current_Hunger < 0) Current_Hunger = 0;
}

void Ant::Add_HP(int add)
{
	Current_HP += add;

	if (Current_HP < 0) Current_HP = 0;
}

void Ant::Add_FoodCarry(int add)
{
	Current_FoodCarry += add;

	if (Current_FoodCarry < 0) Current_FoodCarry = 0;
}
