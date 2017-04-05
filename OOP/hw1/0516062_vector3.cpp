#include <cmath>
#include <iostream>

#include "vector3.h"

vector3::vector3()
{
	this->x=0;
	this->y=0;
	this->z=0;
};

vector3::vector3(float inX, float inY, float inZ)
{
	this->x=inX;
	this->y=inY;
	this->z=inZ;
};

vector3::vector3(const vector3 &v)
{
	this->x=v.x;
	this->y=v.y;
	this->z=v.z;
}

void vector3::set(float xIn, float yIn, float zIn)
{
	this->x=xIn;
	this->y=yIn;
	this->z=zIn;	
}

float vector3::length() const
{
	return sqrt(this->x*this->x+this->y*this->y+this->z*this->z);
}

//not finished
void vector3::printVector3() const
{
	std::cout << this->x <<" "<< this->y <<" "<< this->z;
}

float                 &vector3::operator [] (unsigned int index)
{

	switch(index)
	{
		case 0:
		return this->x;
		case 1:
		return this->y;
		case 2:
		return this->z;
		default:
		float a=0;
		float &re=a;
		return re;
	}
}

const float           &vector3::operator [] (unsigned int index) const
{
	switch(index)
	{
		case 0:
		return this->x;
		case 1:
		return this->y;
		case 2:
		return this->z;
		default:
		float a=0;
		float &re=a;
		return re;
	}
	
}

vector3               &vector3::operator =  (const vector3 &v)
{
	this->x=v.x;
	this->y=v.y;
	this->z=v.z;
	return *this;
}

vector3               &vector3::operator += (const vector3 &v)
{
	(*this)=(*this)+v;
	return (*this);
}

vector3               &vector3::operator -= (const vector3 &v)
{
	(*this)=(*this)-v;
	return (*this);
}

vector3               &vector3::operator *= (float f)
{
	(*this)=(*this)*f;
	return (*this);
}

vector3               &vector3::operator /= (float f)
{
	(*this)=(*this)/f;
	return (*this);
}

bool           operator == (const vector3 &a, const vector3 &b)
{
	if(a.x==b.x && a.y==b.y && a.z==b.z)
		return true;
	else
		return false;
	
}

bool           operator != (const vector3 &a, const vector3 &b)
{
	if(a==b)
		return false;
	else
		return true;
}

vector3        operator - (const vector3 &a)
{
	vector3 vecOut=vector3(a);
	vecOut.x = -vecOut.x;
	vecOut.y = -vecOut.y;
	vecOut.z = -vecOut.z;
	return vecOut;
}

vector3        operator + (const vector3 &a, const vector3 &b)
{
	vector3 vecOut=vector3();
	vecOut.x=a.x+b.x;
	vecOut.y=a.y+b.y;
	vecOut.z=a.z+b.z;
	return vecOut;
}

vector3        operator - (const vector3 &a, const vector3 &b)
{
	vector3 vecOut=vector3();
	vecOut.x=a.x-b.x;
	vecOut.y=a.y-b.y;
	vecOut.z=a.z-b.z;
	return vecOut;
}

vector3        operator * (const vector3 &v, float f)
{
	vector3 vecOut=vector3();
	vecOut.x=v.x*f;
	vecOut.y=v.y*f;
	vecOut.z=v.z*f;
	return vecOut;
}

vector3        operator * (float f, const vector3 &v)
{
	return v*f;
}



vector3        operator / (const vector3 &v, float f)
{
	vector3 vecOut=vector3();
	vecOut.x=v.x/f;
	vecOut.y=v.y/f;
	vecOut.z=v.z/f;
	return vecOut;
}


