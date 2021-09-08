#include"LinkedList.cpp"
#include<windows.h>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	LinkedList<char> lList;
	char tData;
	int iSelect;
	while (1)
	{
		cout << "0.Create\n1.Delete\n2.\n3.Print\n(exit : -1)\nInput :";
		cin >> iSelect;
		
		// exit
		if (iSelect == -1)
			break;
		
		// 항목 선택
		switch (iSelect)
		{
		case 0:
			system("cls");
			cout << "input data(Create) : ";
			cin >> tData;
			lList.Create(tData);
			system("cls");
			break;
		case 1:
			system("cls");
			cout << "input data(Delete) : ";
			cin >> tData;
			lList.Delete(tData);
			Sleep(1000);
			system("cls");
			break;
		case 2:
			break;
		case 3:
			system("cls");
			lList.Print();
			break;
		default:
			break;
		}
		
	}

	return 0;
}