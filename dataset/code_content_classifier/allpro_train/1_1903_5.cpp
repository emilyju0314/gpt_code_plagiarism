#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

template<typename T>
struct Max_Flow{
    struct edge{
        int to; T cap; int rev;
        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    vector<vector<edge>> es;
    vector<bool> used;
    const T INF_T;

    Max_Flow(int n) : INF_T(numeric_limits<T>::max()){
        es.resize(n), used.resize(n);
    }

    void add_edge(int from, int to, T cap, bool directed = true){
        es[from].eb(to, cap, sz(es[to]));
        es[to].eb(from, directed? 0 : cap, sz(es[from])-1);
    }

    T dfs(int now, int t, T flow){
        if(now == t) return flow;
        used[now] = true;
        for(auto &e: es[now]){
            if(!used[e.to] && e.cap > 0){
                T f = dfs(e.to, t, min(flow, e.cap));
                if(f > 0){
                    e.cap -= f;
                    es[e.to][e.rev].cap += f;
                    return f;
                }
            }
        }
        return 0;
    }

    T max_flow(int s, int t){
        T flow = 0;
        for(;;){
            fill(all(used), false);
            T f = dfs(s, t, INF_T);
            if(f == 0) return flow;
            flow += f;
        }
    }
};

int main(){
    int H, W;
    cin >> H >> W;
    int N = H*W;
    string S[H];
    rep(i, H) cin >> S[i];
    Max_Flow<int> G(3*N+2);
    int s = 3*N, t = 3*N+1;
    int sum = 0;
    rep(i, H){
        rep(j, W){
            if(S[i][j] == '.') continue;
            int p = W*i+j;
            G.add_edge(s, p, 1), G.add_edge(p, t, 1);
            int ni = i+1, nj = j+1;
            if(ni < H && S[ni][j] == '#'){
                int np = W*ni+j;
                sum--;
                G.add_edge(s, N+p, 1);
                G.add_edge(N+p, p, inf), G.add_edge(N+p, np, inf);
            }
            if(nj < W && S[i][nj] == '#'){
                int np = W*i+nj;
                sum--;
                G.add_edge(2*N+p, t, 1);
                G.add_edge(p, 2*N+p, inf), G.add_edge(np, 2*N+p, inf);
            }
        }
    }
    cout << sum+G.max_flow(s, t) << endl;
}
