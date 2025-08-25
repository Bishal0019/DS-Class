//Check wheather a given linked list is NULL-terminated or not. If there is a cyclefind the start node of the loop

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *checkCyclic(struct node *head){
    struct node *slow=head, *fast=head;
    int flag=0;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            flag=1;
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    if(flag==0) return NULL;
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

    struct node *loop=checkCyclic(head);
    if(loop==NULL){
        printf("NULL-Terminated\n");
    }
    else{
        printf("Cyclic, with starting node: %p\n",loop);
    }
}