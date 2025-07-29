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
        printf("Press 5 to search a student\n");
        printf("Press any other key to exit\n");
        int choice;
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        printf("\n");

        //Inserting data
        if(choice == 1){
            size++;
            arr = realloc(arr, size*(sizeof(struct student)));
            printf("Enter Roll Number: ");
            scanf("%d",&arr[size-1].roll);
            printf("Enter Name: ");
            getchar();
            fgets(arr[size-1].name,60,stdin);
            arr[size-1].name[strcspn(arr[size-1].name,"\n")]=0;
            printf("Enter CGPA: ");
            scanf("%f",&arr[size-1].cgpa);
            printf("Input Complete....\n\n");
        }

        //Editing Student Data
        else if(choice == 2){
            int troll,flag=0;
            printf("Enter Roll Number Whose Details You Want to Edit: ");
            scanf("%d",&troll);
            for(int i=0;i<size;i++){
                if(arr[i].roll==troll){
                    printf("Student Found\n");
                    flag=1;
                    printf("Enter New Name: ");
                    getchar();
                    fgets(arr[size-1].name,60,stdin);
                    arr[size-1].name[strcspn(arr[size-1].name,"\n")]=0;
                    printf("Enter New CGPA: ");
                    scanf(" %f",&arr[i].cgpa);
                }
            }if(flag==0){
                printf("Student Not Found!\n");
            }
        }

        //Deleting Student Data
        else if(choice == 3){
            int troll,flag=0;
            printf("Enter Roll Whose Details You Want To Delete: ");
            scanf("%d",&troll);
            for(int i=0;i<size;i++){
                if(arr[i].roll==troll){
                    printf("Student Found\n");
                    flag=1;
                    if(size>1){
                        arr[i]=arr[i+1];
                        size--;
                    }else{
                        size--;
                    }
                    printf("Student Data Deleted!\n");
                }
            }if(flag==0){
                printf("Student Not Found!\n");
            }
        }

        //Displaying all data
        else if(choice == 4){
            for(int i=0;i<size;i++){
                printf("\nDetails For Student %d\n",i+1);
                printf("Roll: %d, Name: %s, CGPA: %f\n",arr[i].roll,arr[i].name,arr[i].cgpa);
            }printf("\n");
        }

        //Searching
        else if(choice == 5){
            int troll,flag=0;
            printf("Enter Roll Number You Want To Search: ");
            scanf("%d",&troll);
            for(int i=0;i<size;i++){
                if(arr[i].roll==troll){
                    flag =1;
                    printf("Student Found, Displaying Data....\n");
                    printf("Roll Number: %d, Name: %s, CGPA: %f\n",arr[i].roll,arr[i].name,arr[i].cgpa);
                }
            }
            if(flag==0){
                printf("Student Not Found!\n");
            }
        }

        //Exiting Loop
        else{
            break;
        }
        
    }printf("Thank You");

    return 0;
}