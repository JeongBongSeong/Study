#include<iostream>

using namespace std;

void Create();
//void Destroy();
void Enqueue(int);
void Dequeue();
//void Top();
bool IsEmpty();
bool IsFull();
void Print();


#define SIZE 3

int g_iArray[SIZE];
int g_iFront;
int g_iRear;

int main() {
	Create();

	int iData;
	int iSelect;
	cout << "-----------------------------------------------------------------------------\n";
	while (1)
	{
		iSelect = 0;
		iData = 0;

		cout << "0. Push\n1. Pop\n2. Top\n3. Print\n4. display clear\n(exit : -1)\ninput data : ";
		cin >> iSelect;
		if (iSelect == -1)
			break;

		switch (iSelect)
		{
		case 0:
			cout << "push data :";
			cin >> iData;
			Enqueue(iData);
			break;
		case 1:
			Dequeue();

			break;
		case 2:
//			Top();
			break;
		case 3:
			Print();
			break;
		case 4:
			system("cls");
			break;
		default:
			break;
		}
		cout << "-----------------------------------------------------------------------------\n";
	}



}

void Create()
{
	memset(g_iArray, 0, sizeof(int) * SIZE);
	g_iFront = 0;
	g_iRear = 0;
}

void Enqueue(int data)
{
	
	if (IsFull() == false)
	{
		g_iArray[g_iRear] = data;
		g_iRear = (g_iRear + 1) % SIZE;
	}
}

void Dequeue()
{
	if (IsEmpty() == false)
	{
		cout << "Dequeue Data : ";
		cout << g_iArray[g_iFront] << endl;
		g_iFront = (g_iFront+1) % SIZE;
	}
}

bool IsEmpty()
{
	if (g_iFront == g_iRear)
	{
		cout << "is Empty !!!" << endl;
		return true;
	}
	else
		return false;
}
bool IsFull()
{
	if (g_iFront == ((g_iRear+1)%SIZE))
	{
		cout << "is Full !!!" << endl;
		return true;
	}
	else
		return false;
}

void Print()
{
	int i = g_iFront;
	if (IsEmpty() == false)
	{
		cout << g_iArray[i] << " ";
		i = (i + 1) % SIZE;
	}
	else
		return;

	for (;i != (g_iRear+1)%SIZE;)
	{
		cout << g_iArray[i] << " ";
		i = (i + 1) % SIZE;
	}
	cout << endl;

}