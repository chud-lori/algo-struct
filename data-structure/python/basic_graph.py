class Graph:
    def __init__(self, size):
        self.adj_matrix = [[0] * size for _ in range(size)]
        self.size = size
        self.vertex_data = [''] * size

    def add_edge(self, u, v):
        if 0 <= u < self.size and 0 <= v < self.size:
            self.adj_matrix[u][v] = 1
            self.adj_matrix[v][u] = 1

    def add_vertex_data(self, vertex, data):
        print(self.vertex_data)
        if 0 <= vertex < self.size:
            self.vertex_data[vertex] = data

    def print_graph(self):
        print("Adjacency Matrix")
        for row in self.adj_matrix:
            print(' '.join(map(str, row)))

        print("\nVertex Data:")
        for vertex, data in enumerate(self.vertex_data):
            print(f"Vertex {vertex}: {data}")

    def print_connections(self):
        # seems like still wrong
        print("\nConnections for each vertex")
        for i in range(len(self.vertex_data)):
            if not self.vertex_data[i]:
                continue
            print(f"{self.vertex_data[i]}: ", end="")
            for j in range(len(self.vertex_data)):
                if self.adj_matrix[i][j]:
                    print(self.vertex_data[j], end=" ")
            print()



g = Graph(4)
g.add_vertex_data(0, 'A')
g.add_vertex_data(1, 'B')
g.add_vertex_data(2, 'C')
g.add_vertex_data(3, 'D')
g.add_edge(0, 1) # A - B
g.add_edge(0, 2) # A - C
g.add_edge(0, 3) # A - D
g.add_edge(1, 2) # B - C

g.print_graph()
g.print_connections()


# Basic to show the connection and nodes
#vertex_data = ['A', 'B', 'C', 'D']
#adjacency_matrix = [
#    [0, 1, 1, 1], # Edge for A
#    [1, 0, 1, 0], # Edge for B
#    [1, 1, 0, 0], # Edge for C
#    [1, 0, 0, 0]  # Edge for D
#]
#
#def print_adjacency_matrix(matrix):
#    print("Adjacency Matrix:")
#    for row in matrix:
#        print(row)
#
#
#def print_connections(matrix, vertices):
#    print("\nConnections for each vertex:")
#    for i in range(len(vertices)):
#        print(f"{vertices[i]}: ", end="")
#        for j in range(len(vertices)):
#            if matrix[i][j]: # if there is connection
#                print(vertices[j], end=" ")
#        print()
#
#print_adjacency_matrix(adjacency_matrix)
#print_connections(adjacency_matrix, vertex_data)
#
