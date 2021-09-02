#include<iostream>

void Create();
void Destroy();
void Push();
void Pop();
void Top();
bool IsEmpty();
bool IsFull();

using namesapce std;
#define SIZE 3

int g_iArray[SIZE];
int iTop;

int main() {
	Create();

	int iData;
	int iSelect;
	while (1)
	{
		iSelect = 0;
		iData = 0;

		cout << "0. Push\n1. Pop\n2. Top\n(exit : 그 외 숫자)";
		cin >> iSelect;
		switch (iSelect)
		{
		case 0:
			cout << "push data :";
			cin >> iData;
			Push(iData);
			break;
		case 1:
			Pop();

			break;
		case 2:
			Top();
			break;
		default:
			break;
		}


	}
	


}

void Create()
{
	memset(g_iArray, 0, sizeof(int) * SIZE);
	iTop = -1;
}

void Push(int data)
{
	if (IsFull() == false) 
	{
		iTop[iTop++] == data;
	}
	else
	{
		cout << "isFull"
	}
}

void Top()
{
	cout<<"Top data : "g_iArray[iTop - 1] << endl;
}

bool IsEmpty()
{
	if (iTop == 0)
		return false;
	else
		cout << "is Empty !!!" << endl;
		return true;
}
bool IsFull()
{
	
	if (iTop == SIZE)
		return true;
	else
		cout << "is Full !!!" << endl;
		return false;
}