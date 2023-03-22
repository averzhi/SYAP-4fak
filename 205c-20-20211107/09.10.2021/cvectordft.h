#ifndef CVECTORDFT_H
#define CVECTORDFT_H

#include "cvector.h"

class CVectorDFT : public CVector
{
public:
    CVectorDFT(unsigned int s=0):CVector(s){}
    CVectorDFT(const CVectorDFT &v):CVector(v){}
    CVectorDFT(const CVector &v):CVector(v){}

    void DFT(CVectorDFT &v)const;
    void IDFT(CVectorDFT &v)const;

    void Restore(CVectorDFT &v)const;
};

#endif // CVECTORDFT_H
