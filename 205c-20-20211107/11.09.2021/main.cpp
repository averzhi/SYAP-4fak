#include <stdio.h>
#include "vector3d.h"

int main()
{
    printf("\tProgram started\n\n");

    Vector3D v1,v2(2,3,4),v3(v2),v4=v2;

    printf("\n\n\tPress key ENTER\n");
    getchar();
    return 0;
}//int main()
