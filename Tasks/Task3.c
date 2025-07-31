//Reverse an Array without using a new array
#include <stdio.h>

void RevArr(int arr[],int n){
    for(int i=0;i<n/2;i++){
        int temp = arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
}

int main(){
    int n;
    printf("Enter Array Length: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Input element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    RevArr(arr,n);
    printf("Reversed Array:\n");
    for(int i=0;i<n;i++){
        printf("%d, ",arr[i]);
    }

    return 0;
}