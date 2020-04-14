#include <Windows.h>

#include "Ant.h"

int main()
{
	Ant ant;

	ant.Show_Day();

	while(ant.Get_Day() <= MaxDay)
	{
		ant.Update();
	}

	cout << "\t\t\n\n[ 당신의 최종점수 ]" << endl;
	cout << "\t총 저장량 : " << ant.Get_TotalFood() << endl;

	return 0;
}