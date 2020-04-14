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
	cout << "\n\n\t[ " << day << " 일째 ]" << endl;
	Sleep(1000);
}

void Ant::SleepAnt()
{
	cout << "\n\t개미 : 오늘 할당량을 다 채웠군. 그럼 자볼까?" << endl;
	Sleep(1000);
	cout << "\n\t개미 : ( 잠을 잔다... )" << endl;
	Sleep(1000);
	cout << "\n\t[ HP가 회복되었습니다 ]" << endl;
	Sleep(1000);

	Current_HP = MaxHP;
	todayFood = PerDay; 
	day += 1;
}

void Ant::WakeUpAnt()
{
	cout << "\n\t개미 : 상쾌한 아침이야. 오늘도 열심히 일해보자." << endl;
	Sleep(1000);
	cout << "\n\t오늘의 할당량 : " << todayFood << " 개" << endl;
	Sleep(1000);
}

void Ant::ChangeState(IState* new_State)
{
	// 현재 상태를 나간다
	Current_State->S_Exit(this);

	// 현재 상태를 new_State로 지정한다.
	Current_State = new_State;

	// 현재 상태를 입장한다.
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
