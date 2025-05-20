#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

void printTree(TreeNode* root) {
    if (!root) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            if (current) {
                std::cout << current->val << std::endl;
                q.push(current->left);
                q.push(current->right);
            }
            else {
                std::cout << "null"; // print "null" for missing nodes to show structure
            }
        }
        std::cout << std::endl;
    }
}

// function to calculate height of the tree
int height(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }
}

// function to delete the entire tree, prevent memory leaks
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    if (leftHeight > rightHeight) {
        return 1 + leftHeight;
    }
    else {
        return 1 + rightHeight;
    }
}

int main() {
    TreeNode* root1 = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    std::cout << "Max for Tree 1: " << maxDepth(root1) << std::endl;

    TreeNode* root2 = new TreeNode(1, nullptr, new TreeNode(2));
    std::cout << "Max for Tree 2: " << maxDepth(root2) << std::endl;


    return 0;
}

int mainhehe() {
    // simple manually created tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    std::cout << "Tree 1 Manually Created: " << std::endl;
    printTree(root1);
    std::cout << "Height of Tree 1: " << height(root1) << std::endl;

    deleteTree(root1); // clean up memory for tree1
    root1 = nullptr; // good practice to set the pointer to null after deleting

    // building a tree in a more controlled way, using constructor
    TreeNode* root2 = new TreeNode(10);
    TreeNode* leftChild = new TreeNode(20);
    TreeNode* rightChild = new TreeNode(30, new TreeNode(40), new TreeNode(50)); // using 3 args constructor

    root2->left = leftChild;
    root2->right = rightChild;

    std::cout << "\nTree 2 Constructed: " << std::endl;
    printTree(root2);
    std::cout << "Height of Tree 2: " << height(root2) << std::endl;
    deleteTree(root2);
    root2 = nullptr;

    // emptry tree
    TreeNode* root3 = nullptr;
    std::cout << "\nTree 3 Empty Tree" << std::endl;
    printTree(root3);
    std::cout << "Height of Tree 3: " << height(root3) << std::endl;

    return 0;

}

