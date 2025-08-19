#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
};

struct node *addFirst(struct node *head, int data){
    struct node *temp=head, *current;
    
    current=(struct node*)malloc(sizeof(struct node));
    current->data=data;
    current->next=temp;
    current->prev=NULL;
    
    if(head!=NULL){
        head->prev=current;
    }

    return current;
}

struct node *addLast(struct node *head, int data){
    struct node *temp=head, *current;
    if(temp==NULL){
        temp=addFirst(temp, data);
        return temp;
    }
    
    current=(struct node*)malloc(sizeof(struct node));
    current->data=data;
    current->next=NULL;
    current->prev=NULL;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=current;
    current->prev=temp;

    return head;
}

struct node *addPos(struct node *head, int data, int pos){
    struct node *temp=head, *current;

    if(pos==1){
        temp=addFirst(temp, data);
        return temp;
    }
    
    current=(struct node*)malloc(sizeof(struct node));
    current->data=data;
    current->next=NULL;
    current->prev=NULL;

    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }

    current->next=temp->next;
    current->prev=temp;
    temp->next->prev=current;
    temp->next=current;

    return head;
}

struct node *delFirst(struct node *head){
    struct node *temp=head;
    if(temp==NULL) return NULL;

    if(temp->next==NULL){
        free(temp);
        return NULL;
    }

    struct node *ptr=temp;
    temp=temp->next;
    temp->prev=NULL;

    free(ptr);

    return temp;
}

struct node *delLast(struct node *head){
    struct node *temp=head;
    if(temp==NULL) return NULL;

    if(temp->next==NULL){
        free(temp);
        return NULL;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }

    struct node *ptr=temp;
    temp=temp->prev;
    temp->next=NULL;

    free(ptr);
    return head;
}

struct node *delPos(struct node *head, int pos){
    struct node *temp=head;
    if(temp==NULL) return NULL;

    if(temp->next==NULL){
        free(temp);
        return NULL;
    }

    if(pos==1){
        temp=delFirst(temp);
        return temp;
    }

    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }

    struct node *ptr=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;

    free(ptr);
    return head;
}

void forwardTraverser(struct node *head){
    struct node *temp=head;
    if(temp==NULL) return;

    while(temp!=NULL){
        printf("Element: %d\n",temp->data);
        temp=temp->next;
    }printf("\n");
}

void reverseTraverser(struct node *head){
    struct node *temp=head;
    if(temp==NULL) return;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    while(temp!=NULL){
        printf("Element: %d\n",temp->data);
        temp=temp->prev;
    }printf("\n");
}

int main(){
    struct node *head=NULL;
    while(1){
        printf("Press 1 to Add First Element\n");
        printf("Press 2 to Add Last Element\n");
        printf("Press 3 to Add Element at Any Position\n");
        printf("Press 4 to Delete First Elements\n");
        printf("Press 5 to Delete Last Elements\n");
        printf("Press 6 to Delete Elements at Any Position\n");
        printf("Press 7 to Print Elements in Forward Direction\n");
        printf("Press 8 to Print Elements in Reverse Direction\n");
        printf("Press any Other Key to Exit\n");

        int choice;
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);

        if(choice==1){
            int data;
            printf("Input Data: ");
            scanf("%d",&data);
            head=addFirst(head,data);
        }
        else if(choice==2){
            int data;
            printf("Input Data: ");
            scanf("%d",&data);
            head=addLast(head,data);
        }
        else if(choice==3){
            int data;
            printf("Input Data: ");
            scanf("%d",&data);
            int pos;
            printf("Enter Position: ");
            scanf("%d",&pos);
            head=addPos(head,data,pos);
        }
        else if(choice==4){
            head=delFirst(head);
        }
        else if(choice==5){
            head=delLast(head);
        }
        else if(choice==6){
            int pos;
            printf("Enter Position: ");
            scanf("%d",&pos);
            head=delPos(head,pos);
        }
        else if(choice==7){
            forwardTraverser(head);
        }
        else if(choice==8){
            reverseTraverser(head);
        }
        else{
            break;
        }
    }printf("\nThank You\n");

    return 0;
}