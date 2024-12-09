#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Road {
    int u, v, d;
};

bool cmp(Road a, Road b) {
    return a.d < b.d;
}

int findParent(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = findParent(parent[x], parent);
    }
    return parent[x];
}

void unionSets(int x, int y, vector<int>& parent) {
    int rootX = findParent(x, parent);
    int rootY = findParent(y, parent);
    
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<Road> roads(M);
    
    for (int i = 0; i < M; i++) {
        cin >> roads[i].u >> roads[i].v >> roads[i].d;
    }
    
    sort(roads.begin(), roads.end(), cmp);
    
    vector<int> parent(N + 1);
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    
    int maxDays = 0;
    int connected = 0;
    
    for (int i = 0; i < M; i++) {
        if (connected == N - 1) {
            break;
        }
        
        int u = roads[i].u;
        int v = roads[i].v;
        int d = roads[i].d;
        
        if (findParent(u, parent) != findParent(v, parent)) {
            unionSets(u, v, parent);
            maxDays = max(maxDays, d);
            connected++;
        }
    }
    
    if (connected < N - 1) {
        cout << -1 << endl;
    } else {
        cout << maxDays << endl;
    }
    
    return 0;
}