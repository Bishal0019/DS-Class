#include <stdio.h>

int maxProduct(int arr[],int n){
    int maxNum=arr[0];
    for(int i=0;i<n;i++){
        int prev=1;
        for(int j=i;j<n;j++){
            //[2,3,-2,4]
            if(arr[j]*prev>maxNum){
                maxNum=arr[j]*prev;
            }
            prev*=arr[j];
        }
    }
    return maxNum;
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

    printf("Max Product is: %d\n",maxProduct(arr,n));

    return 0;
}