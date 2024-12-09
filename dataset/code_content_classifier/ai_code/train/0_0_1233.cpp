#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> costs(3, vector<int>(n));
    for(int i=0; i<3; i++) {
        for(int j=0; j<n; j++) {
            cin >> costs[i][j];
        }
    }

    vector<vector<int>> adj_list(n);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u-1].push_back(v-1);
        adj_list[v-1].push_back(u-1);
    }

    vector<int> degree(n, 0);
    for(int i=0; i<n; i++) {
        degree[i] = adj_list[i].size();
    }

    // Check if there is a good painting
    for(int i=0; i<n; i++) {
        if(degree[i] > 2) {
            cout << "-1" << endl;
            return 0;
        }
    }

    // Find the root of the tree
    int root = 0;
    for(int i=0; i<n; i++) {
        if(degree[i] == 1) {
            root = i;
            break;
        }
    }

    long long min_cost = LLONG_MAX;
    vector<int> color(n);
    vector<int> best_coloring;

    vector<int> colors = {0, 1, 2};
    do {
        vector<int> coloring(n);
        long long cost = 0;
        
        queue<int> q;
        q.push(root);
        coloring[root] = colors[0];
        cost += costs[colors[0]][root];
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : adj_list[u]) {
                if(coloring[v] == 0) {
                    for(int c : colors) {
                        if(c != coloring[u] && c != coloring[adj_list[u][0]]) {
                            coloring[v] = c;
                            cost += costs[c][v];
                            break;
                        }
                    }
                    q.push(v);
                }
            }
        }

        if(cost < min_cost) {
            min_cost = cost;
            best_coloring = coloring;
        }
        
    } while(next_permutation(colors.begin(), colors.end()));

    cout << min_cost << endl;
    for(int c : best_coloring) {
        cout << c+1 << " ";
    }
    cout << endl;

    return 0;
}