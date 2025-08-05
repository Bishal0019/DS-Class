//Adding Two Sparse Matrices

#include <stdio.h>

const int max=100;

int matrixSparcer(int mat1[3][max]){
    printf("Enter Matrix:\n");
    int r,c,k=0;
    printf("Enter Rows and Columns: ");
    scanf("%d %d",&r,&c);
    int arr1[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("Enter Elemnt for Row %d, Column %d: ",i+1,j+1);
            scanf("%d",&arr1[i][j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr1[i][j]!=0){
                mat1[0][k]=i;
                mat1[1][k]=j;
                mat1[2][k]=arr1[i][j];
                k++;
            }
        }
    }
    return k;
}

int main(){
    int mat1[3][max],mat2[3][max];
    int size1=matrixSparcer(mat1);
    int size2=matrixSparcer(mat2);

    for (int i=0;i<size1-1;i++) {
        for (int j=0;j<size1-i-1;j++) {
            if(mat1[0][j]>mat1[0][j + 1] || (mat1[0][j]==mat1[0][j + 1] && mat1[1][j]>mat1[1][j + 1])){
            
                int temp=mat1[0][j];
                mat1[0][j]=mat1[0][j + 1];
                mat1[0][j + 1]=temp;

                temp=mat1[1][j];
                mat1[1][j]=mat1[1][j + 1];
                mat1[1][j + 1]=temp;

                temp=mat1[2][j];
                mat1[2][j]=mat1[2][j + 1];
                mat1[2][j + 1]=temp;
            }
        }
    }

    for (int i=0;i<size2-1;i++) {
        for (int j=0;j<size2-i-1;j++) {
            if(mat2[0][j]>mat2[0][j + 1] || (mat2[0][j]==mat2[0][j + 1] && mat2[1][j]>mat2[1][j + 1])){
            
                int temp=mat2[0][j];
                mat2[0][j]=mat2[0][j + 1];
                mat2[0][j + 1]=temp;

                temp=mat2[1][j];
                mat2[1][j]=mat2[1][j + 1];
                mat2[1][j + 1]=temp;

                temp=mat2[2][j];
                mat2[2][j]=mat2[2][j + 1];
                mat2[2][j + 1]=temp;
            }
        }
    }

    int i=0,j=0,k=0;
    int res[3][size1+size2];

    while(i<size1 && j<size2){
        if(mat1[0][i]<mat2[0][j] || (mat1[0][i]==mat2[0][j] && mat1[1][i]<mat2[1][j])){
            res[0][k]=mat1[0][i];
            res[1][k]=mat1[1][i];
            res[2][k]=mat1[2][i];
            i++;
        }else if(mat2[0][j]<mat1[0][i] || (mat2[0][j]==mat1[0][i] && mat2[1][j]<mat1[1][i])){
            res[0][k]=mat2[0][j];
            res[1][k]=mat2[1][j];
            res[2][k]=mat2[2][j];
            j++;
        }else if(mat1[0][i]==mat2[0][j] && mat1[1][i]==mat2[1][j]){
            res[0][k]=mat1[0][i];
            res[1][k]=mat1[1][i];
            res[2][k]=mat1[2][i]+mat2[2][j];
            i++;
            j++;
        }
        k++;
    }

    while(i<size1){
        res[0][k]=mat1[0][i];
        res[1][k]=mat1[1][i];
        res[2][k]=mat1[2][i];
        i++,k++;
    }

    while(j<size2){
        res[0][k]=mat2[0][j];
        res[1][k]=mat2[1][j];
        res[2][k]=mat2[2][j];
        j++,k++;
    }

    printf("\nResult:\n");
    for(int index=0;index<k;index++){
        printf("Element %d: Row: %d, Col: %d, Value: %d\n",index+1,res[0][index],res[1][index],res[2][index]);
    }

    return 0;
}