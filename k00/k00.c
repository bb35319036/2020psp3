#include <stdio.h>
#define ARRAY_SIZE  7
int main (void)
{
    int a,b=0,c=0,d=0,e=0;

a= 2;

d=a+1;
e=d;
d=a;
a=e;
//b=a;
//c=a+1;

printf("%d,%d" ,a,d);

return 0;
}