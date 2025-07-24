#include <stdio.h>
#include <string.h>

struct books{
    char name[30];
    float price;
    int pages;
};

int main(){
    struct books b1;
    struct books b2;
    struct books b3;
    
    struct books *ptr_arr[3]={&b1,&b2,&b3};

    for(int i=0;i<3;i++){
        char bookname[30];
        int bookpages;
        float bookprice;

        printf("Enter Details Book %d\n",i+1);
        printf("Enter Name, Followed by Pages, Followed by Price: ");
        scanf("%s %d %f",bookname,&bookpages,&bookprice);

        strcpy(ptr_arr[i]->name,bookname);
        ptr_arr[i]->pages = bookpages;
        ptr_arr[i]->price = bookprice;

        printf("Input Seccessfull, Enter Next one\n\n");
    }
    printf("Results are: \n\n");

    for(int i=0;i<3;i++){
        printf("Values of Book %d Are: \n",i+1);
        printf("Name: %s\nPrice: %f\nPages: %d\n\n",ptr_arr[i]->name,ptr_arr[i]->price,ptr_arr[i]->pages);
    }

    // strcpy(ptr_arr[0]->name,"conding practices");
    // ptr_arr[0]->pages = 32;
    // ptr_arr[0]->price = 90.45;

    // strcpy(ptr_arr[1]->name,"c++ tutorial");
    // ptr_arr[1]->pages = 120;
    // ptr_arr[1]->price = 900.6;

    // strcpy(ptr_arr[2]->name,"Java tutorial");
    // ptr_arr[2]->pages = 150;
    // ptr_arr[2]->price = 85.00;

    // printf("Results are:\n");
    // printf("Name: %s\nPrice: %f\nPages: %d\n\n",ptr_arr[0]->name,ptr_arr[0]->price,ptr_arr[0]->pages);
    // printf("Name: %s\nPrice: %f\nPages: %d\n\n",ptr_arr[1]->name,ptr_arr[1]->price,ptr_arr[1]->pages);
    // printf("Name: %s\nPrice: %f\nPages: %d\n\n",ptr_arr[2]->name,ptr_arr[2]->price,ptr_arr[2]->pages);

    return 0;
}