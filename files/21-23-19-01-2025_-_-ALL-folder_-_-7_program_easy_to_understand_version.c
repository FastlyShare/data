#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *prev = NULL;

void create()
{
    int n, data;
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    printf("Enter the data for nodes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
        curr->data = data;
        curr->next = NULL;
        if (i == 0)
        {
            head = curr;
        }
        else
        {
            prev->next = curr;
        }
        prev = curr;
    }
}

void insert_front()
{
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
    curr->data = data;
    curr->next = head;
    head = curr;
}

void insert_end()
{
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
    curr->data = data;
    curr->next = NULL;

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = curr;
}

void delete_front()
{
    if (head == NULL)
    {
        printf("Error: void deletion!\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void delete_end()
{
    if (head == NULL)
    {
        printf("Error: void deletion!\n");
        return;
    }

    struct Node *curr = head;
    struct Node *prev = head;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    free(curr);
    prev->next = NULL;
}

void display()
{
    if (head == NULL)
    {
        printf("Error: list is empty!\n");
        return;
    }

    struct Node *curr = head;
    while (curr != NULL)
    {
        printf("%d\t", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("1.create\n2.display\n3.insert_front\n4.insert_end\n5.delete_front\n6.delete_end\n7.exit\nEnter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_front();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            delete_front();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}