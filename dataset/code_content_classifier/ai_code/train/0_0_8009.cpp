#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> adj;
vector<char> letter;
vector<unordered_map<int, int>> depthCount;

void dfs(int u, int p, int d) {
    depthCount[d][letter[u]]++;

    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    depthCount.resize(n);
    letter.resize(n);

    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        adj[p - 1].push_back(i);
    }

    for(int i = 0; i < n; i++) {
        cin >> letter[i];
    }

    dfs(0, -1, 1);

    for(int i = 0; i < m; i++) {
        int v, h;
        cin >> v >> h;
        v--;

        if(h > depthCount[v].size()) {
            cout << "No" << endl;
        } else {
            int oddCount = 0;
            for(auto& count : depthCount[v]) {
                if(count.second % 2 != 0) {
                    oddCount++;
                }
            }

            if(oddCount <= 1) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}