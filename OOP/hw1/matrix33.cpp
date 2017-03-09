#include <iostream>
#include <cmath>
#include "matrix33.h"

matrix33::matrix33()
{
	vector3 zero(0,0,0);
	this->column1=zero;
	this->column2=zero;
	this->column3=zero;
};

matrix33::matrix33(const vector3 &vec1, const vector3 &vec2, const vector3 &vec3 )
{
	this->column1=vec1;
	this->column2=vec2;
	this->column3=vec3;
};

matrix33::matrix33(const matrix33 &m)
{
	*this=m;
};

void matrix33::printMatrix()
{
	int t;
	for(int t=0;t<=2;t++)
	{
		std::cout<<this->column1[t]<<" "<<this->column2[t]<<" "<<this->column3[t]<<" "<<"\n";
	}
}

void matrix33::identity()
{
	
	this->column1=vector3(1,0,0);
	this->column2=vector3(0,1,0);
	this->column3=vector3(0,0,1);
}

float matrix33::determinant()
{
	float ans=0;

	ans+=(*this)[0][0] * ( (*this)[1][1]*(*this)[2][2] - (*this)[2][1]*(*this)[1][2] );
	ans-=(*this)[1][0] * ( (*this)[0][1]*(*this)[2][2] - (*this)[2][1]*(*this)[0][2] );
	ans+=(*this)[2][0] * ( (*this)[0][1]*(*this)[1][2] - (*this)[1][1]*(*this)[0][2] );

	return ans;
}

matrix33 matrix33::invert()
{
	matrix33 matOut;

	if((*this).determinant() != 0)
	{
		matOut[0][0]= (*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1] ;
		matOut[0][1]= -((*this)[0][1] * (*this)[2][2] - (*this)[2][1] * (*this)[0][2]) ;
		matOut[0][2]= (*this)[0][1] * (*this)[1][2] - (*this)[1][1] * (*this)[0][2] ;

		matOut[1][0]= -((*this)[1][0] * (*this)[2][2] - (*this)[2][0] * (*this)[1][2]) ;
		matOut[1][1]= (*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0] ; 
		matOut[1][2]= -((*this)[0][0] * (*this)[1][2] - (*this)[1][0] * (*this)[0][2]) ;

		matOut[2][0]= (*this)[1][0] * (*this)[2][1] - (*this)[2][0] * (*this)[1][1] ;
		matOut[2][1]= -((*this)[0][0] * (*this)[2][1] - (*this)[2][0] * (*this)[0][1]) ;
		matOut[2][2]= (*this)[0][0] * (*this)[1][1] - (*this)[1][0] * (*this)[0][1] ;

		matOut *= 1/(*this).determinant();

		return matOut;
	}



	
	



}

matrix33 matrix33::transpose()
{
	matrix33 matOut;
	int t,t1;
	for(t=0;t<3;t++)
	{
		for(t1=0;t1<3;t1++)
		{
			matOut[t][t1]=(*this)[t1][t];
		}
	}
	return matOut;
}

vector3 &matrix33::operator [] (unsigned int index)
{

	switch(index)
	{
		case 0:
		return this->column1;
		case 1:
		return this->column2;
		case 2:
		return this->column3;
		default:
		vector3 a=vector3();
		vector3 &re=a;
		return re;
	}	

}

const vector3 &matrix33::operator [](unsigned int index) const
{
	
	switch(index)
	{
		case 0:
		return this->column1;
		case 1:
		return this->column2;
		case 2:
		return this->column3;
		default:
		vector3 a=vector3();
		vector3 &re=a;
		return re;
	}
}

matrix33 operator + (const matrix33 &m1, const matrix33 &m2)
{
	matrix33 matOut=matrix33();

	int t,t1;
	for(t=0;t<3;t++)
	{
		for(t1=0;t1<3;t1++)
		{
			matOut[t][t1]=m1[t][t1]+m2[t][t1];
		}
	}
	return matOut;
}

matrix33 operator - (const matrix33 &m1, const matrix33 &m2)
{
	matrix33 matOut=matrix33();
	int t,t1;
	for(t=0;t<3;t++)
	{
		for(t1=0;t1<3;t1++)
		{
			matOut[t][t1]=m1[t][t1]-m2[t][t1];
		}
	}
	return matOut;
}

matrix33 operator * (const matrix33 &m1, float f)
{
	matrix33 matOut=matrix33();

	int t,t1;
	for(t=0;t<3;t++)
	{
		for(t1=0;t1<3;t1++)
		{
			matOut[t][t1]=m1[t][t1]*f;
		}
	}
	return matOut;
}

matrix33 operator * (float f, const matrix33 &m1)
{
	matrix33 matOut=matrix33();
	matOut= m1 * f;
	return matOut;
}

matrix33 operator * (const matrix33 &m1, const matrix33 &m2)
{
	matrix33 matOut=matrix33();
	int t,t1;
	for(t=0;t<3;t++)
	{
		for(t1=0;t1<3;t1++)
		{
			int a;
			for(a=0;a<3;a++)
			{
				matOut[t][t1]+=m2[t][a]*m1[a][t1];
			}
		}
	}
	return matOut;
}

bool operator == (const matrix33 &m1, const	matrix33 &m2)
{
	int t,t1;
	for(t=0;t<3;t++)
	{
		for(t1=0;t1<3;t1++)
		{
			if(m1[t][t1] != m2[t][t1])
				return false;
		}
	}
	return true;
}

bool operator != (const matrix33 &m1, const matrix33 &m2)
{
	if(m1==m2)
		return false;
	return true;
}

matrix33 &matrix33::operator +=(const matrix33 &m)
{
	(*this)=(*this)+m;
	return (*this);
}

matrix33 &matrix33::operator -=(const matrix33 &m)
{
	(*this)=(*this)-m;
	return (*this);
}

matrix33 &matrix33::operator *=(const matrix33 &m)
{
	(*this)=(*this)*m;
	return (*this);
}

matrix33 &matrix33::operator *=(float f)
{
	(*this)= (*this) * f;
	return (*this);
}





