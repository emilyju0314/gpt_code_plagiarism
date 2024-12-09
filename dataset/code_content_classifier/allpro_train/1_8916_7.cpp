#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }


// edge class (for network-flow)
template<class FLOWTYPE> struct Edge {
    int rev, from, to;
    FLOWTYPE cap, icap;
    Edge(int r, int f, int t, FLOWTYPE c) : rev(r), from(f), to(t), cap(c), icap(c) {}
    friend ostream& operator << (ostream& s, const Edge& E) {
        if (E.cap > 0) return s << E.from << "->" << E.to << '(' << E.cap << ')';
        else return s;
    }
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

    /* 
    // debug
    friend ostream& operator << (ostream& s, const Graph& G) {
        s << endl; for (int i = 0; i < G.V; ++i) { s << i << " : " << G.list[i] << endl; }return s;
    }
    */
};

template<class FLOWTYPE> struct Dinic {
    const FLOWTYPE INF = 1<<30; // to be set
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



int main() {
    int N, M;
    string U;
    while (cin >> N >> M >> U) {
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        Graph<long long> G(N+2);
        int s = N, t = N+1;
        for (int i = 0; i < N; ++i) {
            if (U[i] == 'R') {
                G.addedge(s, i, A[i]);
                G.addedge(i, t, 0);
            }
            else {
                G.addedge(s, i, 0);
                G.addedge(i, t, A[i]);
            }
        }
        for (int _ = 0; _ < M; ++_) {
            int a, b; long long c;
            cin >> a >> b >> c;
            --a, --b;
            if (a > b) swap(a, b);
            G.addedge(a, b, c);
        }

        Dinic<long long> din;
        long long res = din.solve(G, s, t);
        cout << res << endl;
    }
}














