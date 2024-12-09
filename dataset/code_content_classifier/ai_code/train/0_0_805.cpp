#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>>& adj_list, int start, vector<bool>& visited) {
    vector<int> connected;
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        connected.push_back(current);

        for (int neighbor : adj_list[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return connected;
}

int findMaxInvited(int n, vector<vector<int>>& friendships, vector<vector<int>>& dislikes) {
    vector<vector<int>> adj_list(n+1);
    for (vector<int>& f : friendships) {
        adj_list[f[0]].push_back(f[1]);
        adj_list[f[1]].push_back(f[0]);
    }

    vector<bool> visited(n+1, false);
    
    int max_invited = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> connected = bfs(adj_list, i, visited);

            bool valid_group = true;
            for (vector<int>& d : dislikes) {
                if (find(connected.begin(), connected.end(), d[0]) != connected.end()
                    && find(connected.begin(), connected.end(), d[1]) != connected.end()) {
                    valid_group = false;
                    break;
                }
            }

            if (valid_group) {
                max_invited = max(max_invited, (int)connected.size());
            }
        }
    }

    return max_invited;
}

int main() {
    int n, k, m;
    cin >> n >> k;

    vector<vector<int>> friendships(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> friendships[i][0] >> friendships[i][1];
    }

    cin >> m;
    vector<vector<int>> dislikes(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> dislikes[i][0] >> dislikes[i][1];
    }

    cout << findMaxInvited(n, friendships, dislikes) << endl;

    return 0;
}