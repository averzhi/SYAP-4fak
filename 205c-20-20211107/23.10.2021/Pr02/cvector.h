#ifndef CVECTOR_H
#define CVECTOR_H

#include <complex>
typedef std::complex<double> complex;
#include <stdio.h>
#include <math.h>

class CVector
{
private:
//protected:
    unsigned int size;
    //std::complex<double> *pVector;
    complex *pVector;

    static int error;

public:
    static int GetError(){return CVector::error;}
    static void SetError(int e=0){CVector::error=e;}

    CVector(unsigned int s=0);
    CVector(const CVector &v);

    ~CVector();

    inline unsigned GetSize()const{return this->size;}
    void SetSize(unsigned int s=0);

    complex Get(unsigned int index=0)const;
    void Set(unsigned int index=0,const complex &c=0.);

    CVector & operator=(const CVector &v);
    CVector operator-()const;
    inline complex& operator[](unsigned int index){return this->pVector[index];}

    friend CVector operator+(const CVector &v1,const CVector &v2);
    friend CVector operator-(const CVector &v1,const CVector &v2);
    friend CVector operator*(const CVector &v1,const complex &c);
    friend CVector operator*(const complex &c,const CVector &v1);
    friend CVector operator/(const CVector &v1,const complex &c);

    CVector& operator+=(const CVector &v);
    CVector& operator-=(const CVector &v);
    CVector& operator*=(const complex &c);
    CVector& operator/=(const complex &c);

    double norm()const;
    double norm2()const;

    friend complex scalar(const CVector &v1,const CVector &v2);

};

void Print(const CVector &v);

#endif // CVECTOR_H
