#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void nodeTraverser(struct node* head){
    while(head!=NULL){
        printf("Element: %d\n",head->data);
        head=head->next;
    }
}

struct node* addFirst(struct node* head,int data){
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;

    return ptr;
}

void addLast(struct node* head,int data){
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;

    while(head->next!=NULL){
        head=head->next;
    }

    head->next=ptr;
}

void addIndex(struct node* head,int data,int index){
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;

    int i=0;
    while(i<index-1){
        head=head->next;
        i++;
    }

    ptr->next=head->next;
    head->next=ptr;
}

struct node* delFirst(struct node* head){
    if(head==NULL) printf("Empty List\n");
    struct node* temp;
    temp=head;
    head=head->next;

    free(temp);
    return head;
}

struct node* delLast(struct node* head){
    if(head==NULL){
        printf("Empty List\n");
        return NULL;
    }
    struct node* temp=head;
    if(head->next==NULL){
        free(head);
        return NULL;
    }

    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    free(temp->next);
    temp->next=NULL;
    return head;
}

struct node* delIndex(struct node* head,int index){
    if(head==NULL){
        printf("Empty List\n");
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    
    int i=0;
    struct node* current = head;
    while(i<index-1){
        current=current->next;
        i++;
    }

    struct node* temp=current->next;
    current->next=current->next->next;
    free(temp);

    return head;

    //20->10->35->40->NULL
}

int main(){
    struct node* head=NULL;
    struct node* current;

    current=(struct node*)malloc(sizeof(struct node));
    current->data=10;
    current->next=NULL;
    head=current;

    head=addFirst(head,20);
    addLast(head,40);
    addIndex(head,35,2);

    head=delIndex(head,2);

    nodeTraverser(head);

    return 0;
}