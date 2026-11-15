#define Max 3
#include<stdio.h>
int queue[Max];
int front=-1;
int rear=-1;

void insert()
{
    int item;
    if(rear>=Max-1){
        printf("Queue Overflow \n");
    }
    else
    {
        printf("Enter the element to be inserted:");
        scanf("%d", &item);

        if(front==-1)
            front=0;
        rear++;
        queue[rear]=item;
        printf("The element %d is inserted Successfully\n", item);
    }


}

void deletion()
{
    if(front==-1|| front>rear)
        printf("Queue Underflow!!  \n");
    else
    {
        printf("The element %d is removed from Queue Successfully", queue[front]);
        front++;
    }

    if(front>rear){
        front=-1;
        rear=-1;
    }
}

void display()
{
    if(front==-1)
        printf("Queue has no elements \n");
    else
        for(int i=front;i<rear+1;i++)
    {
        printf("%d ",queue[i]);
    }
 printf("\n");
}


int main()
{
    int choice;
    while(1)
    {
        printf("\n-----OPERATIONS ON QUEUE-------\n");
        printf("1. Insertion    ");
        printf("2. Deletion     ");
        printf("3. Display     ");
        printf("4. Exit   \n");
        printf("Enter Your Choice");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Program Exitting.....");
            return 0;
        default:
            printf("Enter a valid choice!!\n");

        }
    }
}
