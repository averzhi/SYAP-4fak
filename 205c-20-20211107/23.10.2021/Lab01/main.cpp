#include <stdio.h>
#include "..\..\Lib\vector3d.h"

int main()
{
    printf("\tProgram started\n\n");

    FILE *file;
    const char *fileName="out.txt";

    file=fopen(fileName,"wt");
    if(file == nullptr) return -1;

    Vector3D a(1,2,3),b(-2,3,-6),c(3,-7,5),d(-3,-4,-5);
    double v;

    v=fabs(scalar(b-a,(c-a)*(d-a)))/6.;
    printf("\n\tv=%lg",v);
    fprintf(file,"\n\tv=%lg",v);

    fclose(file);

    printf("\n\n\tPress key ENTER\n");
    getchar();
    return 0;
}//int main()
