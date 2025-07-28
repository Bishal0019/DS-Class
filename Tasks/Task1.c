#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter Number of Inputs: ");
    scanf("%d",&n);

    int *arr = (int*)calloc(n,sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d: ",i+1);
        scanf("%d",arr+i);
    }

    printf("Values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d = %d\n",i+1,arr[i]);
    }
    free(arr);
    printf("Memory freed successfully.\n");

    return 0;
}