#include"JStd.h"
#include <math.h>
struct JVector3
{
	float x;
	float y;
	float z;

public:
	JVector3() : x(0.0f), y(0.0f), z(0.0f) {};		// √ ±‚»≠
	JVector3(float, float, float);			// √ ±‚»≠
	JVector3	operator +	(JVector3);		// ∫§≈Õ ¥ı«œ±‚
	JVector3	operator +=	(JVector3);		// ∫§≈Õ ¥ı«œ±‚
	JVector3	operator -	(JVector3);		// ∫§≈Õ ª©±‚
	JVector3	operator *	(float);
	float		operator |	(JVector3);		// ∫§≈Õ ≥ª¿˚
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
