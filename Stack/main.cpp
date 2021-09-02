#include<iostream>

using namespace std;

void Create();
//void Destroy();
void Enqueue(int);
void Dequeue();
void Top();
bool IsEmpty();
bool IsFull();
void Print();


#define SIZE 3

int g_iArray[SIZE];
int g_iFront;

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
			Top();
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
}

void Enqueue(int data)
{
	if (IsFull() == false)
	{
		g_iArray[g_iFront++] = data;
	}
}
void Dequeue()
{
	if (IsEmpty() == false)
	{
		g_iFront--;
		cout << "Pop Data : ";
		cout << g_iArray[g_iFront] << endl;
	}
}
void Top()
{
	cout << "Top data : " << g_iArray[g_iFront - 1] << endl;
}

bool IsEmpty()
{
	if (g_iFront == 0)
	{
		cout << "is Empty !!!" << endl;
		return true;
	}
	else
		return false;
		
}
bool IsFull()
{

	if (g_iFront == SIZE)
	{
		cout << "is Full !!!" << endl;
		return true;
	}
	else
		return false;
}

void Print()
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << g_iArray[i] << " ";
	}
	cout << endl;

}