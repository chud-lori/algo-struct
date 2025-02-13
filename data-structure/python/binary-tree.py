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
        if self.left:
            self.left.inorderTraversal()
        if self.data:
            print(self.data)
        if self.right:
            self.right.inorderTraversal()

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

    13 15 17 20 30 40
    """

    #root.inorderTraversal()
    root.search(15)

