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

	cout << "\t\t\n\n[ ����� �������� ]" << endl;
	cout << "\t�� ���差 : " << ant.Get_TotalFood() << endl;

	return 0;
}