#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        adj[p][q] = a[p];
        adj[q][p] = a[q];
    }

    for (int i = 0; i < n; i++) {
        int total_soldiers = 0;
        for (int j = 0; j < n; j++) {
            total_soldiers += adj[i][j];
        }
        adj[i][i] = a[i] - total_soldiers;
    }
    
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}