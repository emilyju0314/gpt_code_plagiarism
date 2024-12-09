#include <bits/stdc++.h>
using namespace std;

struct UnionFindTree{
    int N;
    vector<int> par;
    void init(int n){
        N = n;
        par.resize(N);
        for(int i=0;i<N;i++){
            par[i] = i;
        }
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(x > y) swap(x, y);
        par[x] = y;
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    UnionFindTree g;
    g.init(n+m);
    for(int i=0;i<k;i++){
        int f, x, y;
        cin >> f >> x >> y;
        x--; y--;
        if(f == 1){
            if(g.find(x) >= n && g.find(y) >= n && !g.same(x, y)){
                cout << i+1 << endl;
                return 0;
            }
            g.unite(x,y);
        }
        else{
            if(g.find(x) >= n && !g.same(x,y+n)){
                cout << i+1 << endl;
                return 0;
            }
            g.unite(x, y+n);
        }
    }
    cout << 0 << endl;
    return 0;
}

