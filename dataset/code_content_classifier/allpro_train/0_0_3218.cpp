#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, q;
vector<vector<int>> matrix;
vector<int> parent, rank;
int numComponents = 0;

int find(int u) {
    if(parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    
    if(pu == pv) return;
    
    if(rank[pu] < rank[pv]) {
        swap(pu, pv);
    }
    
    parent[pv] = pu;
    rank[pu] += rank[pv];
    numComponents--;
}

int main() {
    cin >> n >> m >> q;
    
    matrix = vector<vector<int>>(n, vector<int>(m, 0));
    parent = vector<int>(n*m);
    rank = vector<int>(n*m, 1);
    
    for(int i = 0; i < n*m; i++) parent[i] = i;
    numComponents = n*m;
    
    vector<pair<int, pair<int, int>>> queries;
    for(int i = 0; i < q; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        queries.push_back({c, {x, y}});
    }
    
    sort(queries.begin(), queries.end());
    
    vector<int> ans;
    for(auto query : queries) {
        int x = query.second.first;
        int y = query.second.second;
        int c = query.first;
        
        int currVal = matrix[x][y];
        matrix[x][y] = c;
        
        numComponents++;
        
        if(x > 0 && matrix[x-1][y] == c) {
            unite(x*m+y, (x-1)*m+y);
        }
        if(x < n-1 && matrix[x+1][y] == c) {
            unite(x*m+y, (x+1)*m+y);
        }
        if(y > 0 && matrix[x][y-1] == c) {
            unite(x*m+y, x*m+y-1);
        }
        if(y < m-1 && matrix[x][y+1] == c) {
            unite(x*m+y, x*m+y+1);
        }
        
        ans.push_back(numComponents);
    }
    
    for(int i : ans) {
        cout << i << "\n";
    }
    
    return 0;
}