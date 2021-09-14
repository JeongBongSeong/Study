// map.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <string>


class THuman
{
public:
    int m_iAge;
    std::wstring sAdd;
    std::wstring sTel;
public:
    THuman() {};
    THuman(int age, std::wstring add, std::wstring tel);
    void Set(int age, std::wstring add, std::wstring tel);
};

THuman::THuman(int age, std::wstring add, std::wstring tel) : m_iAge(age), sAdd(add), sTel(tel) {}
void THuman::Set(int age, std::wstring add, std::wstring tel)
{
    m_iAge = age;
    sAdd = add;
    sTel = tel;
}

int main()
{
    
    //std::map<std::wstring,THuman> map; // 키 값 한쌍구축된 자료구조  // map은 기본이 bst  // 엄청많은 양의 데이터에서 검색을 빠르게 하기위해 사용한다. // 관리하기위한 목적 // 인덱싱은 벡터랑 맵만 지원한다.
    //THuman h1, h2, h3, h4, h5, h6;

    //h1.Set(1, L"서울", L"010-1111-3395");
    //h2.Set(2, L"경기", L"010-2222-3395");
    //h3.Set(3, L"인천", L"010-3333-3395");
    //h4.Set(4, L"부산", L"010-4444-3395");
    //h5.Set(5, L"울산", L"010-5555-3395");
    //h6.Set(6, L"천안", L"010-6666-3395");


    //map[L"김씨"] = h1;
    //map[L"나씨"] = h2;
    //map[L"박씨"] = h3;
    //map[L"이씨"] = h4;
    //map.insert(std::make_pair(L"정씨", &h5));
    //map[L"오씨"] = h4;

    //for (std::map<std::wstring, int>::reverse_iterator it = map.rbegin();it !=map.rend(); it++)
    //{
    //    std::wcout << it->first << std::endl;
    //}

    std::map<std::wstring, THuman*> map2; // 키 값 한쌍구축된 자료구조  // map은 기본이 bst  // 엄청많은 양의 데이터에서 검색을 빠르게 하기위해 사용한다. // 관리하기위한 목적 // 인덱싱은 벡터랑 맵만 지원한다.
    THuman* pH2 = new THuman();
    THuman* pH3 = new THuman();
    THuman* pH1 = new THuman();
    THuman* pH4 = new THuman();
    THuman* pH5 = new THuman();
    THuman* pH6 = new THuman();

    pH1->Set(1, L"서울", L"010-1111-3395");
    pH2->Set(2, L"경기", L"010-2222-3395");
    pH3->Set(3, L"인천", L"010-3333-3395");
    pH4->Set(4, L"부산", L"010-4444-3395");
    pH5->Set(5, L"울산", L"010-5555-3395");
    pH6->Set(6, L"천안", L"010-6666-3395");


    map2[L"김씨"] = pH1;
    map2[L"나씨"] = pH2;
    map2[L"박씨"] = pH3;
    map2[L"이씨"] = pH4;
    map2.insert(std::make_pair(L"정씨", pH5));
    map2.insert(std::make_pair(L"오씨", pH6));

    std::map<std::wstring, THuman*>::iterator iter2 = map2.find(L"정씨");

    if (iter2 != map2.end())
    {
        std::wstring iKey = iter2->first;
        THuman* data = (THuman*)(iter2->second);
        data->m_iAge = 99;
        std::wcout << iKey << " ";
        std::wcout << data->m_iAge << "Hello World!\n";
        delete data;
        data = nullptr;
        map2.erase(iter2);
    }
    for (std::map < std::wstring, THuman*>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << it->second->m_iAge << std::endl;
        THuman* data = it->second;
        delete data;
        data = nullptr;
    }
    map2.clear();    
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메   뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
