#include <iostream>
#include <vector>
#include <unordered_map>

#define MOD 1000000009

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> roads;
    unordered_map<int, int> parent;

    vector<long long> ways(m, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        roads.push_back({a, b});

        if (parent.find(a) == parent.end()) {
            parent[a] = a;
        }
        if (parent.find(b) == parent.end()) {
            parent[b] = b;
        }

        while (parent[a] != a) {
            a = parent[a];
        }
        while (parent[b] != b) {
            b = parent[b];
        }

        if (a != b) {
            parent[b] = a;
        }
    }

    long long total_ways = 1;
    
    for (int i = m - 1; i >= 0; i--) {
        int a = roads[i].first;
        int b = roads[i].second;

        while (parent[a] != a) {
            a = parent[a];
        }
        while (parent[b] != b) {
            b = parent[b];
        }

        if (a != b) {
            total_ways *= 2;
            total_ways %= MOD;
            parent[b] = a;
        }

        ways[i] = total_ways;
    }

    for (int i = 0; i < m; i++) {
        cout << ways[i] << endl;
    }

    return 0;
}