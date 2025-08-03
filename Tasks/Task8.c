//Polynomial Multiplication Using Structure & Array

#include <stdio.h>

const int max=100;

struct Terms{
    int expo;
    int coef;
};

int multiplication(struct Terms p1[],int n1,struct Terms p2[],int n2,struct Terms res[]){
    int k=0;

    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            res[k].expo=p1[i].expo+p2[j].expo;
            res[k].coef=p1[i].coef*p2[j].coef;
            k++;
        }
    }
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(res[i].expo==res[j].expo){
                res[i].coef+=res[j].coef;
                for(int x=j;x<k-1;x++){
                    res[x]=res[x+1];
                }
                k--,j--;
            }
        }
    }
    return k;
}

int main(){
    struct Terms p1[max],p2[max],res[max];

    printf("Input Polynomial 1:\n");
    int n1;
    printf("Enter Number of Terms: ");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        printf("Enter Exponential & Coefficient for term %d (in ascending order of exponential): ",i+1);
        scanf("%d %d",&p1[i].expo,&p1[i].coef);
    }

    printf("Input Polynomial 2:\n");
    int n2;
    printf("Enter Number of Terms: ");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        printf("Enter Exponential & Coefficient for term %d (in ascending order of exponential): ",i+1);
        scanf("%d %d",&p2[i].expo,&p2[i].coef);
    }

    int size = multiplication(p1,n1,p2,n2,res);

    printf("\nResult:\n");
    for(int i=0;i<size;i++){
        printf("Term %d: Exponential = %d, Coefficient = %d\n",i+1,res[i].expo,res[i].coef);
    }

    return 0;
}