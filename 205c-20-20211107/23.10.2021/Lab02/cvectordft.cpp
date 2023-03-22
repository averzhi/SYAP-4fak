#include "cvectordft.h"

void CVectorDFT::DFT(CVectorDFT &v)const
{
    v.SetSize();
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
    v.SetSize();
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

void CVectorDFT::Restore(CVectorDFT &v,unsigned int n)const
{
    v.SetSize();
    v.SetSize(this->GetSize());

    if(this->GetError() < 0) return;

    complex w,w_m;
    double delFi;

    for(unsigned int i1=0;i1<n;i1++)
    {
        //цикл по частоте
        if(i1 > (v.GetSize()+1)/2) break;

        if(i1 == 0)
        {
            for(unsigned int i2=0;i2<v.GetSize();i2++) v[i2]+=this->Get(0);
        }//if(i1 == 0)
        else
        {
            delFi=2.*M_PI*i1/v.GetSize();
            w_m=complex(cos(delFi),sin(delFi));
            w=1.;
            for(unsigned int i2=0;i2<v.GetSize();i2++)
            {
                //цикл по времени
                v[i2]+=this->Get(i1)*w;
                if(i1 < v.GetSize()/2)
                    v[i2]+=this->Get(this->GetSize()-i1)*conj(w);

                w*=w_m;
            }//for(unsigned int i2=0;i2<v.GetSize();i2++)
        }//else if(i1 == 0)
    }//for(unsigned int i1=0;i1<n;i1++)

}//void CVectorDFT::Restore(CVectorDFT &v,unsigned int n)const
