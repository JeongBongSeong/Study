#include<stdio.h>
#include<stdlib.h>

void Print(int** Arr, int iN);

void magic_square(int** Arr, int n) {

	int iEnd_num = n * n;

	//
	int iInput_data = 1;
	int iX = 0;
	int iY = n / 2;

	// ���� �ݺ� Ƚ�� üũ ���� �� 1���� ��Ų��.
	int iCurrent_num = 0;

	// �ߺ� �� �ǵ��� �������� ����
	int iTemp_x = 0;
	int iTemp_y = 0;

	while (1) {
		//iEnd_num �ݺ� �� Ż��
		if (iCurrent_num == iEnd_num)
			break;

		//Default ��ġ 1 �Է�
		if (iInput_data == 1)
			Arr[iX][iY] = iInput_data;
		else if (iInput_data > 1) {
			iTemp_x = iX; iX--;
			iTemp_y = iY; iY++;

			if (iY >= n) {
				iY = iY - n;
			}
			if (iX < 0) {
				iX = iX + n;
			}
			if (Arr[iX][iY] != 0) {
				iX = ++iTemp_x;
				iY = iTemp_y;

			}
			Arr[iX][iY] = iInput_data;
		}
		iCurrent_num++;
		iInput_data++;
	}
}

int main() {
	int iNum = 0;

	// �ݺ�
	while (1) {
		
		while (1) {
			printf("magic size(3~19���� Ȧ��) (-1 to exit) : ");
			scanf_s("%d", &iNum);

			if (iNum >= 3 && iNum <= 19)
				if (iNum % 2 == 1)
					break;
				if (iNum == -1)
					break;
		}
		
		if (iNum == -1)
			break;

		// �����Ҵ� �� �ʱ�ȭ
		int** iMagic = (int**)malloc(sizeof(int*) * iNum);
		for (int i = 0; i < iNum; i++)
		{
			iMagic[i] = (int*)malloc(sizeof(int) * iNum);
		}
		for (int x = 0; x < iNum; x++)
		{
			for (int y = 0; y < iNum; y++)
			{
				iMagic[x][y] = 0;
			}
		}

		// ������
		magic_square(&*iMagic, iNum);

		// ���
		Print(&*iMagic, iNum);

		// �Ҵ�����
		free(iMagic);
	}
	
}

// ���
void Print(int** Arr, int iN)
{
	for (int iX = 0; iX < iN; iX++)
	{
		for (int iY = 0; iY < iN; iY++)
		{
			printf("%4d ", Arr[iX][iY]);
		}
		printf("\n");
	}
}