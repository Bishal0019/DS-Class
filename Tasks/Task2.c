#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int roll;
    char name[60];
    float cgpa;
};

int main(){
    int size = 0;
    struct student *arr = (struct student*)calloc(size,sizeof(struct student));
    while (1){
        printf("Press 1 to add new Student\n");
        printf("Press 2 to edit student details\n");
        printf("Press 3 to delete student\n");
        printf("Press 4 to display all students\n");
        printf("Press any other key to exit\n");
        int choice;
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        printf("\n");
        if(choice == 1){
            size++;
            arr = realloc(arr, size*(sizeof(struct student)));
            printf("Enter Roll Number: ");
            scanf("%d",&arr[size-1].roll);
            printf("Enter Name: ");
            scanf("%s",arr[size-1].name);
            printf("Enter CGPA: ");
            scanf("%f",&arr[size-1].cgpa);
            printf("Input Complete....\n\n");
        }
        else if(choice == 2){
            int troll,flag=0;
            printf("Enter Roll Number Whose Details You Want to Edit: ");
            scanf("%d",&troll);
            for(int i=0;i<size;i++){
                if(arr[i].roll==troll){
                    printf("Student Found");
                    flag=1;
                    printf("Enter New Name: ");
                    scanf("%s",arr[i].name);
                    printf("Enter New CGPA: ");
                    scanf(" %f",&arr[i].cgpa);
                }
            }if(flag==0){
                printf("User Not Found!");
            }
        }
        else if(choice == 3){
            int troll,flag=0;
            printf("Enter Roll Whose Details You Want To Delete: ");
            scanf("%d",&troll);
            for(int i=0;i<size;i++){
                if(arr[i].roll==troll){
                    printf("Student Found");
                    flag=1;
                    if(size>1){
                        arr[i]=arr[i+1];
                        size--;
                    }else{
                        size--;
                    }
                }
            }if(flag==0){
                printf("Student Not Found!");
            }
        }
        else if(choice == 4){
            for(int i=0;i<size;i++){
                printf("\nDetails For Student %d\n",i+1);
                printf("Roll: %d, Name: %s, CGPA: %f\n",arr[i].roll,arr[i].name,arr[i].cgpa);
            }
        }
        else{
            break;
        }
    }printf("Thank You");

    return 0;
}