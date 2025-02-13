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

void insertBST(Node** root, int data) {
    /*
     * pass pointer of pointer of root to pass by reference
     * bcs the way we defined root as pointer of Node instead of just Node
    */
    Node* newNode = createNode(data);
    if(*root == NULL) {
        *root = newNode;
        return;
    }
    Node* rootNode = *root;

    if (data < rootNode->data) {
        if (rootNode->left == NULL) {
            rootNode->left = newNode;
        }
        else {
            // here, after traverse using recursive
            // if the newNode is inserted let's say in the above if condition
            // where left is null, then all's good
            // BUT, if the parent call doesn't insert the data
            // meaning the left is not null
            // then it will call recursive of insertBST, right?
            // where in that recursive it will create another newNode
            // that's why the parent call should check if the current node of left
            // is the newNode, if not it will freed the newNode because not inserted anywhere
            // but has memory allocated in createNode() function
            insertBST(&rootNode->left, data);
            if (rootNode->left == newNode) return;
            free(newNode);
            return;
        }
    }
    else if (data > rootNode->data) {
        if (rootNode->right == NULL) {
            rootNode->right = newNode;
        }
        else {
            insertBST(&rootNode->right, data);
            if (rootNode->right == newNode) return;
            free(newNode);
            return;
        }
    }
    else {
        // duplicated data will free immidiately
        free(newNode);
        return;
    }
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

void preorderTraversal(Node* root) {
    if(root == NULL) return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if(root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
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
    //insert(&root, 20);
    //insert(&root, 30);
    //insert(&root, 40);
    //insert(&root, 50);

    insertBST(&root, 20);
    insertBST(&root, 30);
    insertBST(&root, 40);
    insertBST(&root, 15);
    insertBST(&root, 17);
    insertBST(&root, 13);

    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal of the binary search tree: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal of the binary search tree: ");
    postorderTraversal(root);
    printf("\n");



    freeTree(root);

    return 0;
}
