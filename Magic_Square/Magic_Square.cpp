#include<stdio.h>
#include<stdlib.h>

void Print(int** Arr, int iN);

void magic_square(int** Arr, int n) {

	int iEnd_num = n * n;

	//
	int iInput_data = 1;
	int iX = 0;
	int iY = n / 2;

	// 현재 반복 횟수 체크 끝날 때 1증가 시킨다.
	int iCurrent_num = 0;

	// 중복 시 되돌아 오기위한 변수
	int iTemp_x = 0;
	int iTemp_y = 0;

	while (1) {
		//iEnd_num 반복 시 탈출
		if (iCurrent_num == iEnd_num)
			break;

		//Default 위치 1 입력
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

	// 반복
	while (1) {
		
		while (1) {
			printf("magic size(3~19사이 홀수) (-1 to exit) : ");
			scanf_s("%d", &iNum);

			if (iNum >= 3 && iNum <= 19)
				if (iNum % 2 == 1)
					break;
				if (iNum == -1)
					break;
		}
		
		if (iNum == -1)
			break;

		// 동적할당 및 초기화
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

		// 마방진
		magic_square(&*iMagic, iNum);

		// 출력
		Print(&*iMagic, iNum);

		// 할당해제
		free(iMagic);
	}
	
}

// 출력
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