#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> values(N);
    for(int i = 0; i < N; i++) {
        cin >> values[i];
    }

    vector<vector<int>> adj(N);
    for(int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        adj[s-1].push_back(t-1);
        adj[t-1].push_back(s-1);
    }

    vector<int> dp(N, 0);
    vector<bool> visited(N, false);

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;

        vector<int> stack = {i};
        int sum = 0;

        while(!stack.empty()) {
            int curr = stack.back();
            stack.pop_back();

            visited[curr] = true;
            sum += values[curr];

            for(int next : adj[curr]) {
                if(!visited[next]) {
                    stack.push_back(next);
                    visited[next] = true;
                }
            }
        }

        for(int j = 0; j < N; j++) {
            dp[j] = max(dp[j], sum);
        }
    }

    cout << dp[N-1] << endl;

    return 0;
}