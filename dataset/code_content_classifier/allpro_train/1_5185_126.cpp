#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

int main(){
    int N, M;

    while(cin >> N >> M){
        if(N ==0) break;
        UnionFind<int> UF(N);
        for(int i=0; i<M; ++i){
            char sign;
            int l, r, w;
            cin >> sign;
            if(sign=='?'){
                cin >> l >> r;
                --l, --r;
                if(!UF.issame(l, r)){
                    puts("UNKNOWN");
                }else{
                    cout << UF.diff(l, r) << endl;
                }
            }else{
                cin >> l >> r >> w;
                --l, --r;
                UF.merge(l, r, w);
            }
        }
    }    
}
