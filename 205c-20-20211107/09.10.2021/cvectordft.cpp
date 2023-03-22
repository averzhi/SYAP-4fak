#include "cvectordft.h"

void CVectorDFT::DFT(CVectorDFT &v)const
{
    v.SetSize(this->GetSize());
    //v.SetSize(this->size);

    if(v.GetError() < 0) return;
    complex c,w,w_del;
    double delFi;

    for(unsigned int i1=0;i1<v.GetSize();i1++)
    {
        //цикл по частоте
        delFi=-2.*M_PI*i1/v.GetSize();
        w_del=complex(cos(delFi),sin(delFi));
        w=1.;c=0.;
        for(unsigned int i2=0;i2<this->GetSize();i2++)
        {
            //цикл по времени
            c+=this->Get(i2)*w;

            w*=w_del;
        }//for(unsigned int i2=0;i2<this->size;i2++)

        v[i1]=c/double(this->GetSize());
    }//for(unsigned int i1=0;i1<v.GetSize();i1++)


}//void CVectorDFT::DFT(CVectorDFT &v)const

void CVectorDFT::IDFT(CVectorDFT &v)const
{
    v.SetSize(this->GetSize());
    //v.SetSize(this->size);

    if(v.GetError() < 0) return;
    complex c,w,w_del;
    double delFi;

    for(unsigned int i1=0;i1<v.GetSize();i1++)
    {
        //цикл по времени
        delFi=2.*M_PI*i1/v.GetSize();
        w_del=complex(cos(delFi),sin(delFi));
        w=1.;c=0.;
        for(unsigned int i2=0;i2<this->GetSize();i2++)
        {
            //цикл по частоте
            c+=this->Get(i2)*w;

            w*=w_del;
        }//for(unsigned int i2=0;i2<this->size;i2++)

        v[i1]=c;
    }//for(unsigned int i1=0;i1<v.GetSize();i1++)
}//void CVectorDFT::IDFT(CVectorDFT &v)const

void CVectorDFT::Restore(CVectorDFT &v)const
{

}//void CVectorDFT::Restore(CVectorDFT &v)const
