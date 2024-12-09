#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 1; i < N; i++) {
        cin >> P[i];
    }

    vector<int> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    vector<vector<int>> children(N);
    for (int i = 1; i < N; i++) {
        children[P[i]].push_back(i);
    }

    vector<int> sorted_children(N);
    int index = 0;
    function<void(int)> dfs = [&](int node) {
        for (int child : children[node]) {
            sorted_children[index++] = child;
            dfs(child);
        }
    };

    dfs(0);

    vector<int> dp(N);
    int total = 0;
    for (int i = N - 1; i >= 0; i--) {
        int node = sorted_children[i];
        dp[node] = min(1 + dp[node], 2 - V[node]);
        total += dp[node];
    }

    cout << total << endl;

    return 0;
}