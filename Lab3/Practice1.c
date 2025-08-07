//Linklist

#include <stdio.h>
#include <stdlib.h>

struct node{
    int element;
    struct node *link;
};

int main(){
    struct node *head,*current;
    current = (struct node*)malloc(sizeof(struct node));

    int input;
    printf("Enter Value: ");
    scanf("%d",&input);

    current->element=input;
    current->link=NULL;
    head=current;

    printf("Your Value = %d, and Address = %p\n",head->element,(void*)head);

    current->link=malloc(sizeof(struct node));
    current->link->element=40;
    current->link->link=NULL;

    printf("Your Value = %d, and Address = %p\n",current->link->element,(void*)current->link);

    return 0;
}