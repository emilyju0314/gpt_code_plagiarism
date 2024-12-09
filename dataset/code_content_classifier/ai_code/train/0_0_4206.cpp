#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Girl {
    int index;
    int weight;
};

bool girlComparator(Girl a, Girl b) {
    if (a.weight == b.weight) {
        return a.index < b.index;
    }
    return a.weight < b.weight;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<Girl> girls(m);
    for (int i = 0; i < m; i++) {
        girls[i].index = i + 1;
        cin >> girls[i].weight;
    }
    
    sort(girls.begin(), girls.end(), girlComparator);

    vector<vector<int>> subtreeWeights(n + 1);
    vector<int> parent(n + 1);
    parent[1] = 1;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int v, u, k;
            cin >> v >> u >> k;

            vector<Girl> invitedGirls;
            while (v != u) {
                for (int j = 0; j < adj[v].size(); j++) {
                    if (parent[v] != adj[v][j]) {
                        parent[adj[v][j]] = v;
                        v = adj[v][j];
                        break;
                    }
                }
                
                for (int j = 0; j < girls.size(); j++) {
                    if (parent[girls[j].weight] == v && k > 0) {
                        invitedGirls.push_back(girls[j].index);
                        k--;
                    }
                }
            }

            cout << invitedGirls.size() << " ";
            for (int j = 0; j < invitedGirls.size(); j++) {
                cout << invitedGirls[j] << " ";
            }
            cout << endl;
            
        } else if (t == 2) {
            int v, k;
            cin >> v >> k;

            for (int j = 0; j < girls.size(); j++) {
                if (parent[girls[j].weight] == v) {
                    girls[j].weight += k;
                }
            }
        }
    }

    return 0;
}