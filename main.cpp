#include <iostream>
#include <list>
#include <queue>
#include <vector>

const int INF = 1e9; // "Infinity"

class Graph {
private:
    int vertices; // number of vertices
    std::list<std::pair<int, int>>
            *adj; // pairs for each adjacent vertices and paired weight
public:
    Graph(int vertices);

    // Function to add an edge to graph
    void addEdge(int u, int v, int w);

    // Print MST using Prim's algorithm
    void primMST();
};

// Allocates memory for adjacency list
Graph::Graph(int vertices) {
    this->vertices = vertices;
    adj = new std::list<std::pair<int, int>>[vertices];
}

//   u        v        w
// Point 1, Point 2, Weight
void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(std::make_pair(v, w));
    adj[v].push_back(std::make_pair(u, w));
    std::cout << u << " - " << v << std::endl;

    // adj[vertex number] should contain list of all adjacent vertices with weight
    // in the format (connected pair, weight)
}

void Graph::primMST() {
    std::vector<int> parent(vertices, -1); // Initialize parent array to -1
    std::vector<int> value(vertices, INF); // Initialize values (distances) to INF

    // Create a priority queue (min heap) to store vertices being considered for
    // MST Elements in the queue are pairs of (value, vertex) where value is the
    // distance from the MST and vertex is the vertex index
    std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>
    > pq;

    int src = 0;    // Start with vertex 0 as the source
    value[src] = 0; // Set distance of source vertex to 0
    parent[src] = 0;

    pq.push(std::make_pair(0, src)); // Push source vertex into the priority queue

    std::vector<bool> visited(vertices, false); // Keep track of visited vertices

    // STEPS FOR PRIORITY QUEUE:
    // look at all vertices that are connected to our current MST  vertex
    // determine which edge has the lowest weight to MST and add it to the queue
    // add weight to MST and proceed

    while (!pq.empty()) {

        int current_vertex = pq.top().second;
        pq.pop();

        // if vertex has already been visited, skip it. otherwise, mark it as
        // visited to add it to MST
        if (visited[current_vertex])
            continue;
        else
            visited[current_vertex] = true;

        // now look for all adjacent vertices of our current vertex. whichever one
        // is the smaller than its current weight gets put in our priority queue
        std::list<std::pair<int, int>>::iterator i;
        for (i = adj[current_vertex].begin(); i != adj[current_vertex].end(); ++i) {

            // get temp variables of our vertex and our weight
            int temp_vertex = (*i).first;
            int temp_weight = (*i).second;

            // check if the temp is not already in our MST
            // and if the weight is less than our current known weight.
            if (visited[temp_vertex] == false && temp_weight < value[temp_vertex]) {
                value[temp_vertex] = temp_weight;
                parent[temp_vertex] = current_vertex;

                // add it to the queue
                pq.push(std::make_pair(temp_weight, temp_vertex));
            }
        }
    }

    // finally, use the parent array to print out our MST
    std::cout << std::endl;
    for (int i = 1; i < vertices; i++) {
        std::cout << parent[i] << " - " << i << std::endl;
    }
}

int main() {
    int vertices = 9; // Update the number of vertices to 9
    Graph g(vertices);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 9);
    g.addEdge(1, 4, 9);
    g.addEdge(1, 2, 12);
    g.addEdge(4, 7, 8);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 3);
    g.addEdge(3, 5, 7);
    g.addEdge(4, 7, 8);
    g.addEdge(4, 6, 5);
    g.addEdge(5, 6, 3);
    g.addEdge(6, 7, 15);
    g.addEdge(6, 8, 11);
    g.addEdge(7, 8, 10);

    g.primMST();
    return 0;
}
