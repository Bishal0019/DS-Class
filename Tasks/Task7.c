//Polynomial Addition Using Structure & Array

#include <stdio.h>

const int max=100;

struct Terms{
    int expo;
    int coef;
};

int addition(struct Terms poly1[],int n1,struct Terms poly2[],int n2,struct Terms res[]){
    int k=0,i=0,j=0;
    while(i<n1 && j<n2){
        if(poly1[i].expo<poly2[j].expo){
            res[k]=poly1[i];
            k++,i++;
        }else if(poly2[j].expo<poly1[i].expo){
            res[k]=poly2[j];
            k++,j++;
        }else if(poly1[i].expo==poly2[j].expo){
            res[k].expo=poly1[i].expo;
            res[k].coef=poly1[i].coef+poly2[j].coef;
            i++,j++,k++;
        }
    }
    while(i<n1){
        res[k]=poly1[i];
        i++,k++;
    }
    while(j<n2){
        res[k]=poly2[j];
        j++,k++;
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
    
    int size=addition(p1,n1,p2,n2,res);

    printf("\nResult:\n");
    for(int i=0;i<size;i++){
        printf("Term %d: Exponential = %d, Coefficient = %d\n",i+1,res[i].expo,res[i].coef);
    }

    return 0;
}