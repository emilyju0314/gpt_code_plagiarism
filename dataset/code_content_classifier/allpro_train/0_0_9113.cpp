#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> groups(n);
    for (int i = 0; i < n; i++) {
        cin >> groups[i];
    }

    vector<unordered_set<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].insert(b-1);
        adj[b-1].insert(a-1);
    }

    vector<int> group_size(k+1, 0);
    for (int i = 0; i < n; i++) {
        group_size[groups[i]]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int other_group_size = n - group_size[groups[i]];
        int cnt = 0;
        for (int adj_student : adj[i]) {
            if (groups[adj_student] != groups[i]) {
                cnt++;
            }
        }
        if (cnt == 0) {
            ans += other_group_size - 1;
        }
    }

    cout << ans/2 << endl;

    return 0;
}