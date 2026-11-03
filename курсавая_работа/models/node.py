class _Node:
    def __init__(self):
        self.data = None
        self.color_red = False
        self.link_left = None
        self.link_right = None
        self.parent = None

    def make_red(self, data):
        self.data = data
        self.color_red = True

        self.link_left = _Node()
        self.link_right = _Node()

        self.link_left.parent = self
        self.link_right.parent = self
        return self