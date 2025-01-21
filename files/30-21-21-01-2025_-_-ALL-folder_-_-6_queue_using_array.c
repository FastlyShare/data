#include <stdio.h>
#include <stdlib.h>

#define MAX 3
int arr[MAX];
int front = 0, rear = -1, count = 0;

void insert()
{
    if (count == MAX)
    {
        printf("Error: queue overflow!\n");
        return;
    }
    int item;
    printf("Enter the element to insert :");
    scanf("%d", &item);
    rear = (rear + 1) % MAX;
    arr[rear] = item;
    count++;
}

void delete()
{
    if (count == 0)
    {
        printf("Error: queue underflow!\n");
        return;
    }
    front = (front + 1) % MAX;
    count--;
}

void display()
{
    if (count == 0)
    {
        printf("Error: queue is empty!\n");
        return;
    }
    int index;
    for (int i = 0; i < count; i++)
    {
        index = (front + i) % MAX;
        printf("%d\t", arr[index]);
    }
    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("1.insert\n2.display\n3.delete\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            delete();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}