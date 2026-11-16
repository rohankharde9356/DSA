class Node:
    def __init__(self, value):
        self.data, self.left, self.right = value, None, None


def insert(root, value):
    if not root:
        return Node(value)
    if value < root.data:
        root.left = insert(root.left, value)
    elif value > root.data:
        root.right = insert(root.right, value)
    else:
        print("Duplicate:", value)
    return root


def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)


def search(root, value):
    if not root:
        return False
    if root.data == value:
        return True
    return search(root.left if value < root.data else root.right, value)


def depth(root):
    return 0 if not root else 1 + max(depth(root.left), depth(root.right))


root = None
for value in [50, 30, 70, 20, 40, 60, 80]:
    root = insert(root, value)

print("Inorder:", end=" ")
inorder(root)
print("\nSearch 40:", search(root, 40))
print("Depth:", depth(root))