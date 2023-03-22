#include <stdio.h>
#include "cvector.h"

int main()
{
    printf("\tProgram started\n\n");

    CVector v1(5),v2(2);

    v1.Set(0,complex(10,-11));
    v1.Set(1,11);
    v1[2]=complex(222,-333);//v1.Set(2,complex(22,-33));
    v1.Set(3,33);
    v1.Set(4,44);

    Print(v1);
    Print(v2);

    v2=-v1;
    Print(v2);

    v2.SetSize(7);
    Print(v2);

    v2.SetSize(3);
    Print(v2);

    v2.SetSize();
    Print(v2);

    v2.SetSize(2);
    Print(v2);


    printf("\n\n\tPress key ENTER\n");
    getchar();
    return 0;
}//int main()
