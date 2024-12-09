#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(a)-1;i>=b;i--)
#define chmin(a,b) (a)=min((a),(b));
#define chmax(a,b) (a)=max((a),(b));
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(v) cerr<<(#v)<<":";for(auto(x):(v)){cerr<<" "<<(x);}cerr<<endl;
#define printVS(vs) cerr<<(#vs)<<":"<<endl;for(auto(s):(vs)){cerr<<(s)<< endl;}
#define printVV(vv) cerr<<(#vv)<<":"<<endl;for(auto(v):(vv)){for(auto(x):(v)){cerr<<" "<<(x);}cerr<<endl;}
#define printP(p) cerr<<(#p)<<(p).first<<" "<<(p).second<<endl;
#define printVP(vp) cerr<<(#vp)<<":"<<endl;for(auto(p):(vp)){cerr<<(p).first<<" "<<(p).second<<endl;}

inline void output(){ cerr << endl; }
template<typename First, typename... Rest>
inline void output(const First& first, const Rest&... rest) {
    cerr << first << " "; output(rest...);
}

using ll = long long;
using Pii = pair<int, int>;
using TUPLE = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const int inf = 1ll << 60;
const int mod = 1e9 + 7;
using Graph = vector<vector<int>>;

class UnionFind {
private:
    const int n;
    vector<int> uni;
public:
    UnionFind(int _n) : n(_n), uni(_n, -1) {}
    int root(int x) {
        if (uni[x] < 0) return x;
        return uni[x] = root(uni[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (uni[x] > uni[y]) swap(x, y);
        uni[x] += uni[y];
        uni[y] = x;
        return true;
    }
    void print() {
        for (auto x : uni) cout << x << " ";
        cout << endl;
    }
};

struct edge {
    int from, to;
    double cost;
    edge(){}
    edge(int _from, int _to, double _cost) : from(_from), to(_to), cost(_cost) {}
    bool operator< (const edge& e) const {
        return cost == e.cost ? (from == e.from ? to < e.to : from < e.from) : cost < e.cost;
    }
};

class Kruskal {
private:
    int n;
    vector<edge> edges;
    UnionFind uf;
public:
    Kruskal(int _n) : n(_n), uf(_n) {}
    void addEdge(int _from, int _to, double _cost) {
        edges.emplace_back(_from, _to, _cost);
    }
    double calc() {
        sort(all(edges));
        reverse(all(edges));
        double res = 0.;
        vector<edge> selected_edges;
        rep(i, edges.size()) {
            if (uf.unite(edges[i].from, edges[i].to)) {
                res += edges[i].cost;
                selected_edges.emplace_back(edges[i]);
            }
        }
        // return make_pair(res, selected_edges);
        return res;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    cin >> n >> m;
    vi a(m), b(m);
    vector<double> c(m), d(m);
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    if (m == n - 1) {
        cout << 0 << endl;
        return 0;
    }

    auto check = [&](double x) {
        Kruskal kr(n);
        double whole = 0.;
        rep(i, m) {
            double cost = d[i] - x * c[i];
            kr.addEdge(a[i], b[i], cost);
            whole += cost;
        }
        return kr.calc() >= whole;
    };

    double lb = 0., ub = 1e20;
    rep(_, 100) {
        double mid = (lb + ub) / 2.;
        (check(mid) ? ub : lb) = mid;
    }

    cout << fixed << setprecision(10) << ub << endl;
}