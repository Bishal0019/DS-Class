#include <stdio.h>

void greater(int *a,int *b){
    if (*a>*b)
    {
        printf("Largest = %d",*a);
    }else{
        printf("Largest = %d",*b);
    }
}

int main(){
    int a,b;
    printf("Enter Two Numbers: ");
    scanf("%d %d",&a,&b);
    greater(&a,&b);

    return 0;
}