#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

class Stack {
private:
    const int N, H;
    vector<int> node;
public:
    Stack(const int _N, const int _H) : N(_N), H(_H), node(N+H){ clear(); }
    inline bool empty(const int h){ return node[N+h] == N+h; }
    inline int top(const int h){ return node[N+h]; }
    inline void pop(const int h){ node[N+h] = node[node[N+h]]; }
    inline void push(const int h, const int u){ node[u] = node[N+h], node[N+h] = u; }
    inline void clear(){ iota(node.begin() + N, node.end(), N); }
};

class List
{
public:
    struct node {
        int prev, next;
    };
    const int N, H;
    vector<size_t> sz;
    vector<node> dat;
    List(const int _N, const int _H) : N(_N), H(_H), sz(H, 0), dat(N+H){ clear(); }
    inline size_t size(const int h) const { return sz[h]; }
    inline bool empty(const int h) const { return (sz[h] == 0); }
    inline void insert(const int h, const int u){
        ++sz[h];
        dat[u].prev = dat[N+h].prev, dat[u].next = N+h;
        dat[dat[N+h].prev].next = u, dat[N+h].prev = u;
    }
    inline void erase(const int h, const int u){
        --sz[h];
        dat[dat[u].prev].next = dat[u].next, dat[dat[u].next].prev = dat[u].prev;
    }
    inline void clear(){
        for(int i = N; i < N+H; ++i) dat[i].prev = dat[i].next = i;
    }
};

template <typename T> class PushRelabel
{
public:
    struct edge {
        int to, rev;
        T cap;
        edge(int _to, int _rev, T _cap) : to(_to), rev(_rev), cap(_cap){}
    };
private:
    const int V;
    int s, t, pot_max, checker;
    vector<T> excess;
    vector<int> potential, cur_edge, que;
    List all_ver;
    Stack act_ver;
    int calc_active(){
        pot_max = -1;
        for(int i = 0; i < V; ++i){
            if(potential[i] < V){
                cur_edge[i] = 0;
                pot_max = max(potential[i], pot_max);
                all_ver.insert(potential[i], i);
                if(excess[i] > 0 && i != t) act_ver.push(potential[i], i);
            }else{
                potential[i] = V+1;
            }
        }
        return pot_max;
    }
    void bfs(){
        for(int i = 0; i < V; ++i) potential[i] = max(potential[i], V);
        potential[t] = 0;
        int qh = 0, qt = 0;
        for(que[qt++] = t; qh++ < qt;){
            int u = que[qh-1];
            for(edge& e : G[u]){
                if(potential[e.to] == V && G[e.to][e.rev].cap > 0){
                    potential[e.to] = potential[u] + 1, que[qt++] = e.to;
                }
            }
        }
    }
    int init(){
        potential[s] = V+1;
        bfs();
        for(edge& e : G[s]){
            if(potential[e.to] < V){
                G[e.to][e.rev].cap = e.cap, excess[s] -= e.cap, excess[e.to] += e.cap;
            }
            e.cap = 0;
        }
        return calc_active();
    }
    int global_relabel(){
        bfs();
        all_ver.clear(), act_ver.clear();
        return calc_active();
    }
    void gap_relabel(const int u){
        for(int i = potential[u]; i <= pot_max; ++i){
            for(int id = all_ver.dat[V+i].next; id < V; id = all_ver.dat[id].next){
                potential[id] = V+1;
            }
            all_ver.sz[i] = 0;
            all_ver.dat[V+i].prev = all_ver.dat[V+i].next = V+i;
        }
    }
    int discharge(const int u){
        for(int& i = cur_edge[u]; i < (int)G[u].size(); ++i){
            edge& e = G[u][i];
            if(potential[u] == potential[e.to] + 1 && e.cap > 0){
                if(push(u, e)) return potential[u];
            }
        }
        return relabel(u);
    }
    bool push(const int u, edge& e){
        T f = min(e.cap, excess[u]);
        const int v = e.to;
        e.cap -= f, excess[u] -= f;
        G[v][e.rev].cap += f, excess[v] += f;
        if(excess[v] == f && v != t) act_ver.push(potential[v], v);
        return (excess[u] == 0);
    }
    int relabel(const int u){
        ++checker;
        int prv = potential[u], cur = V;
        for(int i = 0; i < (int)G[u].size(); ++i){
            edge& e = G[u][i];
            if(cur > potential[e.to] + 1 && e.cap > 0){
                cur_edge[u] = i;
                cur = potential[e.to] + 1;
            }
        }
        if((int)all_ver.size(prv) > 1){
            all_ver.erase(prv, u);
            if((potential[u] = cur) == V) return potential[u] = V+1, prv;
            act_ver.push(cur, u);
            all_ver.insert(cur, u);
            pot_max = max(pot_max, cur);
        }else{
            gap_relabel(u);
            return pot_max = prv - 1;
        }
        return cur;
    }
public:
    vector<vector<edge> > G;
    T cap_sum;
    PushRelabel(const int node_size)
        : V(node_size + 2), pot_max(-1), checker(0), excess(V, (T)0),
            potential(V), cur_edge(V), que(V), all_ver(V, V), act_ver(V, V), G(V), cap_sum((T)0){}
    void add_edge(const int _from, const int _to, const T _cap){
        G[_from].emplace_back(_to, (int)G[_to].size(), _cap);
        G[_to].emplace_back(_from, (int)G[_from].size() - 1, 0);
    }
    void add_edge(int from, int to, T min_cap, T max_cap){
        cap_sum += min_cap;
        add_edge(from,to,max_cap-min_cap);
        if(min_cap){
            add_edge(V-2,to,min_cap);
            add_edge(from,V-1,min_cap);
        }
    }
    bool check(int s, int t){
        add_edge(t,s,numeric_limits<T>::max() / 10);
        T res = solve(V-2, V-1);
        return (res >= cap_sum);
    }
    //最大流を計算
    T max_flow(int s, int t){
        add_edge(V-2,s,numeric_limits<T>::max() / 10);
        add_edge(t,V-1,numeric_limits<T>::max() / 10);
        return solve(V-2, V-1) - cap_sum;
    }
    T solve(const int source, const int sink){
        s = source, t = sink;
        int level = init();
        while(level >= 0){
            if(act_ver.empty(level)){
                --level;
                continue;
            }
            int u = act_ver.top(level);
            act_ver.pop(level);
            if(excess[u] == 0) continue;
            level = discharge(u);
            if(checker >= V / 2){
                level = global_relabel();
                checker = 0;
            }
        }
        return excess[t];
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(1){
        int n,m;
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        vp vec(m);
        rep(i,m){
            cin >> vec[i].fi >> vec[i].se;
        }
        int ans = m+1;
        int l=-1,r=-1;
        int max_cap = m;
        rrep(i,m/n+1){
            while(max_cap >= i){
                PushRelabel<int> dn(m+n+2);
                rep(j,m){
                    dn.add_edge(0,j+1,1,1);
                }
                rep(j,m){
                    dn.add_edge(j+1,m+vec[j].fi,0,1);
                    dn.add_edge(j+1,m+vec[j].se,0,1);
                }
                rep(k,n){
                    dn.add_edge(m+k+1,m+n+1,i,max_cap);
                }
                if(dn.check(0,m+n+1)){
                    if(ans >= max_cap - i){
                        ans = max_cap - i;
                        l = i, r = max_cap;
                    }
                    max_cap--;
                }else{
                    break;
                }
            }
        }
        cout << l << " " << r << "\n";
    }
    return 0;
}

