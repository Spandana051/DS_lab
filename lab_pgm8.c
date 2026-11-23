
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create() {
    struct node *head = NULL, *temp, *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    return head;
}

void display(struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sort(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

struct node *reverse(struct node *head) {
    struct node *prev = NULL, *current = head, *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct node *concat(struct node *head1, struct node *head2) {
    struct node *temp;

    if (head1 == NULL)
        return head2;

    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct node *head1, *head2;

    printf("Create first linked list:\n");
    head1 = create();

    printf("Create second linked list:\n");
    head2 = create();

    printf("\nFirst list: ");
    display(head1);

    sort(head1);
    printf("Sorted list: ");
    display(head1);

    head1 = reverse(head1);
    printf("Reversed list: ");
    display(head1);

    head1 = concat(head1, head2);
    printf("Concatenated list: ");
    display(head1);

    return 0;
}
