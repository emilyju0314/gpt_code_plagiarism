#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;

bool isBus(int n, int m) {
    if (m != n - 1) {
        return false;
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            count++;
        }
    }
    return count == 2;
}

bool isRing(int n, int m) {
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() != 2) {
            return false;
        }
    }
    return true;
}

bool isStar(int n, int m) {
    int centralNode = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == n - 1) {
            centralNode++;
        } else if (adj[i].size() == 1) {
            continue;
        } else {
            return false;
        }
    }
    return centralNode == 1;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (isBus(n, m)) {
        cout << "bus topology\n";
    } else if (isRing(n, m)) {
        cout << "ring topology\n";
    } else if (isStar(n, m)) {
        cout << "star topology\n";
    } else {
        cout << "unknown topology\n";
    }

    return 0;
}