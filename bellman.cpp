bellmann ford dp
#include <iostream>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Function to perform Bellman-Ford algorithm
void bellmanFord(Edge edges[], int vertices, int edgesCount, int source) {
    // Array to store the distance from the source to each vertex
    int distance[vertices];

    // Initialize distances to infinity
    for (int i = 0; i < vertices; ++i)
        distance[i] = INT_MAX;

    // Set distance to source as 0
    distance[source] = 0;

    // Relax edges repeatedly
    for (int i = 1; i <= vertices - 1; ++i) {
        for (int j = 0; j < edgesCount; ++j) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < edgesCount; ++j) {
        int u = edges[j].source;
        int v = edges[j].destination;
        int w = edges[j].weight;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            cout << "Graph contains negative weight cycle. Bellman-Ford algorithm does not work." << endl;
            return;
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from source vertex " << source << " are:" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    // Example graph represented as an array of edges
    Edge edges[] = {
        {0, 1, 5},
        {0, 2, 4},
        {1, 3, 3},
        {2, 1, 6},
        {2, 3, 2},
        {2, 4, 7},
        {3, 4, 1},
        {4, 1, 2}
    };

    int vertices = 5;
    int edgesCount = sizeof(edges) / sizeof(edges[0]);
    int sourceVertex = 0;

    bellmanFord(edges, vertices, edgesCount, sourceVertex);

    return 0;
}
