#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> children;
vector<int> parent;
vector<int> timer;
vector<long long> answerTime;

void dfs(int node) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    while (!pq.empty()) {
        int t = timer[pq.top().second];
        int from = pq.top().second;
        pq.pop();

        if (from == 0) {
            answerTime[node] = t;
            continue;
        }

        if (timer[node] <= t) {
            cout << t << " ";
            return;
        }

        pq.push({t + 1, parent[from]});
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    children.resize(n+1);
    parent.resize(n+1);
    timer.resize(n+1, -1);
    answerTime.resize(n+1, -1);

    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int x, t;
        cin >> x >> t;
        timer[x] = t;
        dfs(x);
    }

    return 0;
}