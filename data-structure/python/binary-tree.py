from typing import Optional

class Node:
    data: int
    left: Optional["Node"]
    right: Optional["Node"]
    def __init__(self, data: int, left: Optional["Node"] = None, right: Optional["Node"] = None):
        self.data = data
        self.left = left
        self.right = right

    def insert(self, data):
        # binary search tree
        if not self.data:
            # incase the node is never been initiate using Node(data)
            self.data = data
            return
        if data < self.data:
            if self.left is None:
                self.left = Node(data)
            else:
                self.left.insert(data)
        elif data > self.data:
            if self.right is None:
                self.right = Node(data)
            else:
                self.right.insert(data)
    def search(self, valFind):
        if valFind < self.data:
            if self.left is None:
                print("Not found")
                return
            return self.left.search(valFind)
        elif valFind > self.data:
            if self.right is None:
                print("Notfound")
                return
            return self.right.search(valFind)
        else:
            # meaning the value is found or same with current self.data
            print(f"FOUND {self.data}")

    def inorderTraversal(self):
        # left -> root -> right
        if self.left:
            self.left.inorderTraversal()
        if self.data:
            print(self.data, end=" ")
        if self.right:
            self.right.inorderTraversal()

    def preorderTraversal(self):
        # root -> left -> right
        if self.data is not None:
            print(self.data, end=" ")
            if self.left is not None:
                self.left.preorderTraversal()
            if self.right is not None:
                self.right.preorderTraversal()

    def postorderTraversal(self):
        # left -> right -> root
        if self.data is not None:
            if self.left is not None:
                self.left.postorderTraversal()
            if self.right is not None:
                self.right.postorderTraversal()
            print(self.data, end=" ")

if __name__ == "__main__":
    root = Node(20)
    root.insert(30)
    root.insert(40)
    root.insert(15)
    root.insert(17)
    root.insert(13)
    """
    20
   /   \
  15    30
  / \   / \
 13  17    40

inorder traversal 13 15 17 20 30 40
preorder traversal 20 15 13 30 40
postorder traversal 13 17 15 40 30 20
    """

    print("Inorder Traversal")
    root.inorderTraversal()
    print("\n")
    print("Preorder Traversal")
    root.preorderTraversal()
    print("\n")
    print("Postorder Traversal")
    root.postorderTraversal()
    print()
    # root.search(15)

