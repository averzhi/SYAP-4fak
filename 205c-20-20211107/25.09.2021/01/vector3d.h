#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <math.h>

class Vector3D
{  
private:
    double _x,_y,_z;

public:
    //Vector3D();
    inline Vector3D(double x=0.,double y=0.,double z=0.)
        {this->_x=x;this->_y=y;this->_z=z;}
    inline Vector3D(const Vector3D &v)
        {this->_x=v._x;this->_y=v._y;this->_z=v._z;}

    inline ~Vector3D(){}

    inline double GetX()const{return this->_x;}
    inline double GetY()const{return this->_y;}
    inline double GetZ()const{return this->_z;}
    inline void GetXYZ(double &x,double &y,double &z)const
        {x=this->_x;y=this->_y;z=this->_z;}

    inline void SetX(double x=0.){this->_x=x;}
    inline void SetY(double y=0.){this->_y=y;}
    inline void SetZ(double z=0.){this->_z=z;}
    inline void SetXYZ(double x=0.,double y=0.,double z=0.)
        {this->_x=x;this->_y=y;this->_z=z;}

    inline Vector3D & operator=(const Vector3D & v)
        {this->_x=v._x;this->_y=v._y;this->_z=v._z;return *this;}
    Vector3D operator-()const;

    friend Vector3D operator+(const Vector3D &v1,const Vector3D &v2);
    friend Vector3D operator-(const Vector3D &v1,const Vector3D &v2);
    friend Vector3D operator*(const Vector3D &v1,const Vector3D &v2);
    friend Vector3D operator*(const Vector3D &v1,const double &d);
    friend Vector3D operator*(const double &d,const Vector3D &v1);
    friend Vector3D operator/(const Vector3D &v1,const double &d);

    Vector3D & operator+=(const Vector3D &v);
    Vector3D & operator-=(const Vector3D &v);
    Vector3D & operator*=(const Vector3D &v);
    Vector3D & operator*=(const double &d);
    Vector3D & operator/=(const double &d);

    double norm()const{return sqrt(this->_x*this->_x+this->_y*this->_y+this->_z*this->_z);}
    double norm2()const{return (this->_x*this->_x+this->_y*this->_y+this->_z*this->_z);}

    friend double scalar(const Vector3D &v1,const Vector3D &v2);
};//class Vector3D

#endif // VECTOR3D_H
