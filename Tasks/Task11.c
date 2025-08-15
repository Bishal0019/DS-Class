//Check wheather the given lisked list is either NULL-terminated or ends in a cycle (cyclic)

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void checkCyclic(struct node *head){
    struct node *prev=head;
    struct node *temp=head;

    while(temp!=NULL && temp->next!=NULL){
        prev=prev->next;
        temp=temp->next->next;

        if(prev==temp){
            printf("Cyclic LinkedList\n");
            return;
        }
    }
    printf("NULL-Terminated LinkedList\n");
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
    current5->next=current2;

    head=current1;

    checkCyclic(head);

    return 0;
}