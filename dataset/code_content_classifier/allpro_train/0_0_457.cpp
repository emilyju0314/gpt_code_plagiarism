#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    int n = 3 + (k-1) * 2; // Determine the number of vertices based on the number of cycles

    cout << n << endl;

    // Initialize the adjacency matrix with all zeros
    vector<vector<int>> adj(n, vector<int>(n, 0));

    // Add edges for the cycles
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < i+3; j++) {
            adj[i][j] = 1;
            adj[j][i] = 1;
        }
    }

    // Add additional edges to form cycles
    for (int i = 1; i < k; i++) {
        adj[i*2][i*2+1] = 1;
        adj[i*2+1][i*2] = 1;
        adj[i*2][i*2+2] = 1;
        adj[i*2+2][i*2] = 1;
    }

    // Output the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j];
        }
        cout << endl;
    }

    return 0;
}