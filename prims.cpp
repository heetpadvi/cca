prims
#include <iostream>
#include <climits>

using namespace std;

const int MAX_VERTICES = 100; // Maximum number of vertices (adjust as needed)

// Structure to represent an edge in the graph
struct Edge {
    int destination;
    int weight;
};

// Function to implement Prim's algorithm
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    // Arrays to store the parent of each vertex in the MST and the key (weight) of each vertex
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];

    // Array to keep track of whether a vertex is in the MST
    bool inMST[MAX_VERTICES] = {false};

    // Start with the first vertex (can start with any vertex)
    int startVertex = 0;
    key[startVertex] = 0;
    parent[startVertex] = -1;

    // Prim's algorithm
    for (int count = 0; count < vertices - 1; ++count) {
        int u = -1;
        int minKey = INT_MAX;

        // Find the vertex with the minimum key that is not yet in the MST
        for (int v = 0; v < vertices; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        // Add the selected vertex to the MST
        inMST[u] = true;

        // Update the key values of adjacent vertices
        for (int v = 0; v < vertices; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the Minimum Spanning Tree
    cout << "Minimum Spanning Tree using Prim's algorithm:" << endl;
    for (int i = 1; i < vertices; ++i) {
        cout << "Edge: " << parent[i] << " - " << i << "  Weight: " << key[i] << endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int vertices = 5;

    primMST(graph, vertices);

    return 0;
}
