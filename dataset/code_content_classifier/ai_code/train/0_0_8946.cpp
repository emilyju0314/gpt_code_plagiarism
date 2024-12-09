#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
vector<vector<pair<int,int>>> graph;
int dp[1 << 15][15];

int tsp(int mask, int pos) {
    if(mask == (1 << n) - 1) {
        return 0;
    }
    if(dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    for(auto nb : graph[pos]) {
        int next_pos = nb.first;
        int weight = nb.second;

        if(!(mask & (1 << next_pos))) {
            ans = min(ans, tsp(mask | (1 << next_pos), next_pos) + weight);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cin >> n >> m;
    graph.resize(n);
    
    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    int ans = INT_MAX;
    fill(dp[0], dp[1 << 15], -1);

    for(int i = 0; i < n; i++) {
        ans = min(ans, tsp(1 << i, i));
    }

    if(ans == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}