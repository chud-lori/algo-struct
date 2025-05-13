#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

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
            //printf("left: %d \n", temp->left->data);
        }
        // if left child is not NULL, add queue of temp->left
        queue[++rear] = temp->left;

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            //printf("right: %d \n", temp->right->data);
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

bool isBstMinMax(Node* root, int min, int max) {
    /*
     * it uses recursive to check subtree left and right, and make sure the subtree is lesser than parent in left, and greater than parent in right
    */
    if (root == NULL) return true;

    if (root->data < min || root-> data > max) return false;

    return isBstMinMax(root->left, min, root->data - 1) && isBstMinMax(root->right, root->data + 1, max);
}

bool isBstInorder(Node* root, int* prev) {
    if (root == NULL)
        return true;

    if(!isBstInorder(root, prev))
        return false;

    if(*prev >= root->data)
        return false;

    *prev = root->data;

    return isBstInorder(root, prev);
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
    Node* rootBst = NULL;

    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 15);
    insert(&root, 17);
    insert(&root, 13);

    insertBST(&rootBst, 20);
    insertBST(&rootBst, 30);
    insertBST(&rootBst, 40);
    insertBST(&rootBst, 15);
    insertBST(&rootBst, 17);
    insertBST(&rootBst, 13);

    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(rootBst);
    printf("\n");

    printf("Preorder traversal of the binary search tree: ");
    preorderTraversal(rootBst);
    printf("\n");

    printf("Postorder traversal of the binary search tree: ");
    postorderTraversal(rootBst);
    printf("\n");

    bool isBstMinMaxB = isBstMinMax(rootBst, INT_MIN, INT_MAX);
    printf("The tree is BST (MIN MAX): %s\n", isBstMinMaxB ? "true" : "false");

    int prev = INT_MIN;
    bool isBstInorderB = isBstInorder(rootBst, &prev);
    printf("The tree is BST (Inorder Traversal): %s\n", isBstInorderB ? "true" : "false");

    //bool isBstMinMax = isBstMinMax(rootBst, INT_MIN, INT_MAX);
    //printf("The tree is BST (MIN MAX): %s\n", isBstMinMax ? "true" : "false");

    freeTree(root);
    freeTree(rootBst);

    return 0;
}
