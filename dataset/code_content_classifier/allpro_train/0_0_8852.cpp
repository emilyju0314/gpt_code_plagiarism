#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool bfs(vector<vector<int>>& adjList, vector<int>& color, int start) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adjList[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
                return false;
            }
        }
    }

    return true;
}

bool canAssignTeachers(int n, vector<pair<int, int>>& passages) {
    vector<vector<int>> adjList(n + 1);
    vector<int> color(n + 1, -1);

    for (auto passage : passages) {
        int u = passage.first;
        int v = passage.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            if (!bfs(adjList, color, i)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> passages(m);
        for (int i = 0; i < m; i++) {
            cin >> passages[i].first >> passages[i].second;
        }

        if (canAssignTeachers(n, passages)) {
            cout << "YES" << endl;

            int count = count_if(passages.begin(), passages.end(), [&](pair<int, int> p){
                return passages[p.first] != passages[p.second]; 
            });

            cout << count << endl;

            for(auto p : passages){
                 if(p.first%p.second){
                     cout << p.first << " " << p.second << endl;
             }
        } 
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}