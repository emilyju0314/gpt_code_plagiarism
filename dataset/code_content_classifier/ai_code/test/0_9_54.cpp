#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;
vector<int> roles;
vector<int> visited;

bool dfs(int node, int role) {
    if(visited[node] != -1) {
        return visited[node] == role;
    }

    visited[node] = role;

    for(int neighbor : adj_list[node]) {
        if(!dfs(neighbor, role ^ 1)) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        adj_list.clear();
        adj_list.resize(n);
        roles.clear();
        roles.resize(n, -1); // -1 represents unknown role
        visited.clear();
        visited.resize(n, -1);

        for(int i = 0; i < m; i++) {
            int a, b;
            string c;
            cin >> a >> b >> c;
            a--; b--;

            if(c == "imposter") {
                adj_list[a].push_back(b);
            } else {
                adj_list[b].push_back(a);
            }
        }

        for(int i = 0; i < n; i++) {
            if(visited[i] == -1 && !dfs(i, 0)) {
                cout << -1 << endl;
                break;
            }
        }

        int imposters = 0;
        for(int role : visited) {
            if(role == 1) {
                imposters++;
            }
        }

        if(imposters > 0 && imposters < n) {
            cout << imposters << endl;
        } else {
            cout << n << endl;
        }
    }

    return 0;
}