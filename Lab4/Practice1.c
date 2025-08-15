#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void listTraverser(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("Element: %d\n",temp->data);
        temp=temp->next;
    }
}

struct node* addFirst(struct node* head, int data){
    struct node* current;
    current=(struct node*)malloc(sizeof(struct node));
    current->data=data;
    current->next=head;
    head=current;

    return head;
}

struct node* addLast(struct node* head, int data){
    struct node* temp=head;
    struct node* current;
    current=(struct node*)malloc(sizeof(struct node));
    current->data=data;
    current->next=NULL;
    
    if(head==NULL){
        return current;
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=current;
        return head;
    }
}

struct node* addPos(struct node* head, int data, int pos){
    struct node* temp=head;
    struct node* current;
    current=(struct node*)malloc(sizeof(struct node));
    current->data=data;
    current->next=NULL;

    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    current->next=temp->next;
    temp->next=current;

    return head;
}

struct node* delFirst(struct node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    struct node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

struct node* delLast(struct node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    struct node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}

struct node* delPos(struct node* head, int pos){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    struct node* temp=head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    struct node* ptr = temp->next;
    temp->next=temp->next->next;
    free(ptr);

    return head;
}

struct node* insertList(struct node* head, struct node* head2, int pos){
    struct node* temp=head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    struct node* ptr=temp->next;
    temp->next=head2;
    while(head2->next!=NULL){
        head2=head2->next;
    }
    head2->next=ptr->next;

    return head;
}

struct node* delList(struct node* head,int startPos, int endPos){
    struct node* temp=head;
    struct node* firstPos;
    struct node* lastPos;

    int i=1;
    while(i<startPos-1){
        temp=temp->next;
        i++;
    }
    firstPos=temp->next;
    while(i<endPos){
        temp=temp->next;
        i++;
    }
    lastPos=temp->next;
    temp->next=lastPos->next;
    while(firstPos->next!=lastPos){
        struct node*ptr=firstPos;
        firstPos=firstPos->next;
        free(ptr);
    }

    return head;
}

int main(){
    struct node* head=NULL;

    while(1){
        printf("Press 1 to Add First Element\n");
        printf("Press 2 to Add Last Element\n");
        printf("Press 3 to Add Element at Any Position\n");
        printf("Press 4 to Delete First Elements\n");
        printf("Press 5 to Delete Last Elements\n");
        printf("Press 6 to Delete Elements at Any Position\n");
        printf("Press 7 to Add Another Linked List at Any Position\n");
        printf("Press 8 to Delete Node at Any Position\n");
        printf("Press 9 to Print Elements\n");
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
            struct node* head2=NULL;
            int inputs;
            printf("Enter Number of Inputs in Secondary Linked List: ");
            scanf("%d",&inputs);
            for(int i=0;i<inputs;i++){
                int data;
                printf("Enter Data: ");
                scanf("%d",&data);
                head2=addLast(head2,data);
            }
            int pos;
            printf("Enter Insertion Position: ");
            scanf("%d",&pos);
            head=insertList(head,head2,pos);
        }
        else if(choice==8){
            int startpos,endpos;
            printf("Enter Staring & Ending Position: ");
            scanf("%d %d",&startpos,&endpos);
            head=delList(head,startpos,endpos);
        }
        else if(choice==9){
            listTraverser(head);
        }
        else{
            break;
        }
    }printf("\nThank You\n");

    return 0;
}