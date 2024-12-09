#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adj_list;
vector<int> discovered_time;
vector<int> finish_time;
int current_time = 1;

void dfs(int u) {
    discovered_time[u] = current_time++;
    for (int v : adj_list[u]) {
        if (discovered_time[v] == 0) {
            dfs(v);
        }
    }
    finish_time[u] = current_time++;
}

int main() {
    int n;
    cin >> n;

    adj_list.resize(n+1);
    discovered_time.resize(n+1);
    finish_time.resize(n+1);

    for (int i = 1; i <= n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            adj_list[u].push_back(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (discovered_time[i] == 0) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << discovered_time[i] << " " << finish_time[i] << endl;
    }

    return 0;
}