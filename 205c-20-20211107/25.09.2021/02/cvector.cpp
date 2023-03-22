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
//-------------\CVector--------------------------------------------------

void Print(const CVector &v)
{
    printf("\n\n\tv_size=%u v_error=%d",v.GetSize(),v.GetError());

    for(unsigned int i=0;i<v.GetSize();i++)
        printf("\n\tv[%u]=(%lg,%lg)",i,v.Get(i).real(),v.Get(i).imag());
}//void Print(const CVector &v)
