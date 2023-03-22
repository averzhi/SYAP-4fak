#include <stdio.h>
#include "..\..\Lib\cvectordft.h"

#define SIZE    17
#define T       4

const double eps=1.e-12;
const double rad2grad=180./M_PI;

int main()
{
    printf("\tProgram started\n\n");

    FILE *file;
    const char *fileName="out.txt";

    file=fopen(fileName,"wt");
    if(file == nullptr) return -1;

    CVectorDFT v(SIZE),vs,vr;

    //Формирование отсчетов сигнала
    for(unsigned int i=0;i<T;i++) v[i]=1.;

    Print(v);
    fPrint(file,v);

    v.DFT(vs);

    printf("\n\n\tv_size=%u v_error=%d",vs.GetSize(),vs.GetError());
    fprintf(file,"\n\n\tv_size=%u v_error=%d",vs.GetSize(),vs.GetError());
    for(unsigned int i=0;i<vs.GetSize();i++)
    {
        double a,fi;
        a=sqrt(vs[i].real()*vs[i].real()+vs[i].imag()*vs[i].imag());
        if(a > eps) fi=atan2(vs[i].imag(),vs[i].real());
        else fi=0.;
        printf("\n\tindex=%u a=%lf fi=%lf",i,a,fi*rad2grad);
        fprintf(file,"\n\tindex=%u a=%lf fi=%lf",i,a,fi*rad2grad);
    }//for(unsigned int i=0;i<vs.GetSize();i++)

    fclose(file);

    printf("\n\n\tPress key ENTER\n");
    getchar();
    return 0;
}//int main()

