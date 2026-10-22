
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 99999

int main() {
    int n;
    int cost[10][10];
    int path[10];
    int visited[10] = {0};
    int minCost = INF;

    cout << "Enter number of cities: ";
    cin >> n;

    if (n < 2 || n > 10) {
        cout << "Invalid number of cities!";
        return 1;
    }

    cout << "Enter cost matrix (99999 for no route):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    // Brute-force permutation approach
    for (int i = 1; i < n; i++)
        path[i - 1] = i;

    int bestPath[10];
    bool found = false;

    do {
        int total = 0;
        int current = 0;
        bool valid = true;

        for (int i = 0; i < n - 1; i++) {
            int next = path[i];

            if (cost[current][next] == INF) {
                valid = false;
                break;
            }

            total += cost[current][next];
            current = next;
        }

        if (valid && cost[current][0] != INF) {
            total += cost[current][0];

            if (total < minCost) {
                minCost = total;
                for (int i = 0; i < n - 1; i++)
                    bestPath[i] = path[i];
                found = true;
            }
        }

    } while (next_permutation(path, path + n - 1));

    if (found) {
        cout << "\nMinimum cost: " << minCost;
        cout << "\nOptimal tour: 1 ";

        for (int i = 0; i < n - 1; i++)
            cout << bestPath[i] + 1 << " ";

        cout << "1\n";
    } else {
        cout << "\nNo complete tour exists.\n";
    }

    return 0;
}