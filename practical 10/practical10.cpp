#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    // Initialize parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            cout << e.u << " - " << e.v << " : " << e.weight << endl;

            totalCost += e.weight;
            unite(e.u, e.v);
        }
    }

    cout << "Minimum Cost = " << totalCost << endl;

    return 0;
}