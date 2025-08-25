#include <stdio.h>
#include <stdlib.h>

struct node{
    int exp,coeff;
    struct node *next;
};

struct node *inputPoly(struct node *head){
    struct node *temp=head;
    int coeff,exp,n;
    printf("Enter Number of Non-Zero Values You Want To Enter: ");
    scanf("%d",&n);

    printf("Enter All the values in Descending Order\n");
    
    for(int i=0;i<n;i++){
        struct node *current;
        current=(struct node *)malloc(sizeof(struct node));

        printf("Enter Coeffecient followed by Exponents: ");
        scanf("%d %d",&coeff,&exp);

        current->coeff=coeff;
        current->exp=exp;
        current->next=NULL;

        if(temp==NULL){
            temp=current;
        }

        temp->next=current;
    }

    return head;
}

struct node *addPoly(struct node *head1, struct node *head2, struct node *head3){
    struct node *temp1=head1;
    struct node *temp2=head2;
    struct node *current = (struct node *)malloc(sizeof(struct node));
    struct node *temp3=head3;

    while(temp1->next!=NULL && temp2->next!=NULL){
        if(temp1->exp==temp2->exp){
            current->exp=temp1->exp;
            current->coeff=temp1->coeff+temp2->coeff;
            current->next=NULL;
            if(temp3==NULL){
                temp3=current;
                head3=temp3;
            }else{
                temp3->next=current;
            }
            temp1=temp1->next;
            temp2=temp2->next;
            temp3=temp3->next;
        }else if(temp1->exp>temp2->exp){
            current->exp=temp1->exp;
            current->coeff=temp1->coeff;
            current->next=NULL;
            if(temp3==NULL){
                temp3=current;
                head3=temp3;
            }else{
                temp3->next=current;
            }
            temp1=temp1->next;
            temp3=temp3->next;
        }else{
            current->exp=temp2->exp;
            current->coeff=temp2->coeff;
            current->next=NULL;
            if(temp3==NULL){
                temp3=current;
                head3=temp3;
            }else{
                temp3->next=current;
            }
            temp2=temp2->next;
            temp3=temp3->next;
        }
    }
    while(temp1->next!=NULL){
        current->coeff=temp1->coeff;
        current->exp=temp1->exp;
        current->next=NULL;
        if(temp3==NULL){
            temp3=current;
            head3=temp3;
        }else{
            temp3->next=current;
        }
        temp1=temp1->next;
        temp3=temp3->next;
    }
    while(temp2->next!=NULL){
        current->coeff=temp2->coeff;
        current->exp=temp2->exp;
        current->next=NULL;
        if(temp3==NULL){
            temp3=current;
            head3=temp3;
        }else{
            temp3->next=current;
        }
        temp2=temp2->next;
        temp3=temp3->next;
    }

    return head3;
}

void forwardTraverser(struct node *head){
    struct node *temp=head;
    if(temp==NULL) return;

    while(temp!=NULL){
        printf("EXP: %d, Coeff: %d\n",temp->exp,temp->coeff);
        temp=temp->next;
    }printf("\n");
}

int main(){
    struct node *head1=NULL,*head2=NULL,*head3=NULL;

    printf("Enter 1st Poly: \n");
    head1=inputPoly(head1);

    printf("Enter 2nd Poly: \n");
    head2=inputPoly(head2);

    head3=addPoly(head1,head2,head3);

    forwardTraverser(head3);

    return 0;
}