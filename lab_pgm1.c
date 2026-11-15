#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push();
void pop();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n---- STACK OPERATIONS ----\n");
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. \n");
        }
    }
    return 0;
}

void push() {
    int value;

    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter the value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d successfully pushed onto the stack.\n", value);
    }
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow! \n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}


void display() {

    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements :\n");
        for (int i = top; i >= 0; i--) {
            printf(" %d \n", stack[i]);
        }
        printf("-----\n");
    }
}
