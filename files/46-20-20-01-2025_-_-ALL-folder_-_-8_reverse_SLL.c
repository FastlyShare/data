#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *prev = NULL, *curr = NULL, *next = NULL;
    // exactly same as create() function in program 7
    int n, data;
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    printf("Enter the data for nodes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        curr = (struct Node *)malloc(sizeof(struct Node));//minor difference
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
    // end same

    printf("Reversing linked list :\n");
    prev = head;
    curr = prev->next;
    next = curr->next;

    head->next = NULL;

    while (next != NULL)
    {
        curr->next = prev;

        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    head = curr;

    //printing reversed linked list
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp= temp->next;
    }
    printf("\n");
    return 0;
}