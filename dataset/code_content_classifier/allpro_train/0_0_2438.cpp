#include <iostream>
#include <vector>
using namespace std;

vector<int> friends[500005];
bool visited[500005];
int result[500005];

int dfs(int user) {
    visited[user] = true;
    int count = 1;
    for (int friend : friends[user]) {
        if (!visited[friend]) {
            count += dfs(friend);
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> group;
        for (int j = 0; j < k; j++) {
            int user;
            cin >> user;
            group.push_back(user);
        }
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < k; l++) {
                if (j != l) {
                    friends[group[j]].push_back(group[l]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        fill(visited, visited + n + 1, false);
        result[i] = dfs(i) - 1; // Subtract 1 to exclude the initial user
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}