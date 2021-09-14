#pragma once

#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<string>
#include<queue>
using namespace std;

struct CVector2
{
	float x;
	float y;

	

	CVector2 operator + (CVector2 p) 
	{
		CVector2 ret;
		ret.x = this->x + p.x;
		ret.y = this->y + p.y;
		return ret;
	}

	CVector2() {}
	CVector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};


struct TRect
{
	CVector2 p0;
	CVector2 p1;
	CVector2 wh;

};