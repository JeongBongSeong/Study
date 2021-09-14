#include <iostream>

class Pointer
{
protected:
	int x;
	int y;
public:
	Pointer(): x(NULL),y(NULL) {}
	Pointer(int, int);
	void Set(int, int);
	int GetX() { return x; }
	int GetY() { return y; }
};
Pointer::Pointer(int ix,int iy) : x(ix),y(iy){}
void Pointer::Set(int ix, int iy)
{
	this->x = ix;
	this->y = iy;
}

class Square
{
private:
	Pointer* m_pStartPointer;
	int width;			//너비 , 가로
	int height;			//깊이 , 세로
public:
	Square();
	Square(int x, int y, int w, int h);
	void Set(int x, int y, int w, int h);
	int GetX() { return m_pStartPointer->GetX(); }
	int GetY() { return m_pStartPointer->GetY(); }
	int GetW() { return width; }
	int GetH() { return height; }
	int GetMaxX() { return GetX() + width; }	//가로
	int GetMinX() { return GetX(); }
	int GetMaxY() { return GetY() + height; }	//세로 
	int GetMinY() { return GetY(); }
};
Square::Square() : m_pStartPointer(nullptr),width(NULL),height(NULL){}
Square::Square(int x, int y, int w, int h)
	:m_pStartPointer(new Pointer(x, y)), width(w), height(h) {}


void Square::Set(int x, int y, int w, int h)
{
	if (m_pStartPointer != nullptr)
	{
		std::cout << "data is collision!!" << std::endl;
		return;
	}
	m_pStartPointer = new Pointer(x,y);
	width = w;
	height = h;
}
class Collision
{
public:
	static bool Collision_Check(Square *s1, Square* s2);
};

bool Collision::Collision_Check(Square* s1, Square* s2)
{
	Pointer* pStart = new Pointer();
	int iMinX, iMinY;
	int iMaxX, iMaxY;
	//s1의 시작 iMinXY과 s2 시작 iMinXY을 비교하여 더 작은 곳이 두개의 전체 범위의 시작지점
	if (s1->GetMinX() < s2->GetMinX())	{ iMinX = s1->GetMinX(); }
	else								{ iMinX = s2->GetMinX(); }

	if (s1->GetMinY() < s2->GetMinY())	{ iMinY = s1->GetMinY(); }
	else								{ iMinY = s2->GetMinY(); }

	//s1의 시작 iMaxXY과 s2 시작 iMaxXY을 비교하여 더 큰 곳이 두개의 전체 범위의 시작지점
	if (s1->GetMaxX() > s2->GetMaxX())	{ iMaxX = s1->GetMaxX(); }
	else								{ iMaxX = s2->GetMaxX(); }

	if (s1->GetMaxY() > s2->GetMaxY())	{ iMaxY = s1->GetMaxY(); }
	else								{ iMaxY = s2->GetMaxY(); }
	
	/*
	std::cout << "iMinX : " << iMinX << std::endl;
	std::cout << "iMinY : " << iMinY << std::endl;
	std::cout << "iMaxX : " << iMaxX << std::endl;
	std::cout << "iMaxY : " << iMaxY << std::endl;
	*/
	if (s1->GetW() + s2->GetW() < iMaxX-iMinX)
	{
		if (s1->GetH() + s2->GetH() < iMaxY-iMinY)
			return false;
		else
			return true;
	}
	else
		return true;
}


int main()
{
	bool result = false;
	Square *m1, *m2;
	
	m1 = new Square();
	m2 = new Square(20, 20, 40, 40);
	m1->Set(9, 9, 10, 10);
	
	result = Collision:: Collision_Check(m1, m2);
	
	
	if (result == true)
		std::cout << "Collision!!" << std::endl;
	else
		std::cout << "Safety!!" << std::endl;


	
}
