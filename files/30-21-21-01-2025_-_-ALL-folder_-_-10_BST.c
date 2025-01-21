#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int data);
void search(Node *root, int key);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);
Node *findMin(Node *root);
Node *deleteNode(Node *root, int key);

int main(){
    Node *root = NULL;
    int choice, data;
    while (1)
    {
        printf("\n1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6. Delete\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter the data to search: ");
            scanf("%d", &data);
            search(root, data);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            printf("Enter the data to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    
    return 0;
}


Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        return root;
    }
    return root;
}

void search(Node *root, int data)
{
    if (root == NULL)
    {
        printf("Error: element not found!\n");
        return;
    }
    else if (data < root->data)
    {
        search(root->left, data);
    }
    else if (data > root->data)
    {
        search(root->right, data);
    }
    else
    {
        printf("%d is founded\n",root->data);
        return;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d\t", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        inorder(root->right);
        printf("%d\t", root->data);
    }
}

Node *findMin(Node *node)
{
    Node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        printf("Error :element not found!\n");
        return root;
    }
    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
