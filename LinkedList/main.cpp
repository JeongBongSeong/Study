#include"LinkedList.cpp"
#include<windows.h>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	LinkedList<int> lList;
	int iData;
	int iSelect;
	while (1)
	{
		cout << "0.Create\n1.Delete\n2.\n3.Print\n(exit : -1)\nInput :";
		cin >> iSelect;
		
		// exit
		if (iSelect == -1)
			break;

		// �׸� ����
		switch (iSelect)
		{
		case 0:
			system("cls");
			cout << "input data(Create) : ";
			cin >> iData;
			lList.Create(iData);
			system("cls");
			break;
		case 1:
			system("cls");
			cout << "input data(Delete) : ";
			cin >> iData;
			lList.Delete(iData);
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