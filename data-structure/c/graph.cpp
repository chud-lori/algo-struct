#include <iostream>
#include <vector>

class Graph {
    // Adjacency matrix to store graph edges
    std::vector<std::vector<int> > adj_matrix;

    public:
        // Constructor to initialize the graph with n vertices
        Graph(int n) {
            adj_matrix = std::vector<std::vector<int> >(n, std::vector<int>(n, 0));
        }

        // Function to add an edge between vertices 'u' and 'v' of the graph
        void add_edge(int u, int v) {
            // set edge from u to v
            adj_matrix[u][v] = 1;
            // set edge from v to u (for undirected graph)
            adj_matrix[v][u] = 1;
        }

        // Function to print the adjacency matrix representation of the graph
        void print() {
            // Get the number of the vertices
            std::cout << "Adjacency Matrix of the Graph" << std::endl;
            int n = adj_matrix.size();
            for(size_t i = 0; i < n; ++i) {
                for(size_t j = 0; j < n; ++j) {
                    std::cout << adj_matrix[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
};

int main() {
    // number of vertices
    int n = 4;
    // create graph with n vertices
    Graph g(n);

    // adding the specified edges in the graph
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);

    // print the adjacency matrix representation of the graph
    g.print();

    return 0;
}

