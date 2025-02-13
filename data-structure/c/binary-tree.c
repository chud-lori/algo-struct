#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(Node** root, int data) {
    // binary tree level order
    Node* newNode = createNode(data);
    if(*root == NULL) {
        *root = newNode;
        return;
    }

    // Level order traversal to find appropriate place for insertion
    Node* temp;
    Node* queue[100];
    // rear use to enqueued/add to queue
    // front use to dequeded/process data
    int front = -1, rear = -1;
    // increase rear by 1 and then use the added value (pre increment)
    // if using post increment, it will use current value (-1) and then add rear by 1, will be invalid array index
    queue[++rear] = *root;

    while (front != rear) {
        temp = queue[++front];

        // Insert new node as left child
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            printf("left: %d \n", temp->left->data);
        }
        // if left child is not NULL, add queue of temp->left
        queue[++rear] = temp->left;

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            printf("right: %d \n", temp->right->data);
        }
        // same as left logic
        queue[++rear] = temp->right;
    }
}

void inorderTraversal(Node* root) {
    if(root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void freeTree(Node* root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

int main() {

    Node* root = NULL;
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);

    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
