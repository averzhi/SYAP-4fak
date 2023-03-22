#include "vector3d.h"

/*
Vector3D::Vector3D()
{
    this->_x=this->_y=this->_z=0.;
}//Vector3D::Vector3D()
*/

Vector3D Vector3D::operator-()const
{
    Vector3D v(*this);

    v._x=-v._x;v._y=-v._y;v._z=-v._z;

    return v;
}//Vector3D Vector3D:operator-()const

Vector3D operator+(const Vector3D &v1,const Vector3D &v2)
{
    Vector3D v;

    v._x=v1._x+v2._x;
    v._y=v1._y+v2._y;
    v._z=v1._z+v2._z;

    return v;
}//Vector3D operator+(const Vector3D &v1,const Vector3D &v2)

Vector3D operator-(const Vector3D &v1,const Vector3D &v2)
{
    Vector3D v;

    v._x=v1._x-v2._x;
    v._y=v1._y-v2._y;
    v._z=v1._z-v2._z;

    return v;
}//Vector3D operator-(const Vector3D &v1,const Vector3D &v2)

Vector3D operator*(const Vector3D &v1,const Vector3D &v2)
{
    Vector3D v;

    v._x=v1._y*v2._z-v1._z*v2._y;
    v._y=v1._z*v2._x-v1._x*v2._z;
    v._z=v1._x*v2._y-v1._y*v2._x;

    return v;
}//Vector3D operator*(const Vector3D &v1,const Vector3D &v2)

Vector3D operator*(const Vector3D &v1,const double &d)
{
    Vector3D v(v1);

    v._x*=d;v._y*=d;v._z*=d;

    return v;
}//Vector3D operator*(const Vector3D &v1,const double &d)

Vector3D operator*(const double &d,const Vector3D &v1)
{
    Vector3D v(v1);

    v._x*=d;v._y*=d;v._z*=d;

    return v;
}//Vector3D operator*(const double &d,const Vector3D &v1)

Vector3D operator/(const Vector3D &v1,const double &d)
{
    Vector3D v(v1);

    v._x/=d;v._y/=d;v._z/=d;

    return v;
}//Vector3D operator/(const Vector3D &v1,const double &d)

Vector3D & Vector3D::operator+=(const Vector3D &v)
{
    this->_x+=v._x;
    this->_y+=v._y;
    this->_z+=v._z;

    return *this;
}//Vector3D & Vector3D::operator+=(const Vector3D &v)

Vector3D & Vector3D::operator-=(const Vector3D &v)
{
    this->_x-=v._x;
    this->_y-=v._y;
    this->_z-=v._z;

    return *this;
}//Vector3D & Vector3D::operator-=(const Vector3D &v)

Vector3D & Vector3D::operator*=(const Vector3D &v)
{
    double x,y,z;
    this->GetXYZ(x,y,z);

    this->_x=y*v._z-z*v._y;
    this->_y=z*v._x-x*v._z;
    this->_z=x*v._y-y*v._x;

    return *this;
}//Vector3D & Vector3D::operator*=(const Vector3D &v)

Vector3D & Vector3D::operator*=(const double &d)
{
    this->_x*=d;this->_y*=d;this->_z*=d;
    return *this;
}//Vector3D & Vector3D::operator*=(const double &d)

Vector3D & Vector3D::operator/=(const double &d)
{
    this->_x/=d;this->_y/=d;this->_z/=d;
    return *this;
}//Vector3D & Vector3D::operator/=(const double &d)

double scalar(const Vector3D &v1,const Vector3D &v2)
{
    return v1._x*v2._x+v1._y*v2._y+v1._z*v2._z;
}//double scalar(const Vector3D &v1,const Vector3D &v2)
