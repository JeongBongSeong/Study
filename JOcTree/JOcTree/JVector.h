#include"JStd.h"
#include <math.h>
struct JVector3
{
	float x;
	float y;
	float z;

public:
	JVector3() : x(0.0f), y(0.0f), z(0.0f) {};		// �ʱ�ȭ
	JVector3(float, float, float);			// �ʱ�ȭ
	JVector3	operator +	(JVector3);		// ���� ���ϱ�
	JVector3	operator +=	(JVector3);		// ���� ���ϱ�
	JVector3	operator -	(JVector3);		// ���� ����
	JVector3	operator *	(float);
	float		operator |	(JVector3);		// ���� ����
	//JVector2	operator +	(JVector2);		//


};

class JRact {
public:
	JVector3 p0;
	JVector3 p1;
	JVector3 whl;
public:
	JRact();
};
