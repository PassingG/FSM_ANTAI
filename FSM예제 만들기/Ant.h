#pragma once
#include "IState.h"
#include "enum.h"
#include "AntcaveState.h"

#include <iostream>
#include <Windows.h>
using namespace std;

class IState;
class AntcaveState;

const int MaxHP = 10;						// 최대체력
const int MaxHunger = 10;					// 최대 배고픔수치
const int MaxWeight = 3;					// 최대 무게
const int MaxDay = 5;						// 진행일수
const int PerDay = 10;						// 하루 할당량

class Ant
{
private:
	IState *Current_State;					// 현재 상태
	Location Current_Locate;				// 현재 위치

	int Current_Hunger;						// 현재 배고픔 수치
	int Current_HP;							// 현재 체력
	int Current_FoodCarry;					// 현재 들고있는 음식

	int totalSaveFood;						// 현재까지 저장한 음식

	int todayFood;							// 오늘 저장해야할 음식

	int day;								// 현재 날짜
public:
	Ant();

	void Update();

	int Get_Day() { return day; }
	void Show_Day();

	void SleepAnt();
	void WakeUpAnt();

	// 상태를 new_State 로 변경하는 함수
	void ChangeState(IState* new_State);

	Location Get_Location() { return Current_Locate; }
	void Set_Location(Location loc) { Current_Locate = loc; }

	int Get_Hunger() { return Current_Hunger; }
	void Set_Hunger(int hung) { Current_Hunger = hung; }
	void Add_Hunger(int add);

	int Get_HP() { return Current_HP; }
	void Set_HP(int hp) { Current_HP = hp; }
	void Add_HP(int add);

	int Get_FoodCarry() { return Current_FoodCarry; }
	void Set_FoodCarry(int fc) { Current_FoodCarry = fc; }
	void Add_FoodCarry(int add);

	int Get_TotalFood() { return totalSaveFood; }
	void Add_TotalFood(int add) { totalSaveFood += add; }

	int Get_TodayFood() { return todayFood; }
	void Add_TodayFood(int add) { todayFood += add; }
	void Set_TodayFood(int tf) { todayFood = tf; }

	bool isPerFood() { return todayFood <= 0; }
	bool isFullWeight() { return Current_FoodCarry >= MaxWeight; }
	bool isLowHP() { return Current_HP <= 1; }
	bool isLowHunger() { return Current_Hunger <= 0; }
};