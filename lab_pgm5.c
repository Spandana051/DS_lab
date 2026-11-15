
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create()
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }
}

void deleteFirst()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("First element deleted\n");
}

void deleteSpecified()
{
    struct node *temp, *prev;
    int key;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    temp = head;

    if(head->data == key)
    {
        head = head->next;
        free(temp);
        printf("Element deleted\n");
        return;
    }

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Element not found\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);
        printf("Element deleted\n");
    }
}

void deleteLast()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Last element deleted\n");
        return;
    }

    temp = head;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Last element deleted\n");
}

void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int ch;

    create();

    while(1)
    {
        printf("\n1.Delete First");
        printf("\n2.Delete Specified Element");
        printf("\n3.Delete Last");
        printf("\n4.Display");
        printf("\n5.Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: deleteFirst();
                    break;

            case 2: deleteSpecified();
                    break;

            case 3: deleteLast();
                    break;

            case 4: display();
                    break;

            case 5: exit(0);

            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
