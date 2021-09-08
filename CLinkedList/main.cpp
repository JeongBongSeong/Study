#include"CLinkedList.h"
#include"CircleGame.h"
#include<cstdlib>
#include<windows.h>

void InsertFunc(CLinkedList* CList);
void game(CLinkedList* CList);
int random_number(int end);
CNode* CircleGameStart(CLinkedList* CList);
CNode* PrevMove(CNode*,int);
int main()
{
	CLinkedList*CList = new CLinkedList();
	int iSelect = 0;
	while (true)
	{
		CList->Menu();

		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			InsertFunc(CList);
			break;
		case 2:

			break;
		case 3:
			InsertFunc(CList);
			break;
		case 4:
			game(CList);
			break;
		}

	}


}
int random_number(int end)
{
	srand((unsigned int)time(NULL));
	return rand() % end;
}
CNode* CircleGameStart(CLinkedList* CList)
{
	CNode* CurrentNode = CList->ReturnHead();
	int iRotation_Number = random_number(1000);
	
	while(true)
	{
		CurrentNode = PrevMove(CurrentNode, iRotation_Number);
		cout << "삭제될 데이터 : " << CurrentNode->next->data << "\n";
		CList->Delete(CurrentNode);

		if (CurrentNode->next == nullptr)
			break;
		CurrentNode = CurrentNode->next;
	}
	cout << "최종 승리자 : " << CurrentNode->data << "\n";
	Sleep(5000);
	
	


	return CurrentNode;
}
CNode* PrevMove(CNode* CurrentNode,int iRotation_Number)
{
	for (int i = 0; i < iRotation_Number-1; i++)
	{
		CurrentNode = CurrentNode->next;
	}
	return CurrentNode;
}

void game(CLinkedList* CList)
{
	int f_iSelect = 0;
	int f_data;
	while (true)
	{
		//system("cls");
		CList->Circle_Game_Menu();
		cin >> f_iSelect;

		switch (f_iSelect)
		{
		case 1:
		{
			//system("cls");
			for (int i = 0; i < random_number(1000); i++)
			{
				if (CList->Is_Empty() == true)
				{
					CList->Create_Circle(i);
				}
				else
				{
					CList->Insert_Circle(i);
				}
			}
			CList->Size();
		}break;
		case 2:
		{
			CNode* ret = CircleGameStart(CList);
			cout << ret->data << "dfadsf" << endl;
		}break;
		case 3:
		{

		}
		break;
		case 4:
		{

		}
		break;
		}
	}
}
void InsertFunc(CLinkedList* CList)
{
	int f_iSelect = 0;
	int f_data;
	while (true)
	{
		//system("cls");
		CList->Insert_Menu();
		cin >> f_iSelect;

		switch (f_iSelect)
		{
		case 1:
			//system("cls");
			cout << "Input Data : ";
			cin >> f_data;
			if (CList->Is_Empty() == true)
			{
				CList->Create_Circle(f_data);
			}
			else
			{
				CList->Insert_Circle(f_data);
			}
			
			break;
		case 2:
			cout << "Input Data : ";
			cin >> f_data;
			
			break;
		case 3:

			break;
		case 4:

			break;
		}
	}
}
