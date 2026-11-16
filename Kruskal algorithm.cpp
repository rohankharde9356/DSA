class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.edges = []

    def add_edge(self, u, v, weight):
        self.edges.append((u, v, weight))

    def find(self, parent, node):
        if parent[node] != node:
            parent[node] = self.find(parent, parent[node])
        return parent[node]

    def kruskal(self):
        parent = list(range(self.vertices))
        mst = []

        for u, v, weight in sorted(self.edges, key=lambda edge: edge[2]):
            root_u = self.find(parent, u)
            root_v = self.find(parent, v)

            if root_u != root_v:
                mst.append((u, v, weight))
                parent[root_v] = root_u

        total = 0
        print("Minimum Spanning Tree Edges:")
        for u, v, weight in mst:
            print(f"{u} -- {v} = {weight}")
            total += weight
        print("Total Cost of MST =", total)


# 0: Main Gate, 1: Computer Dept, 2: IT Dept
# 3: Library, 4: Hostel
g = Graph(5)
g.add_edge(0, 1, 10)
g.add_edge(0, 2, 8)
g.add_edge(1, 2, 5)
g.add_edge(1, 3, 3)
g.add_edge(2, 3, 7)
g.add_edge(2, 4, 6)
g.add_edge(3, 4, 4)

g.kruskal()