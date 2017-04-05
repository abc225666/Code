#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"

class matrix33 
{  
public:
	vector3 column1;
	vector3 column2;
	vector3 column3;

public:
	matrix33();

	matrix33(const vector3 &vec1,const vector3 &vec2 ,const vector3 &vec3 );

	matrix33(const matrix33 &m);

public:
	void printMatrix();
	void identity();
	float determinant();
	matrix33 invert();

	vector3 &operator [] (unsigned int index);
	const vector3 &operator [](unsigned int index) const;

	matrix33 &operator *= (const matrix33 &m);
	matrix33 &operator *= (float f);
	matrix33 &operator += (const matrix33 &m);
	matrix33 &operator -= (const matrix33 &m);
	friend bool operator == (const matrix33 &m1, const matrix33 &m2);
	friend bool operator != (const matrix33 &m1, const matrix33 &m2);
	friend matrix33 operator + (const matrix33 &m1, const matrix33 &m2);
	friend matrix33 operator * (const matrix33 &m1, float f);
	friend matrix33 operator * (float f, const matrix33 &m1);
	friend matrix33 operator * (const matrix33 &m1, const matrix33 &m2);
	friend matrix33 operator - (const matrix33 &m1, const matrix33 &m2);

public:

	matrix33 transpose();


};

#endif