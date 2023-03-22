#include <stdio.h>
#include "..\..\Lib\cvectordft.h"

#define SIZE    17
#define T       4


int main()
{
    printf("\tProgram started\n\n");

    FILE *file;
    const char *fileName="out.txt";

    file=fopen(fileName,"wt");
    if(file == nullptr) return -1;

    CVectorDFT v(SIZE),vs,vr;

    for(unsigned int i=0;i<T;i++) v[i]=1.;

    Print(v);
    fPrint(file,v);

    v.DFT(vs);

    printf("\n");
    fprintf(file,"\n");
    for(unsigned int n=0;n<SIZE;n++)
    {
        vs.Restore(vr,n);
        printf("\n\tn=%u p_del=%lg",n,(v-vr).norm2());
        fprintf(file,"\n\tn=%u p_del=%lg",n,(v-vr).norm2());
    }//for(unsigned int n=0;n<SIZE;n++)


    fclose(file);

    printf("\n\n\tPress key ENTER\n");
    getchar();
    return 0;
}//int main()
