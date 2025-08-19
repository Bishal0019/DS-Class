//Find n'th node from the end of linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* nthNode(struct node *head,int pos){
    int size=0;
    struct node *temp=head, *temp2=head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    if(pos>size){
        printf("List Short\n");
        return NULL;
    }else{
        for(int i=0;i<(size-pos);i++){
            temp2=temp2->next;
        }
        return temp2;
    }
}

int main(){
    struct node *head, *current1, *current2, *current3, *current4, *current5;
    
    current1=(struct node*)malloc(sizeof(struct node));
    current2=(struct node*)malloc(sizeof(struct node));
    current3=(struct node*)malloc(sizeof(struct node));
    current4=(struct node*)malloc(sizeof(struct node));
    current5=(struct node*)malloc(sizeof(struct node));
    
    current1->data=10;
    current1->next=current2;

    current2->data=20;
    current2->next=current3;

    current3->data=30;
    current3->next=current4;

    current4->data=40;
    current4->next=current5;

    current5->data=50;
    current5->next=NULL;

    head=current1;

    struct node *ptr=nthNode(head,2);
    printf("Element = %d, at Address = %p\n",ptr->data,ptr); 

    return 0;
}