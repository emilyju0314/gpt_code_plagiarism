#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, a, n) for(int i=(a);i < (n);i++)
#define REP(i, n) rep(i,0,n)
#define all(e) e.begin(),e.end()


#ifdef LOCAL
#define show(x) cerr<<__LINE__" : "<<#x<<" = "<<(x)<<endl
#else
#define show(x) true
#endif

using namespace std;
using ll = long long;
template<class T>
using V=vector<T>;

template<class T, class U>
void chmin(T &t, const U u) { if (t > u) t = u; }

template<class T, class U>
void chmax(T &t, const U u) { if (t < u) t = u; }

const int INF = (1 << 30) - 1;
const ll INFL = (ll) 5e15;
const int MOD = 1e9 + 7;

struct SCC {
    int V;
    vector<vector<int>> G;
    vector<vector<int>> rG;
    vector<vector<int>> vG;
    vector<int> vs;
    vector<bool> used;
    vector<int> cmp;

    vector<int> used2;

    SCC(int v) {
        V = v;
        G.resize(V);
        rG.resize(V);
        used.resize(V);
        cmp.resize(V);

        used2.resize(V);
    }


    void add_edge(int from, int to) {
        G[from].push_back(to);
        rG[to].push_back(from);
    }

    void dfs(int v) {
        used[v] = true;
        for (int i = 0; i < G[v].size(); ++i) {
            if (!used[G[v][i]]) dfs(G[v][i]);
        }
        vs.push_back(v);
    }

    void rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        vG[k].push_back(v);
        for (int i = 0; i < rG[v].size(); ++i) {
            if (!used[rG[v][i]]) rdfs(rG[v][i], k);
        }
    }

    int scc() {
        fill(used.begin(), used.end(), false);
        vs.clear();
        for (int v = 0; v < V; ++v) {
            if (!used[v]) dfs(v);
        }
        fill(used.begin(), used.end(), false);
        int k = 0;
        for (int i = (int) vs.size() - 1; i >= 0; i--) {
            vG.push_back(vector<int>());
            if (!used[vs[i]]) rdfs(vs[i], k++);
        }
        return k;
    }


};


struct Solve {
    int N;
    vector<double> P;
    vector<vector<int>> d;

    vector<bool> used;
    vector<bool> used2;
    vector<vector<int>> G;
    vector<vector<int>> rG;
    vector<int> cmp;

    void dfs(int v) {
        used[v] = true;
        for (int i = 0; i < G[v].size(); ++i) {
            if (!used[G[v][i]]) dfs(G[v][i]);
        }
    }

    void rdfs(int v) {
        used[v] = true;
        for (int i = 0; i < rG[v].size(); ++i) {
            if (!used[rG[v][i]]) rdfs(rG[v][i]);
        }

    }

    int rdfs2(int v) {
        int ret = cmp[v];
        used2[v] = true;
        for (int i = 0; i < rG[v].size(); ++i) {
            if (!used2[rG[v][i]]) chmin(ret, rdfs2(rG[v][i]));
        }

        return ret;
    }

    bool solve() {

        cin >> N;
        if (N == 0) return false;
        P.resize(N);
        d.resize(N, vector<int>(N, INF));
        for (int i = 0; i < N; ++i) {
            d[i][i] = 0;
        }

        SCC scc(N);

        for (int i = 0; i < N; ++i) {
            cin >> P[i];
            int m;
            cin >> m;
            int from = i;
            for (int j = 0; j < m; ++j) {
                int to;
                cin >> to;
                to--;
                scc.add_edge(from, to);
                d[from][to] = 1;
            }
        }


//        for (int k = 0; k < N; ++k) {
//            for (int i = 0; i < N; ++i) {
//                for (int j = 0; j < N; ++j) {
//                    chmin(d[i][j], d[i][k] + d[k][j]);
//                }
//            }
//        }
//        for (int i = 0; i < N; ++i) {
//            for (int j = 0; j < N; ++j) {
//                if (d[i][j] == INF) cerr << 1;
//                else cerr << 0;
//            }
//            cerr << endl;
//        }


//        used = scc.used;
//        used2 = scc.used;
//        G = scc.G;
//        rG = scc.rG;
        int k = scc.scc();

        double ans = 1.0;
        for (int i = 0; i < k; ++i) {
//            for (int j = 0; j < scc.vG[i]; ++j) {
//                bool flag = true;
//                for (auto e : scc.rG[vG[i][j]]) {
//
//                }
//
//            }
            double zekki = 1.0;
            bool flag = true;
            for (auto v : scc.vG[i]) {
                zekki *= P[v];
                for (auto w : scc.rG[v]) {
                    //scc.v : 普通のトポ順
                    //scc.cmp[w] : 元の辺のトポ順
                    if (scc.cmp[w] < scc.cmp[v]) {
                        flag = false;
                    }
                }
            }

            if (flag) {
                ans *= (1. - zekki);
            }
        }
        cout << ans << endl;
//        cmp = scc.cmp;
//        set<int> sentou;
//        vector<pair<int, int>> pp;
//        for (int i = 0; i < N; ++i) {
//            pp.emplace_back(scc.cmp[i], i);
//        }
//        sort(all(pp));
//        for (int i = 0; i < N; ++i) {
//            cerr << pp[i].first << " " << pp[i].second << endl;
//            if (i > 0) {
//                if (pp[i - 1].first != pp[i].first) {
//                    if (d[pp[i - 1].second][pp[i].second] == INF) {
//                        sentou.insert(pp[i].first);
//                    }
//                }
//            } else if (i == 0) {
//                sentou.insert(pp[i].first);
//            }
//        }
//
//        double ans = 1.0;
//        for (auto gr : sentou) {
//            cerr << gr << endl;
//
//            // cmp[i] == grとなるようなもの全て集める
//            double zekki = 1.0;
//
//            for (int i = 0; i < N; ++i) {
//                if (scc.cmp[i] == gr) {
//                    zekki *= P[i];
////                    cerr << P[i] << endl;
//                }
//            }
//            ans *= 1.0 - zekki;
//        }

//        double ans = 1.0;
//        set<int> usedg;
//        for (int i = 0; i < N; ++i) {
//            if (used[i]) continue;
//            //rdfsしてグループを求める
//            fill(used2.begin(), used2.end(), false);
//            int g = rdfs2(i);
////            cerr << i << " " << g << endl;
//            //dfsして使用済みにする
//            dfs(i);
//            rdfs(i);
//
//            double zekki = 1.0;
//            for (int j = 0; j < N; ++j) {
//                if (usedg.count(g) == 0) {
//                    if (scc.cmp[j] == g) {
//                        zekki *= P[j];
////                        cerr << j << " " << P[j] << endl;
//                    }
//                }
//            }
//            usedg.insert(g);
//            ans *= 1.0 - zekki;
//        }
//        cout << ans << endl;

//        for (int i = 0; i < N; ++i) {
//            cout << scc.cmp[i] << endl;
//        }

        return true;
    }


};


int main() {
    cout << setprecision(9) << fixed;

    while (Solve().solve());

//    SCC scc(5);
//    scc.add_edge(0, 1);
//    scc.add_edge(1, 0);
//    scc.add_edge(1, 2);
//    scc.add_edge(2, 3);
//    scc.scc();
//
//    for (int i = 0; i < 5; ++i) {
//        cout << scc.cmp[i] << endl;
//    }

//    int N;
//    cin >> N;
//    SCC scc(N);
//    for (int i = 0; i < N; ++i) {
//        double uku;
//        cin >> uku;
//        int m;
//        cin >> m;
//        for (int j = 0; j < m; ++j) {
//            int tmp;
//            cin >> tmp;
//            tmp--;
//            scc.add_edge(i, tmp);
//        }
//    }

//    scc.scc();
//
//    for (int i = 0; i < N; ++i) {
//        cout << scc.cmp[i] << endl;
//    }

    return 0;
}

