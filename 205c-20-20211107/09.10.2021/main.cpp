#include <stdio.h>
#include "cvectordft.h"

#define SIZE    16
#define T       4

const double eps=1.e-12;
const double rad2grad=180./M_PI;

int main()
{
    printf("\tProgram started\n\n");
/*
    CVectorDFT v1(5),v2(2),v3,v4,*pV;

    v1.Set(0,complex(10,-11));
    v1.Set(1,11);
    v1[2]=complex(222,-333);//v1.Set(2,complex(22,-33));
    v1.Set(3,33);
    v1.Set(4,44);

    Print(v1);

    v2=-v1;
    Print(v2);

    v3=v1-v2;
    Print(v3);

    //v4=v3*0.5;
    //v4=0.5*v3;
    //v4=v3/2.;
    //Print(v4);

    v3+=v1;
    Print(v3);

    v3-=v1;
    Print(v3);

    v3/=2.;
    Print(v3);

    pV=new CVectorDFT(8);
    if(pV == nullptr) return -1;

    Print(*pV);

    delete pV;
*/
    CVectorDFT v(SIZE),vs,vr;

    for(unsigned int i=0;i<T;i++) v[i]=1.;

    Print(v);

    v.DFT(vs);
    //Print(vs);
    printf("\n\n\tv_size=%u v_error=%d",vs.GetSize(),vs.GetError());
    for(unsigned int i=0;i<vs.GetSize();i++)
    {
        double a,fi;
        a=sqrt(vs[i].real()*vs[i].real()+vs[i].imag()*vs[i].imag());
        if(a > eps) fi=atan2(vs[i].imag(),vs[i].real());
        else fi=0.;
        printf("\n\tindex=%u a=%lf fi=%lf",i,a,fi*rad2grad);
    }//for(unsigned int i=0;i<vs.GetSize();i++)




    vs.IDFT(vr);
    Print(vr);


    printf("\n\n\tPress key ENTER\n");
    getchar();
    return 0;
}//int main()
