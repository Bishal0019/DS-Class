#include <stdio.h>

struct N
{
    int i;
    float c;
};

int main(){
    int a=10;
    float b=1.922;
    struct N N1;

    N1.i = 110;
    N1.c = 120.11;

    void *arr[3];
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &N1;

    struct N *ptr = (struct N*)arr[2];

    printf("Values Are:\n");
    printf("INT = %d\n",*(int*)arr[0]);
    printf("FLOAT = %f\n",*(float*)arr[1]);
    printf("STRUCTURE = int: %d, float: %f",ptr->i,ptr->c);

    return 0;
}