////# include <iostream>
////# define MAX_SIZE 10000
////
////// gap만큼 떨어진 요소들을 삽입 정렬
////// 정렬의 범위는 first에서 last까지
////void inc_insertion_sort(int list[], int first, int last, int gap) {
////	int i, j, key;
////
////	for (i = first + gap; i <= last; i = i + gap) {
////		key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사
////
////		// 현재 정렬된 배열은 i-gap까지이므로 i-gap번째부터 역순으로 조사한다.
////		// j 값은 first 이상이어야 하고
////		// key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+gap번째로 이동
////		for (j = i - gap; j >= first && list[j] > key; j = j - gap) {
////			list[j + gap] = list[j]; // 레코드를 gap만큼 오른쪽으로 이동
////		}
////
////		list[j + gap] = key;
////	}
////}
////
////// 셸 정렬
////void shell_sort(int list[], int n) {
////	int i, gap;
////
////	for (gap = n / 2; gap > 0; gap = gap / 2) {
////		if ((gap % 2) == 0) {
////			gap++; // gap을 홀수로 만든다.
////		}
////		// 부분 리스트의 개수는 gap과 같다.
////		for (i = 0; i < gap; i++) {
////			// 부분 리스트에 대한 삽입 정렬 수행
////			inc_insertion_sort(list, i, n - 1, gap);
////		}
////	}
////}
////
////void main() {
////	int i;
////	int n = MAX_SIZE;
////
////
////	// 셸 정렬 수행
////
////	int* list = new int[MAX_SIZE];
////
////	for (int i = 0; i < MAX_SIZE; i++)
////	{
////		list[i] = rand() % MAX_SIZE;
////		//cout << pNumber[i] << endl;
////	}
////
////	shell_sort(list, n);
////	// 정렬 결과 출력
////	for (i = 0; i < n; i++) {
////		printf("%d\n", list[i]);
////	}
////
////}
//
//#include <iostream>
//#include<cstdlib>
//#include <time.h>
//
//#define SIZE 10000
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//void SelectSort(int* pNumber);
//void InsertSort(int*);
//void InsertSort(int* pNumber, int first, int iGap);
//void ShellSort(int*);
//void Swap(int*, int*);
//
//void Menu()
//{
//	cout << "----------------------------" << endl;
//	cout << "0.Select Sort" << endl;
//	cout << "1.Insert Sort" << endl;
//	cout << "2.Shell Sort" << endl;
//	cout << "3. Sort" << endl;
//	cout << "4. Sort" << endl;
//	cout << "(exit : -1)" << endl;
//	cout << "----------------------------" << endl;
//	cout << "Select Number : ";
//}
//
//
//int main()
//{
//	clock_t start, end;
//	double result;
//	int* pNumber = new int[SIZE];
//	int iSelect = 0;
//
//	srand((unsigned int)time(NULL));
//
//	while (true) {
//
//		for (int i = 0; i < SIZE; i++)
//		{
//			pNumber[i] = rand() % SIZE;
//			//cout << pNumber[i] << endl;
//		}
//		//int pNumber[4] = { 0,2,0,2 };
//
//		Menu();
//		cin >> iSelect;
//		system("cls");
//
//		switch (iSelect)
//		{
//		case 0:
//		{
//			start = clock();
//			SelectSort(pNumber);
//			end = clock(); // 시간 측정 끝
//			result = (double)(end - start);
//			cout << "[Insert][speed : " << result << "]" << endl;
//			//for (int i = 0; i < SIZE; i++) { cout << pNumber[i] << " "; }
//			cout << endl;
//		}break;
//		case 1:
//		{
//			start = clock();
//			InsertSort(pNumber, 0, 1);
//			end = clock(); // 시간 측정 끝
//			result = (double)(end - start);
//			for (int i = 0; i < SIZE; i++) { cout << pNumber[i] << " "; }
//			cout << endl;
//
//			cout << "[Shell][speed : " << result << "]" << endl;
//
//		}break;
//		case 2:
//		{
//			start = clock();
//			ShellSort(pNumber);
//			end = clock(); // 시간 측정 끝
//			result = (double)(end - start);
//			cout << "[Shell][speed : " << result << "]" << endl;
//			for (int i = 0; i < SIZE; i++) { cout << pNumber[i] << " "; }
//			cout << endl;
//		}break;
//		case -1:
//			cout << "----[exit]----" << endl;
//			return 0;
//		default:
//			break;
//			//ShellSort(pNumber);
//			//for (int i = 0; i < SIZE; i++) { cout << pNumber[i] << " "; }
//			//cout << endl;
//		//
//		}
//	}
//
//	return 0;
//
//}
//
//
//void Swap(int* x, int* y)
//{
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void SelectSort(int* pNumber)
//{
//	int iCount = 0;
//	for (int i = 0; i < SIZE; i++)
//	{
//		for (int j = i; j < SIZE; j++)
//		{
//			if (pNumber[i] > pNumber[j])
//			{
//				Swap(&pNumber[i], &pNumber[j]);
//
//			}
//			//iCount++;
//		}
//		for (int z = 0; z < SIZE; z++) { cout << pNumber[z] << " "; }
//		cout << endl;
//	}
//	//cout << "count : " << iCount << endl;
//}
//void InsertSort(int* pNumber, int first, int iGap)
//{
//
//
//	int target;
//	int prev;
//	bool check;
//	for (int key = first + iGap; key < SIZE; key += iGap)
//	{
//		check = false;
//		target = pNumber[key];
//		for (prev = key - iGap; prev >= first && pNumber[prev] > target; prev -= iGap)
//		{
//			pNumber[prev + iGap] = pNumber[prev];
//			/*if (target < pNumber[prev]) {
//				check = true;
//				pNumber[prev + iGap] = pNumber[prev];
//				if (prev - iGap < 0)
//				{
//					pNumber[prev] = target;
//					break;
//				}
//
//			}
//			else if (target >= pNumber[prev] && check == true)
//			{
//				pNumber[prev + iGap] = target;
//				break;
//			}
//			*/
//		}
//		pNumber[prev + iGap] = target;
//	}
//}
////void InsertSort(int* pNumber, int first, int iGap)
////{
////	int temp;
////	int prev;
////	bool result;
////	for (int i = 0; i < SIZE; i++) { cout << pNumber[i] << " "; }
////	cout << endl;
////	for (int key = first+iGap; key < SIZE; key++)
////	{
////		result = false;
////		temp = pNumber[key];
////		prev = key;
////		
////		for (int i = key-iGap; i >= 0; i-=iGap) {
////			if (temp <= pNumber[i])
////			{
////				if (result == false) {
////					result = true;
////				}
////				
////				pNumber[prev] = pNumber[i];
////				if (i - iGap < 0)
////				{
////					pNumber[i] = temp;
////					
////					return;
////				}
////			}
////			else if (temp >= pNumber[i] && result == true)
////			{
////				pNumber[i + iGap] = temp;
////				
////				return;
////			}
////			prev -= iGap;
////		}
////		
////		
////	}
////}
//
//
//void ShellSort(int* pNumber)
//{
//	//int iCount = 0;
//	int iGap = SIZE;
//
//	for (iGap /= 2; iGap > 0; iGap /= 2)
//	{
//		if ((iGap % 2) == 0) {
//			iGap++; // gap을 홀수로 만든다.
//		}
//		for (int i = 0; i < iGap; i++) {
//			InsertSort(pNumber, i, iGap);
//		}
//
//	}
//	//cout << "Shell : " << iCount << endl;
//}
//
//
//
///*void ShellSort(int* pNumber)
//{
//	int iCount = 0;
//	int iGap = SIZE;
//	while (true)
//	{
//		iGap /= 2;
//		for (int i = 0; i < iGap; i++)
//		{
//			for (int j = i; j < SIZE; j += iGap)
//			{
//				for (int k = j; k < SIZE; k += iGap)
//				{
//					if (pNumber[j] > pNumber[k])
//					{
//						Swap(&pNumber[j], &pNumber[k]);
//					}
//					iCount++;
//				}
//			}
//
//			cout << endl;
//		}
//
//		if (iGap == 1)
//			break;
//	}
//	cout << "Count : " << iCount << "번" << endl;
//
//
//
//
//
//}
//*/