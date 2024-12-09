#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5005;
vector<pair<int, int>> adj[MAXN];
int subtree_size[MAXN];
long long total_sum = 0;

int calculate_subtree_size(int node, int parent) {
    subtree_size[node] = 1;

    for (auto edge : adj[node]) {
        int child = edge.first;
        int weight = edge.second;

        if (child != parent) {
            subtree_size[node] += calculate_subtree_size(child, node);
            total_sum += 2 * min(subtree_size[child], MAXN - subtree_size[child]) * weight;
        }
    }

    return subtree_size[node];
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    calculate_subtree_size(1, -1);

    cout << total_sum << endl;

    return 0;
}