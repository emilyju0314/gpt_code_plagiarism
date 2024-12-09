#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> money_needed, donation_amount;
vector<bool> visited;

long long total_amount_needed = 0;

void dfs(int node, int parent) {
    visited[node] = true;
    total_amount_needed += money_needed[node];
    
    for(int neighbor : adj[node]) {
        if(neighbor != parent && !visited[neighbor]) {
            dfs(neighbor, node);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    adj.resize(N);
    money_needed.resize(N);
    donation_amount.resize(N);
    visited.resize(N, false);

    for(int i = 0; i < N; i++) {
        cin >> money_needed[i] >> donation_amount[i];
    }

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    vector<long long> remaining_amounts;
    for(int i = 0; i < N; i++) {
        remaining_amounts.push_back(max((long long)0, total_amount_needed - money_needed[i]));
    }

    sort(remaining_amounts.rbegin(), remaining_amounts.rend());

    long long initial_amount = total_amount_needed + remaining_amounts[0];
    cout << initial_amount << endl;

    return 0;
}