#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isReasonableNetwork(int n, vector<pair<int, int>>& friends) {
    unordered_set<int> adj[n + 1];

    for (auto p : friends) {
        adj[p.first].insert(p.second);
        adj[p.second].insert(p.first);
    }

    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            for (int k : adj[j]) {
                if (adj[i].count(k) == 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> friends;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends.push_back({a, b});
    }

    if (isReasonableNetwork(n, friends)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}