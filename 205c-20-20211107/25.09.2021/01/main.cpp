#include <stdio.h>
#include "vector3d.h"

int main()
{
    printf("\tProgram started\n\n");

    /*
    Vector3D v1,v2(2,3,4),v3(v2),v4=v2;

    v1=-v2;
    v4=v1+v2;
    */
    Vector3D a(1,2,3),b(-11,12,-13),c(22,-23,24);
    double s1,s2,ab,ac,bc,p,d1,d2;

    ab=(a-b).norm();
    ac=(a-c).norm();
    bc=(b-c).norm();
    p=(ab+ac+bc)/2;
    s1=sqrt(p*(p-ab)*(p-ac)*(p-bc));

    /*
    s2=((b-a)*(c-a)).norm()/2;
    d1=scalar(b-a,(b-a)*(c-a));
    d2=scalar(c-a,(b-a)*(c-a));
    */
    b-=a;c-=a;
    d1=scalar(b,b*c);
    d2=scalar(c,b*c);
    s2=(b*c).norm()/2;

    printf("\n\ts1=%lg s2=%lg d1=%lg d2=%lg",s1,s2,d1,d2);

    printf("\n\n\tPress key ENTER\n");
    getchar();
    return 0;
}//int main()
