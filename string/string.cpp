#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


int main()
{
	// 싱글바이트(1) : 1문자를 표현하는 메모리 바이트
	// 멀티바이트(1 or 2) : English한국어  (글자당 == 영어 : 1바이트, 한국어 : 2바이트)	(예: KGCA게임)
	// 영어만 사용 시 싱글바이트 영어 외 한국어 일본어등 사용 시 멀티 바이트
	// 유니코드(Only 2) ; 국제표준 (예: KGCA게임)
	//char data3[] = "KGCA";
	//char data4[] = " Game";
	//char copy[200] = { 0, };
	//int iLength = strlen(data3);
	//// 버퍼오버런 문제를 해결하기 위해서
	//strcpy_s(copy,_countof(copy), data3);
	//strcpy_s(&copy[iLength], _countof(
	//	copy)-iLength, data4);
	//printf("%s SUCCESS!\n", copy);


	std::string data1 = "TEST ";
	std::string data2 = "게임아카";
	std::string sum = data1 + data2;
	int iLen = sum.size();
	if (data1 <= data2)
		std::cout << sum << " SUCCESS!\n";
	std::cout << iLen << std::endl;


	std::wstring data3 = L"TEST ";
	std::wstring data4 = L"게임아카";
	std::wstring wSum = data3 + data4;
	int iWLen = wSum.size();	//글자 수를 가져온다.
	if (data3 <= data4)
		std::wcout << wSum << " SUCCESS!\n";
	std::cout << iWLen << std::endl;

}