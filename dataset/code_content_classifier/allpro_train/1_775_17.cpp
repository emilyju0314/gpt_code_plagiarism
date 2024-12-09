#include <bits/stdc++.h>
using namespace std;
//#define DEBUG_MODE
#define endl '\n'
#ifdef DEBUG_MODE
#define DEBUG(X) debug_func(X, #X)
#define DEBUG_ENDL endl
#define DEBUG_SEPARATOR_LINE cout<<"=================\n"
#else
#define DEBUG(X) 0
#define DEBUG_ENDL 0
#define DEBUG_SEPARATOR_LINE 0
#endif
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()
#define DEBUG_ENDL_S(S) ((S).size() ? "\n" : "")
template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;
template <typename T, typename U> using P = pair<T, U>;
using ll = int64_t;
using PLL = P<ll, ll>;
template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename Head, typename... Tail> const Head& var_min(const Head &head, const Tail&... tail) { return min(head, var_min(tail...)); }
template <typename Head, typename... Tail> const Head& var_max(const Head &head, const Tail&... tail) { return max(head, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }
void debug_func_preffix(const string &s) { if(s.size()) cout << s << " = "; }
template <typename T>
void debug_func(const T &t, const string &s = "") {
    debug_func_preffix(s);
    cout << t << DEBUG_ENDL_S(s);
}
template <typename T, typename U>
void debug_func(const P<T, U> &p, const string &s = "") {
    debug_func_preffix(s);
    cout << "(";
    debug_func(p.first);
    cout << ", ";
    debug_func(p.second);
    cout << ")" << DEBUG_ENDL_S(s);
}
template <typename T>
void debug_func(const V<T> &v, const string &s = "") {
    for(ll i = 0; i < v.size(); i++) {
        string t = s + "[" + to_string(i) + "]";
        debug_func(v[i], t);
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    V<ll> mv(M);
    for(ll &e : mv) cin >> e;
    ll initl = mv[0] - 1;
    mv.push_back(N + 1);
    V<ll> dist;
    for(ll i = 0; i + 1 < mv.size(); i++) dist.push_back(mv[i + 1] - mv[i] - 1);
    sort(ALL(dist));
    DEBUG(dist);
    V<ll> dsum(M + 1);
    for(ll i = 0; i + 1 < dsum.size(); i++) dsum[i + 1] = dsum[i] + dist[i];
    DEBUG(dsum);
    ll Q;
    cin >> Q;
    for(ll QQ = 0; QQ < Q; QQ++) {
        ll L;
        cin >> L;
        ll ok = 1e9, ng = 0;
        bool suc = 0;
        while(ok - ng > 1) {
            ll mid = (ok + ng) / 2;
            auto ite = lower_bound(ALL(dist), mid);
            ll idx = distance(dist.begin(), ite);
            ll cnt = distance(ite, dist.end());
            ll rdsum = dsum[M] - dsum[idx];
            ll loss = rdsum - cnt * (mid - 1);
            DEBUG(mid);
            DEBUG(idx);
            DEBUG(cnt);
            DEBUG(rdsum);
            DEBUG(loss);
            loss += initl;
            if(loss <= L) {
                ok = mid;
                suc = true;
            } else {
                ng = mid;
            }
        }
        cout << (suc ? ok : -1) << endl;
    }
    return 0;
}

