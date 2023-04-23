#include<iostream>
using namespace std;
#include"workerManager.h"
#include"Worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"

int main()
{
	WorkerManager WM;
	int choice = 0;
	while (true)
	{
		WM.Show_Menu();
		cout << "ÇëÑ¡Ôñ" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1: // Ìí¼Ó
				WM.Add();
				break;
			case 2: // É¾³ý
			{
				WM.del_worker();
				break;
			}
			case 3: // ÏÔÊ¾
				WM.show_worker();
				break;
			case 4: // ÐÞ¸Ä
				WM.mod_worker();
				break;
			case 5: // ²éÕÒ
				WM.find_worker();
				break;
			case 6: // ÅÅÐò
				WM.sort_worker();
				break;
			case 7: // Çå¿Õ
				WM.cleam_worker();
				break;
			case 0: // ÍË³ö
				WM.Exit_System();
				break;
			default:
				system("cls");
				break;
		}
	}

	// test:
	//Worker* worker1 = NULL;
	//worker1 = new employee(1,"Joyce",1); 
	//worker1->showInfo();
	//delete worker1;

	//Worker* worker2 = NULL;
	//worker2 = new manager(2, "Nana", 2);
	//worker2->showInfo();
	//delete worker2;

	//Worker* worker3 = NULL;
	//worker3 = new boss(3, "Baby",3);
	//worker3->showInfo();
	//delete worker3;

	return 0;
}
