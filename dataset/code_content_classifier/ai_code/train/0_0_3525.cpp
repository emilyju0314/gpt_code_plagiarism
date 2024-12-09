#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parent, int x) {
    if (parent[x] == x) {
        return x;
    } else {
        parent[x] = find(parent, parent[x]);
        return parent[x];
    }
}

void unite(vector<int>& parent, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> parent(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        unite(parent, A, B);
    }
    
    int groups = 0;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) {
            groups++;
        }
    }
    
    cout << groups << endl;
    
    return 0;
}