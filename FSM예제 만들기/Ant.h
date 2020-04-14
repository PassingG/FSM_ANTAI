#pragma once
#include "IState.h"
#include "enum.h"
#include "AntcaveState.h"

#include <iostream>
#include <Windows.h>
using namespace std;

class IState;
class AntcaveState;

const int MaxHP = 10;						// �ִ�ü��
const int MaxHunger = 10;					// �ִ� ����ļ�ġ
const int MaxWeight = 3;					// �ִ� ����
const int MaxDay = 5;						// �����ϼ�
const int PerDay = 10;						// �Ϸ� �Ҵ緮

class Ant
{
private:
	IState *Current_State;					// ���� ����
	Location Current_Locate;				// ���� ��ġ

	int Current_Hunger;						// ���� ����� ��ġ
	int Current_HP;							// ���� ü��
	int Current_FoodCarry;					// ���� ����ִ� ����

	int totalSaveFood;						// ������� ������ ����

	int todayFood;							// ���� �����ؾ��� ����

	int day;								// ���� ��¥
public:
	Ant();

	void Update();

	int Get_Day() { return day; }
	void Show_Day();

	void SleepAnt();
	void WakeUpAnt();

	// ���¸� new_State �� �����ϴ� �Լ�
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