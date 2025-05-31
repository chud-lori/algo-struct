#include <stdio.h>
#include <stdlib.h>

#define MAX 3  // Maximum number of keys in a node
#define MIN 2  // Minimum number of keys in a node (except root)

// B-tree node structure
struct BTreeNode {
    int val[MAX + 1];        // Array to store keys/values (1-based indexing)
    int count;               // Number of keys currently in node
    struct BTreeNode *link[MAX + 1];  // Array of pointers to child nodes
};

struct BTreeNode *root = NULL;  // Global root pointer, initialize to NULL

// Creates a new B-tree node
struct BTreeNode* createNode(int val, struct BTreeNode* child) {
    struct BTreeNode* newNode = (struct BTreeNode*) malloc(sizeof(struct BTreeNode));
    newNode->val[1] = val;    // Store value in first position (1-based indexing)
    newNode->count = 1;       // Set count to 1 as we're adding first value
    newNode->link[0] = root;  // Left child
    newNode->link[1] = child; // Right child
    return newNode;
}

// Inserts a value into a non-full node at specified position
void insertNode(int val, int pos, struct BTreeNode* node, struct BTreeNode* child) {
    int j = node->count;  // Start from last element
    // Shift elements to right to make space for new value
    while (j > pos) {
        node->val[j + 1] = node->val[j];    // Shift values
        node->link[j + 1] = node->link[j];  // Shift child pointers
        j--;
    }
    node->val[j + 1] = val;    // Insert new value
    node->link[j + 1] = child; // Insert new child pointer
    node->count++;             // Increment count
}

// Splits a full node during insertion
void splitNode(int val, int* pval, int pos, struct BTreeNode* node,
               struct BTreeNode* child, struct BTreeNode** newNode) {
    int median;
    // Determine median position
    if (pos > MIN)
        median = MIN + 1;
    else
        median = MIN;

    // Create new node to store split values
    *newNode = (struct BTreeNode*) malloc(sizeof(struct BTreeNode));

    // Move values and pointers from median+1 to MAX to new node
    int j = median + 1;
    while (j <= MAX) {
        (*newNode)->val[j - median] = node->val[j];
        (*newNode)->link[j - median] = node->link[j];
        j++;
    }

    // Update counts for both nodes
    node->count = median;      // Original node now has median elements
    (*newNode)->count = MAX - median;  // New node has remaining elements

    // Insert the new value in appropriate node
    if (pos <= MIN)
        insertNode(val, pos, node, child);
    else
        insertNode(val, pos - median, *newNode, child);

    // Setup the median value to move up to parent
    *pval = node->val[node->count];
    (*newNode)->link[0] = node->link[node->count];
    node->count--;
}

// Recursive function to set value in B-tree
int setValue(int val, int* pval, struct BTreeNode* node, struct BTreeNode** child) {
    int pos;

    // If node is NULL, this is insertion point
    if (!node) {
        *pval = val;
        *child = NULL;
        return 1;  // Return 1 to indicate insertion needed
    }

    // Find position where value should be inserted
    if (val < node->val[1])
        pos = 0;
    else {
        // Find appropriate position, checking for duplicates
        for (pos = node->count; (val < node->val[pos] && pos > 1); pos--) {
            if (val == node->val[pos]) {
                printf("Duplicates are not permitted\n");
                return 0;
            }
        }
    }

    // Recursively set value in appropriate child
    if (setValue(val, pval, node->link[pos], child)) {
        if (node->count < MAX) {
            // Node has space, insert directly
            insertNode(*pval, pos, node, *child);
        }
        else {
            // Node is full, need to split
            splitNode(*pval, pval, pos, node, *child, child);
            return 1;  // Indicate that splitting occurred
        }
    }
    return 0;
}

// Main insertion function
void insert(int val) {
    int flag, i;
    struct BTreeNode* child;

    // Try to insert value
    flag = setValue(val, &i, root, &child);
    if (flag) {
        // If root was split or tree is empty, create new root
        root = createNode(i, child);
    }
}

// Search for a value in the B-tree
void search(int val, int* pos, struct BTreeNode* myNode) {
    if (!myNode) {
        *pos = -1;  // Value not found
        return;
    }

    // Find position in current node
    if (val < myNode->val[1])
        *pos = 0;
    else {
        for (*pos = myNode->count;
             (val < myNode->val[*pos] && *pos > 1);
             (*pos)--);
        if (val == myNode->val[*pos]) {
            printf("%d is found\n", val);
            return;
        }
    }
    // Continue search in appropriate child node
    search(val, pos, myNode->link[*pos]);
}

// In-order traversal of B-tree
void traversal(struct BTreeNode* myNode) {
    int i;
    if (myNode) {
        for(i = 0; i < myNode->count; i++) {
            traversal(myNode->link[i]);     // Visit left subtree
            printf("%d ", myNode->val[i + 1]); // Print current value
        }
        traversal(myNode->link[i]);         // Visit rightmost subtree
    }
}

int main() {
    int val, ch;


    insert(8);
    insert(9);
    insert(10);
    insert(11);
    insert(15);
    insert(16);
    insert(17);
    insert(18);
    insert(20);
    insert(23);

    traversal(root);

    printf("\n");
    search(11, &ch, root);

    return 0;
}
