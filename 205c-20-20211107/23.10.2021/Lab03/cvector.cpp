#include "cvector.h"

//-------------CVector--------------------------------------------------
int CVector::error=0;

CVector::CVector(unsigned int s)
{
    if(s == 0)
    {
        this->size=0;
        this->pVector=nullptr;
    }//if(s == 0)
    else
    {
        this->pVector=new complex[s];
        if(this->pVector != nullptr)
        {
            this->size=s;
            for(unsigned int i=0;i<this->size;i++)
                this->pVector[i]=0.;
        }//if(this->pVector != nullptr)
        else
        {
            this->size=0;
            this->error=-1;
        }//else if(this->pVector != nullptr)
    }//else if(s == 0)
}//CVector::CVector(unsigned int s)

CVector::CVector(const CVector &v)
{
    if(v.size == 0)
    {
        this->size=0;
        this->pVector=nullptr;
    }//if(this->pVector != nullptr)
    else
    {
        this->pVector=new complex [v.size];
        if(this->pVector != nullptr)
        {
            this->size=v.size;
            for(unsigned int i=0;i<this->size;i++)
                this->pVector[i]=v.pVector[i];
        }//if(this->pVector != nullptr)
        else
        {
            this->size=0;
            this->error=-1;
        }//else if(this->pVector != nullptr)
    }//else if(v.size == 0)

}//CVector::CVector(const CVector &v)

CVector::~CVector()
{
    if(this->pVector != nullptr) delete [] this->pVector;
}//CVector::~CVector()

void CVector::SetSize(unsigned int s)
{
    if(this->size == s) return;

    if(s == 0)
    {
        if(this->pVector != nullptr) delete [] this->pVector;

        this->size=0;
        this->pVector=nullptr;
    }//if(s == 0)
    else
    {
        complex *pV;
        pV=new complex [s];
        if(pV != nullptr)
        {
            for(unsigned int i=0;i<s;i++)
            {
                if(i<this->size) pV[i]=this->pVector[i];
                else pV[i]=0.;
            }//for(unsigned int i=0;i<s;i++)
            if(this->pVector != nullptr) delete [] this->pVector;

            this->pVector=pV;
            this->size=s;

        }//if(pV != nullptr)
        else this->error=-1;
    }//else if(s == 0)
}//void CVector::SetSize(unsigned int s)

complex CVector::Get(unsigned int index)const
{
    if(index<this->size) return this->pVector[index];
    else
    {
        this->error=-2;
        return 0.;
    }
}//complex CVector::Get(unsigned int index)const

void CVector::Set(unsigned int index,const complex &c)
{
    if(index<this->size) this->pVector[index]=c;
    else    this->error=-2;

}//void CVector::Set(unsigned int index,const complex &c)

CVector & CVector::operator=(const CVector &v)
{
    if(this->pVector != nullptr) delete [] this->pVector;

    if(v.size == 0)
    {
        this->size=0;
        this->pVector=nullptr;
    }//if(this->pVector != nullptr)
    else
    {
        this->pVector=new complex [v.size];
        if(this->pVector != nullptr)
        {
            this->size=v.size;
            for(unsigned int i=0;i<this->size;i++)
                this->pVector[i]=v.pVector[i];
        }//if(this->pVector != nullptr)
        else
        {
            this->size=0;
            this->error=-1;
        }//else if(this->pVector != nullptr)
    }//else if(v.size == 0)

    return *this;
}//CVector & CVector::operator=(const CVector &v)

CVector CVector::operator-()const
{
    CVector v(*this);

    for(unsigned int i=0;i<this->size;i++)
        v.pVector[i]=-v.pVector[i];

    return v;
}//CVector CVector::operator-()const

CVector operator+(const CVector &v1,const CVector &v2)
{
    CVector v;
    if(v1.size != v2.size){v.error=-2;return v;}

    v.SetSize(v1.size);

    for(unsigned int i=0;i<v.size;i++)
        v.pVector[i]=v1.pVector[i]+v2.pVector[i];

    return v;
}//CVector operator+(const CVector &v1,const CVector &v2)

CVector operator-(const CVector &v1,const CVector &v2)
{
    CVector v;
    if(v1.size != v2.size){v.error=-2;return v;}

    v.SetSize(v1.size);

    for(unsigned int i=0;i<v.size;i++)
        v.pVector[i]=v1.pVector[i]-v2.pVector[i];

    return v;
}//CVector operator-(const CVector &v1,const CVector &v2)

CVector operator*(const CVector &v1,const complex &c)
{
    CVector v(v1);

    for(unsigned int i=0;i<v.size;i++) v.pVector[i]*=c;

    return v;
}//CVector operator*(const CVector &v1,const complex &c)

CVector operator*(const complex &c,const CVector &v1)
{
    CVector v(v1);

    for(unsigned int i=0;i<v.size;i++) v.pVector[i]*=c;

    return v;
}//CVector operator*(const complex &c,const CVector &v1)

CVector operator/(const CVector &v1,const complex &c)
{
    CVector v(v1);

    for(unsigned int i=0;i<v.size;i++) v.pVector[i]/=c;

    return v;
}//CVector operator/(const CVector &v1,const complex &c)

CVector& CVector::operator+=(const CVector &v)
{
    if(this->size != v.size) this->error=-2;
    else
    {
        for(unsigned int i=0;i<this->size;i++)
            this->pVector[i]+=v.pVector[i];

    }//else if(this->size != v.size)

    return *this;
}//CVector& CVector::operator+=(const CVector &v)

CVector& CVector::operator-=(const CVector &v)
{
    if(this->size != v.size) this->error=-2;
    else
    {
        for(unsigned int i=0;i<this->size;i++)
            this->pVector[i]-=v.pVector[i];

    }//else if(this->size != v.size)

    return *this;
}//CVector& CVector::operator-=(const CVector &v)

CVector& CVector::operator*=(const complex &c)
{
    for(unsigned int i=0;i<this->size;i++) this->pVector[i]*=c;

    return *this;
}//CVector& CVector::operator*=(const complex &c)

CVector& CVector::operator/=(const complex &c)
{
    for(unsigned int i=0;i<this->size;i++) this->pVector[i]/=c;

    return *this;
}//CVector& CVector::operator/=(const complex &c)

double CVector::norm()const
{
    double res=0.;

    for(unsigned int i=0;i<this->size;i++)
        res+=   this->pVector[i].real()*this->pVector[i].real()+
                this->pVector[i].imag()*this->pVector[i].imag();

    return sqrt(res);
}//double CVector::norm()const

double CVector::norm2()const
{
    double res=0.;

    for(unsigned int i=0;i<this->size;i++)
        res+=   this->pVector[i].real()*this->pVector[i].real()+
                this->pVector[i].imag()*this->pVector[i].imag();

    return (res);
}//double CVector::norm2()const

complex scalar(const CVector &v1,const CVector &v2)
{
    complex res=0.;

    if(v1.size != v2.size) v1.error=-2;
    else
    {
        for(unsigned int i=0;i<v1.size;i++)
            res+=v1.pVector[i]*conj(v2.pVector[i]);

    }//else if(v1.size != v2.size) v1.error=-2;

    return res;
}//complex scalar(const CVector &v1,const CVector &v2)

//-------------\CVector--------------------------------------------------

void Print(const CVector &v)
{
    printf("\n\n\tv_size=%u v_error=%d",v.GetSize(),v.GetError());

    for(unsigned int i=0;i<v.GetSize();i++)
        printf("\n\tv[%u]=(%lg,%lg)",i,v.Get(i).real(),v.Get(i).imag());
}//void Print(const CVector &v)

void fPrint(FILE *file,const CVector &v)
{
    fprintf(file,"\n\n\tv_size=%u v_error=%d",v.GetSize(),v.GetError());

    for(unsigned int i=0;i<v.GetSize();i++)
        fprintf(file,"\n\tv[%u]=(%lg,%lg)",i,v.Get(i).real(),v.Get(i).imag());
}//void fPrint(FILE *file,const CVector &v)
