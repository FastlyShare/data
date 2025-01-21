#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int priority;
    int data;
    struct Node *next;
};
struct Node *front = NULL;

void insert(int data, int priority)
{
    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
    curr->data = data;
    curr->next = NULL;
    curr->priority = priority;

    if (front == NULL)
    {
        front = curr;
    }
    else if (curr->priority > front->priority)
    {
        curr->next = front;
        front = curr;
    }
    else
    {
        struct Node *temp = front;
        while (temp->next != NULL && temp->next->priority > curr->priority)
        {
            temp = temp->next;
        }
        curr->next = temp->next;
        temp->next = curr;
    }
}

void delete()
{
    if (front == NULL)
    {
        printf("Error: queue underflow!\n");
        return;
    }
    struct Node *temp = front;
    front = front->next;
    free(temp);
}

void display()
{
    if (front == NULL)
    {
        printf("Error: queue is empty!\n");
        return;
    }
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    int data, priority;
    while (1)
    {
        printf("1.insert\n2.display\n3.delete\n4.exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data and priority :");
            scanf("%d%d", &data, &priority);
            insert(data, priority);
            break;
        case 2:
            display();
            break;
        case 3:
            delete ();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}