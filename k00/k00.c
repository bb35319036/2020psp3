#include <stdio.h>
#define ARRAY_SIZE  7
int main (void)
{
int array[ARRAY_SIZE]
    ={1,5,3,8,2,4,6};
int pos,result;
int key = 3;

result=-1;

for(pos=0; pos < ARRAY_SIZE; pos++)
{
    if(key==array[pos])//array[pos]はposが示す場所の中身の値
{
    result = pos;
    break;//ループから抜ける
}
    else
    {

    }
}

printf("result=%d" ,result);

return 0;
}