#ifndef _Vectorrechnung_h
#define _Vectorrechnung_h


#define _USE_MATH_DEFINES
#include <math.h>


class Vector3
{
public:
	Vector3() 
		: x(0), y(0),z(0) {}
	Vector3(float xn, float yn, float zn) 
		: x(xn), y(yn), z(zn) {}
	float betrag() {return sqrt(x*x+y*y+z*z);}
	void operator = (Vector3 const & aVector3) {x = aVector3.x; y = aVector3.y; z = aVector3.z;}
	float x,y,z; 
};

inline Vector3 operator + (Vector3 const &lvalue, Vector3 const &rvalue) 
{
	return Vector3(lvalue.x + rvalue.x, lvalue.y + rvalue.y, lvalue.z + rvalue.z);
};

inline Vector3 operator * (float afloat, Vector3 const & aVector3)
{
	return Vector3(afloat*aVector3.x, afloat*aVector3.y, afloat*aVector3.z);
};

inline float skalarprodukt(Vector3 const &Vec1, Vector3 const &Vec2)
{
	return (Vec1.x*Vec2.x+Vec1.y*Vec2.y+Vec1.z*Vec2.z);
};

inline float skalarsumme (Vector3 const & Vec1, Vector3 const &Vec2)
{
	return Vec1.x + Vec1.y + Vec1.z + Vec2.x + Vec2.y + Vec2.z;
};

inline float operator * (Vector3 const &Vec1, Vector3 const &Vec2)
{
	return skalarprodukt(Vec1, Vec2);
};

inline Vector3 kreuzprodukt (Vector3 const &Vec1, Vector3 const &Vec2) 
 {
	Vector3 produkt;

	produkt.x =	Vec1.y * Vec2.z - Vec1.z * Vec2.y;
	produkt.y = Vec1.z * Vec2.x - Vec1.x * Vec2.z;
	produkt.z = Vec1.x * Vec2.y - Vec1.y * Vec2.x;

	return (produkt);
};

inline float betrag (Vector3 const &Vec) 
{
	return sqrt(Vec*Vec);
};

inline Vector3 einheitsvector (Vector3 const &Vec)
{
	

	return (1 / betrag(Vec))*Vec;
};

inline Vector3 rotatedBy(Vector3 const &axis, float angleDeg, Vector3 const &x)
{	
	// Rotation by Angular Displacement
	// (1-cos(a))<x,A>A  +  cos(a)*x  +  sin(a)*(x "kreuz" A)

	float const angleRad = angleDeg/180*M_PI;	// inlcude <math.h>
	float const cosA = cos(angleRad);
	float const sinA = sin(angleRad);

	return (1-cosA)*skalarprodukt(x,axis)*axis + cosA*x + sinA*kreuzprodukt(axis,x);
};

inline bool operator == (Vector3 const &Vec1, Vector3 const & Vec2) {return (Vec1.x == Vec2.x && Vec1.y == Vec2.y && Vec1.z == Vec2.z);};
inline bool operator != (Vector3 const &Vec1, Vector3 const & Vec2) {return (!(Vec1 == Vec2));};
#endif
