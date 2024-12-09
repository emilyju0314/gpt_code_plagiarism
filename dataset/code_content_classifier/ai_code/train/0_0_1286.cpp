#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> parent(N+1, 0);
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    
    vector<int> sz(N+1, 1);
    
    function<int(int)> find = [&](int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    };
    
    auto unite = [&](int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        
        parent[y] = x;
        sz[x] += sz[y];
        
    };
    
    long long total = 1LL * N * (N-1) / 2;
    vector<long long> ans(M);
    
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        
        ans[i] = total;
        
        if(find(A) != find(B)) {
            total -= 1LL * sz[find(A)] * sz[find(B)];
        }
        
        unite(A, B);
    }
    
    for(int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}