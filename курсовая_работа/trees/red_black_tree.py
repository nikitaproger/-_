from interfaces.tree_interface import TreeInterface
from models.node import _Node

class BlackRedTree(TreeInterface):
    def __init__(self):
        self.head = _Node()

    def insert(self, x):
        node = self._search_insert(self.head, x)
        self._insert_case1(node)

    def _insert_case1(self, node):
        if node.parent is None:
            node.color_red = False
        else:
            self._insert_case2(node)

    def _insert_case2(self, node):
        if not node.parent.color_red:
            return
        else:
            self._insert_case3(node)

    def _insert_case3(self, node):
        u = self._uncle(node)
        g = self._grandparent(node)
        if u is not None and u.color_red:
            node.parent.color_red = False
            u.color_red = False
            g.color_red = True
            self._insert_case1(g)
        else:
            self._insert_case4(node)

    def _insert_case4(self, node):
        g = self._grandparent(node)
        p = node.parent
        if node is p.link_right and p is g.link_left:
            self.rotate_left(p)
            node = node.link_left
        elif node is p.link_left and p is g.link_right:
            self.rotate_right(p)
            node = node.link_right
        self._insert_case5(node)

    def _insert_case5(self, node):
        p = node.parent
        g = self._grandparent(node)
        p.color_red = False
        g.color_red = True
        if node is p.link_left and p is g.link_left:
            self.rotate_right(g)
        else:
            self.rotate_left(g)

    def rotate_left(self, node):
        right = node.link_right
        node.link_right = right.link_left
        node.link_right.parent = node
        right.parent = node.parent
        if node.parent is None:
            self.head = right
        elif node is node.parent.link_left:
            node.parent.link_left = right
        else:
            node.parent.link_right = right
        right.link_left = node
        node.parent = right

    def rotate_right(self, node):
        left = node.link_left
        node.link_left = left.link_right
        node.link_left.parent = node
        left.parent = node.parent
        if node.parent is None:
            self.head = left
        elif node is node.parent.link_left:
            node.parent.link_left = left
        else:
            node.parent.link_right = left
        left.link_right = node
        node.parent = left

    def _search_insert(self, head, x):
        if head.data is None:
            return head.make_red(x)
        if x < head.data:
            return self._search_insert(head.link_left, x)
        else:
            return self._search_insert(head.link_right, x)

    def print_tree(self, node=None, indent=0):
        if node is None:
            node = self.head
        if node.data is None:
            return
        print("-" * indent + str(node.data))
        self.print_tree(node.link_left, indent + 1)
        self.print_tree(node.link_right, indent + 1)

    def _grandparent(self, node):
        if node.parent is None:
            return None
        return node.parent.parent

    def _uncle(self, node):
        g = self._grandparent(node)
        if g is None:
            return None
        if node.parent == g.link_left:
            return g.link_right
        else:
            return g.link_left

    def _validate_structure(self, node=None, parent=None):
        if node is None:
            node = self.head
        if node.parent is not parent:
            return False
        if node.data is None:
            return True
        if node.link_left is None or node.link_right is None:
            return False
        return (self._validate_structure(node.link_left, node)
                and self._validate_structure(node.link_right, node))

    def validate_root(self):
        return not self.head.color_red

    def _validate_red_nodes(self, node=None):
        if node is None:
            node = self.head
        if node.data is None:
            return True
        if node.color_red:
            if node.link_left.color_red or node.link_right.color_red:
                return False
        return (self._validate_red_nodes(node.link_left)
                and self._validate_red_nodes(node.link_right))

    def _black_height(self, node):
        if node.data is None:
            return 1
        left = self._black_height(node.link_left)
        right = self._black_height(node.link_right)
        if left is None or right is None or left != right:
            return None
        return left + (not node.color_red)

    def validate_black_height(self):
        return self._black_height(self.head) is not None

    def validate(self):
        return (self._validate_structure() and self.validate_root()
                and self._validate_red_nodes() and self.validate_black_height())

    def contains(self, x):
        node = self.head
        while node.data is not None:
            if x < node.data:
                node = node.link_left
            elif x > node.data:
                node = node.link_right
            else:
                return True
        return False
