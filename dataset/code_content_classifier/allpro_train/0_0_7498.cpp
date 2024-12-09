#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool bfs(int n, int m, vector<vector<int>>& adjList, vector<int>& nodes, vector<int>& ans) {
    vector<int> inDegree(n + 1);
    for (int i = 0; i < m; i++) {
        inDegree[adjList[i][1]]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    unordered_map<int, int> values;
    bool possible = false;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < m; i++) {
            if (adjList[i][0] == curr) {
                inDegree[adjList[i][1]]--;

                if (values[curr] == 0) {
                    values[curr] = 1;
                }

                values[adjList[i][1]] = max(values[adjList[i][1]], values[curr]);

                if (inDegree[adjList[i][1]] == 0) {
                    q.push(adjList[i][1]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (values[i] == 0) {
            ans.clear();
            break;
        }
        ans.push_back(values[i]);
    }

    return (!ans.empty());
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adjList(m, vector<int>(2));
        vector<int> nodes(n + 1);
        vector<int> ans;

        for (int i = 0; i < m; i++) {
            cin >> adjList[i][0] >> adjList[i][1];
            nodes[adjList[i][0]]++;
        }

        if (bfs(n, m, adjList, nodes, ans)) {
            cout << "YES" << endl;
            for (int val : ans) {
                cout << val << " ";
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }

        if (t > 0) {
            string temp;
            getline(cin, temp); // Read and discard empty line
        }
    }

    return 0;
}