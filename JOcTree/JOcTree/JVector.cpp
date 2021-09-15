#include"JVector.h"

JVector3::JVector3(float fX, float fY, float fZ){
	this->x = fX;
	this->y = fY;
	this->z = fZ;
}

JVector3 JVector3::operator + (JVector3 pos){
	JVector3 ret;
	ret.x = this->x + pos.x;
	ret.y = this->y + pos.y;
	ret.z = this->z + pos.z;
	return ret;
}

JVector3 JVector3::operator += (JVector3 pos){
	this->x += pos.x;
	this->y += pos.y;
	this->z += pos.z;
	return *this;
}

JVector3 JVector3::operator - (JVector3 pos){
	JVector3 ret;
	ret.x = this->x - pos.x;
	ret.y = this->y - pos.y;
	ret.z = this->z - pos.z;
	return ret;
}

JVector3 JVector3::operator*(float t)
{
	JVector3 ret;
	ret.x = this->x * t;
	ret.y = this->y * t;
	ret.z = this->z * t;
	return ret;
}

float JVector3::operator | (JVector3 pos){
	return (this->x * pos.x) + (this->y * pos.y)+ (this->z * pos.z);
}





JRact::JRact() {
	p0 = JVector3(0, 0);
	p1 = JVector3(0, 0);
	whl = JVector3(0, 0);
}
