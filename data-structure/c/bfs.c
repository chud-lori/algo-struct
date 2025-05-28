#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists; // array of linked list
    int* visited; // 1 or 0
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**) malloc(vertices * sizeof(Node*));
    graph->visited = (int*) malloc(vertices * sizeof(int));

    for(int i = 0; i < vertices; ++i) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// function to add an edge to the graph (undirected graph)
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dst
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // add edge from dst to src for undirected graph
    newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// function to implement bfs
void bfs(Graph* graph, int startVertex) {
    // create a queue
    int queue[graph->numVertices];
    int front = 0, rear = 0;

    // enqueue the starting vertex and mark it as visited
    queue[rear++] = startVertex;
    graph->visited[startVertex] = 1;

    printf("BFS Traversal starting from vertex %d", startVertex);

    while (front < rear) {
        // dequeue a vertex from the queue
        int currentVertex = queue[front++];
        printf("%d", currentVertex);

        // get the adjacent vertices of the current vertex
        Node* temp = graph->adjLists[currentVertex];

        // enqueue each unvisited adjacent vertex
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                queue[rear++] = adjVertex;
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int numVertices = 6;
    Graph* graph = createGraph(numVertices);

    // add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    // perform BFS starting from vertex 0
    bfs(graph, 0); // expected output 0 1 2 3 4 5

    // clean up memory, important
    for (int i = 0; i < numVertices; ++i) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);

    return 0;
}

