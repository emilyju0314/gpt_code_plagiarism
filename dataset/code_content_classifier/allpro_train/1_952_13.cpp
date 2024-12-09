#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// edge class (for network-flow)
template<class FLOWTYPE> struct Edge {
    int rev, from, to;
    FLOWTYPE cap, icap;
    Edge(int r, int f, int t, FLOWTYPE c) : rev(r), from(f), to(t), cap(c), icap(c) {}
};

// graph class (for network-flow)
template<class FLOWTYPE> struct Graph {
    vector<vector<Edge<FLOWTYPE> > > list;
    
    Graph(int n = 0) : list(n) { }
    void init(int n = 0) { list.clear(); list.resize(n); }
    void reset() { for (int i = 0; i < (int)list.size(); ++i) for (int j = 0; j < list[i].size(); ++j) list[i][j].cap = list[i][j].icap; }
    inline vector<Edge<FLOWTYPE> >& operator [] (int i) { return list[i]; }
    inline const size_t size() const { return list.size(); }
    
    inline Edge<FLOWTYPE> &redge(Edge<FLOWTYPE> e) {
        if (e.from != e.to) return list[e.to][e.rev];
        else return list[e.to][e.rev + 1];
    }
    
    void addedge(int from, int to, FLOWTYPE cap) {
        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from, to, cap));
        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size() - 1, to, from, 0));
    }
    
    void add_undirected_edge(int from, int to, FLOWTYPE cap) {
        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from, to, cap));
        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size() - 1, to, from, cap));
    }
};

template<class FLOWTYPE> struct Dinic {
    const FLOWTYPE INF = 1LL<<59; // to be set
    vector<int> level, iter;

    Dinic() { }
    void dibfs(Graph<FLOWTYPE> &G, int s) {
        level.assign((int)G.size(), -1);
        level[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < G[v].size(); ++i) {
                Edge<FLOWTYPE> &e = G[v][i];
                if (level[e.to] < 0 && e.cap > 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    
    FLOWTYPE didfs(Graph<FLOWTYPE> &G, int v, int t, FLOWTYPE f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < G[v].size(); ++i) {
            Edge<FLOWTYPE> &e = G[v][i], &re = G.redge(e);
            if (level[v] < level[e.to] && e.cap > 0) {
                FLOWTYPE d = didfs(G, e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    re.cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    FLOWTYPE solve(Graph<FLOWTYPE> &G, int s, int t) {
        level.assign((int)G.size(), -1); iter.assign((int)G.size(), 0);
        FLOWTYPE res = 0;
        while (true) {
            dibfs(G, s);
            if (level[t] < 0) return res;
            for (int i = 0; i < (int)iter.size(); ++i) iter[i] = 0;
            FLOWTYPE flow = 0;
            while ((flow = didfs(G, s, t, INF)) > 0) {
                res += flow;
            }
        }
    }
};

using pint = pair<int,int>;

long long N, M, W;
long long B[110][110];

map<pint,int> ma; // (i, j) -> 装置 ID

// (i, j) にある装置の四隅の電球の利得 
long long calc(int i, int j) {
    long long res = 0;
    for (int di = 0; di < 2; ++di) {
        for (int dj = 0; dj < 2; ++dj) {
            res += B[i+di][j+dj];
        }
    }
    return res;
}

int main() {
    cin >> N >> M >> W;
    ma.clear();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> B[i][j];
            if ( i+1 < N && j+1 < M && (i + j) % 2 == 0 ) 
                ma[pint(i, j)] = 0;            
        }
    }
    int iter = 0;
    for (auto &it : ma) it.second = iter++;
  
    // グラフを作る
    Graph<long long> G(ma.size() + 2);
    int s = ma.size(), t = s + 1;      
    for (int i = 0; i < N-1; ++i) {
        for (int j = 0; j < M-1; ++j) {
            if (!ma.count(pint(i, j))) continue;
            int id = ma[pint(i, j)];
            
            if (i % 2 == 0) { // 正規の装置
                G.addedge(s, id, calc(i, j));
                G.addedge(id, t, W);
            }
            else { // 反転した装置 
                G.addedge(s, id, W);
                G.addedge(id, t, calc(i, j));
            }
            
            // 正規から反転へとペナルティ辺をはる
            if (i % 2 == 0) {
                for (int di = -1; di <= 1; di += 2) {
                    for (int dj = -1; dj <= 1; dj += 2) {
                        int ni = i + di, nj = j + dj;
                        if (!ma.count(pint(ni, nj))) continue;
                        int id2 = ma[pint(ni, nj)];
                        int bi = i + (di == -1 ? 0 : 1);
                        int bj = j + (dj == -1 ? 0 : 1);
                        G.addedge(id, id2, B[bi][bj]);
                    }
                }
            }
        }
    }

    Dinic<long long> din;
    long long res = din.solve(G, s, t);

    long long all = 0;
    for (auto it : ma) all += calc(it.first.first, it.first.second);
    cout << all - res << endl;
}

