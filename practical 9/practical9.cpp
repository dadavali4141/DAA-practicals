#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "\nEnter adjacency matrix (" << n << " x " << n << "):\n";

    for (int i = 0; i < n; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> key(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        if (u == -1 || key[u] == INT_MAX) {
            cout << "\nGraph is disconnected. MST cannot be formed.\n";
            return 0;
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        total += graph[i][parent[i]];
    }

    cout << "\nTotal MST weight = " << total << endl;

    return 0;
}