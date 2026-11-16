import sys


class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.matrix = [[0] * vertices for _ in range(vertices)]

    def find_min(self, keys, included):
        minimum = sys.maxsize
        index = -1

        for vertex in range(self.vertices):
            if not included[vertex] and keys[vertex] < minimum:
                minimum = keys[vertex]
                index = vertex

        return index

    def prim(self, names):
        keys = [sys.maxsize] * self.vertices
        parent = [-1] * self.vertices
        included = [False] * self.vertices
        keys[0] = 0

        for _ in range(self.vertices):
            current = self.find_min(keys, included)

            if current == -1:
                break

            included[current] = True

            for neighbor in range(self.vertices):
                distance = self.matrix[current][neighbor]

                if (distance > 0 and not included[neighbor]
                        and distance < keys[neighbor]):
                    keys[neighbor] = distance
                    parent[neighbor] = current

        total = 0
        print("\nMinimum Spanning Tree edges:")

        for vertex in range(1, self.vertices):
            if parent[vertex] != -1:
                distance = self.matrix[vertex][parent[vertex]]
                print(f"{names[parent[vertex]]} -- "
                      f"{names[vertex]} = {distance}")
                total += distance

        print("Total distance:", total)


names = ["Main Gate", "CS", "IT", "Library", "Hostel"]
campus = Graph(len(names))

campus.matrix = [
    [0, 10, 8, 0, 0],
    [10, 0, 5, 3, 0],
    [8, 5, 0, 7, 6],
    [0, 3, 7, 0, 4],
    [0, 0, 6, 4, 0]
]

print("Campus locations:")
for number, name in enumerate(names):
    print(number, "-", name)

campus.prim(names)