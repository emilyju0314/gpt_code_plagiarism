#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> sz;

    UnionFind(int n=0){
        if(n>0) initialize(n);
    }

    void initialize(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0; i<n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }

    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(sz[x] > sz[y]) swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
        return true;
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    int size(int x){
        return sz[find(x)];
    }
};

struct Dinic{
    struct edge {
        int64_t to, cap, rev;
        edge(int64_t to, int64_t cap, int64_t rev):to(to), cap(cap), rev(rev){}
    };

    int N, S, T;
    int64_t flow = 0;
    const int64_t INF = 1e18;
    vector<int> level, iter;
    vector<vector<edge>> G;

    Dinic(int N, int S, int T):N(N), S(S), T(T){
        flow = 0;
        level.resize(N);
        iter.resize(N);
        G.resize(N);
    }

    void add_edge(int from, int to, int64_t cap){
        G[from].emplace_back(to, cap, G[to].size());
        G[to].emplace_back(from, 0, G[from].size()-1);
    }

    void bfs(int s){
        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(que.size()){
            int v = que.front(); que.pop();
            for(auto& e : G[v]){
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    int64_t dfs(int v, int t, int64_t f){
        if(v == t) return f;
        for(int& i=iter[v]; i<G[v].size(); i++){
            auto& e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                int64_t d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int64_t max_flow(){
        while(true){
            bfs(S);
            if(level[T] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            while(true){
                int64_t f = dfs(S, T, INF);
                if(f == 0) break;
                flow += f;
            }
        }
    }
};

int main(){
    int N, M, X[1000], Y[1000];
    cin >> N >> M;
    int S = 2001, T = 2002;
    Dinic solver(T+1, S, T);
    for(int i=1; i<=1000; i++){
        solver.add_edge(S, i, 1);
        solver.add_edge(1000+i, T, 1);
    }

    for(int i=0; i<M; i++){
        cin >> X[i] >> Y[i];
        solver.add_edge(X[i], 1000+Y[i], 1);
    }
    UnionFind uf(M);
    for(int i=0; i<M; i++) for(int j=0; j<M; j++) if(X[i] == X[j] || Y[i] == Y[j]) uf.unite(i, j);
    int ans1 = 0, ans2 = solver.max_flow();
    for(int i=0; i<M; i++) if(uf.find(i) == i) ans1++;
    cout << M-ans2 << " " << M-ans1 << endl;
    return 0;
}

