//Find the merging point of two different linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *mergingPoint(struct node *head1, struct node *head2){
    if(head1==NULL || head2==NULL) return NULL;

    struct node *ptr1=head1, *ptr2=head2;
    int len1=0,len2=0,len;

    while(ptr1!=NULL){
        ptr1=ptr1->next;
        len1++;
    }ptr1=head1;
    while(ptr2!=NULL){
        ptr2=ptr2->next;
        len2++;
    }ptr2=head2;
    if(len1>len2){
        len=len1-len2;
        for(int i=0;i<len;i++){
            ptr1=ptr1->next;
        }
    }else{
        len=len2-len1;
        for(int i=0;i<len;i++){
            ptr2=ptr2->next;
        }
    }

    while (ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2) return ptr1;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return NULL;
}

int main(){
    struct node *head1, *head2, *current1, *current2, *current3, *current4, *current5, *current6, *current7;
    
    current1=(struct node*)malloc(sizeof(struct node));
    current2=(struct node*)malloc(sizeof(struct node));
    current3=(struct node*)malloc(sizeof(struct node));
    current4=(struct node*)malloc(sizeof(struct node));
    current5=(struct node*)malloc(sizeof(struct node));
    current6=(struct node*)malloc(sizeof(struct node));
    current7=(struct node*)malloc(sizeof(struct node));

    current1->data=10;
    current1->next=current2;

    current2->data=20;
    current2->next=current3;

    current3->data=30;
    current3->next=current7;

    current4->data=40;
    current4->next=current5;

    current5->data=50;
    current5->next=current6;

    current6->data=60;
    current6->next=current7;

    current7->data=100;
    current7->next=NULL;

    head1=current1, head2=current4;

    struct node *merge=mergingPoint(head1,head2);

    if(merge==NULL){
        printf("No Merging Point\n");
    }else{
        printf("Merging Point is: %p\n",merge);
    }

    return 0;
}