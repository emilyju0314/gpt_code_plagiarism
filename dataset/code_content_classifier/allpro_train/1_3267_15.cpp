#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;

const int nax = 1e6 + 5;
vector<pair<int,int>> edges[nax];
int mod;
bool visited[nax];
pair<int,int> pre[nax], inv[nax];

int add(int a, int b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
    return a;
}
int twice(int a) {
    return add(a, a);
}
int mul(int a, int b) {
    // return b == 2 ? twice(a) : (ll) a * b % mod;
    return (ll) a * b % mod;
}

vector<pair<int,int>> cycles;

pair<int,int> f(const pair<int,int>& a, const pair<int,int>& b) {
    return make_pair(
        mul(a.first, b.first),
        add(mul(a.second, b.first), b.second)
    );
}
int f2(int a, const pair<int,int>& b) {
    return add(mul(a, b.first), b.second);
}

void dfs(int a) {
    assert(!visited[a]);
    visited[a] = true;
    // debug() << imie(a) imie(pre[a]) imie(inv[a]);
    for(pair<int,int> edge : edges[a]) {
        int b = edge.first;
        int len = edge.second;
        // 4x+3 -> 2*(4x+3)+len
        pair<int,int> tmp_pre = f(pre[a], make_pair(2, len)); //{twice(pre[a].first), add(twice(pre[a].second), len)};
        pair<int,int> tmp_inv = f(make_pair(2, len), inv[a]); //{twice(inv[a].first), add(inv[a].second, mul(len, inv[a].first))};
        // debug() << imie(a) imie(b) imie(len) imie(tmp_pre) imie(tmp_inv);
        if(visited[b]) {
            cycles.push_back(f(tmp_pre, inv[b]));
                // mul(tmp_pre.first, inv[b].first),
                // add(mul(tmp_pre.second, inv[b].first), inv[b].second)
            // );
            cycles.push_back(f(pre[b], tmp_inv));
                // mul(tmp_inv.first, pre[b].first),
                // add(tmp_inv.second, mul(pre[b].second, tmp_inv.first))
            // );
        }
        else {
            pre[b] = tmp_pre;
            inv[b] = tmp_inv;
            dfs(b);
        }
    }
}

int main() {
	int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    scanf("%d", &mod);
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[a].emplace_back(b, c);
        if(a != b) {
            edges[b].emplace_back(a, c);
        }
    }
    pre[1] = inv[1] = {1, 0};
    dfs(1);
    // debug() << imie(cycles);
    sort(cycles.begin(), cycles.end());
    cycles.resize( unique(cycles.begin(), cycles.end()) - cycles.begin() );
    debug() << imie(cycles);
    vector<int> twos{1};
    for(int x = 2; x != 1; x = twice(x)) {
        twos.push_back(x);
    }
    // debug() << imie(twos);
    vector<int> my_inv(mod);
    my_inv[1] = 1;
    for(int i = 1; i < (int) twos.size(); ++i) {
        my_inv[twos[i]] = twos[(int)twos.size()-i];
        assert(mul(twos[i], my_inv[twos[i]]) == 1);
    }
    
    
    
    vector<int> g(mod);
    vector<vector<int>> g_inv(mod);
    for(int i = 0; i < mod; ++i) {
        g[i] = i;
        g_inv[i] = {i};
    }
    auto uni = [&](int a, int b) {
        a = g[a];
        b = g[b];
        assert(a != b);
        if(g_inv[a].size() > g_inv[b].size()) {
            swap(a, b);
        }
        for(int x : g_inv[a]) {
            g_inv[b].push_back(x);
            g[x] = b;
        }
        g_inv[a].clear();
    };
    
    int UP = 1000;
    UP *= 1000 * 1000 / max(mod, 10 * 1000);
    UP *= 100 * 1000 / max(1000, (int) cycles.size());
    // if(mod <= 500 * 1000) {
        // UP *= 2;
    // }
    // if(max(n, m) <= 25 * 1000) {
        // UP *= 2;
    // }
    srand(69);
    random_shuffle(cycles.begin(), cycles.end());
    // vector<int> order;
    // for(int i = 0; i < mod; ++i) {
        // order.push_back(i);
    // }
    // random_shuffle(order.begin(), order.end());
    for(pair<int,int> cycle : cycles) {
        int nothing = 0;
        vector<int> wait;
        // for(int i = 0; i < mod; ++i) {
            // int x = order[i];
        for(int x = 0; x < mod; ++x) {
            ++nothing;
            int y = ((ll) cycle.first * x + cycle.second) % mod;
            if(g[x] != g[y]) {
                uni(x, y);
                nothing = 0;
                wait.push_back(y);
            }
            if(nothing >= UP) {
                break;
            }
        }
        for(int i = 0; i < (int) wait.size(); ++i) {
            int x = wait[i];
            while(true) {
                int y = ((ll) cycle.first * x + cycle.second) % mod;
                if(g[x] != g[y]) {
                    uni(x, y);
                    x = y;
                }
                else {
                    break;
                }
            }
        }
    }
    
    // for(int already = 0; already < mod; ++already) {
        // vector<int> kol{already};
        // set<int> vis{already};
        // for(int i = 0; i < (int) kol.size(); ++i) {
            // for(pair<int,int> cycle : cycles) {
                // int maybe = f2(kol[i], cycle);
                // if(vis.insert(maybe).second) {
                    // kol.push_back(maybe);
                // }
            // }
        // }
        // debug() << imie(already) imie(vis);
    // }
    
    while(q--) {
        int a, b, goal;
        scanf("%d%d%d", &a, &b, &goal);
        goal -= pre[a].second;
        if(goal < 0) {
            goal += mod;
        }
        // x * pre[a].first = goal
        goal = mul(goal, my_inv[pre[a].first]);
        int already = inv[b].second;
        
        // already --> goal ?
        puts(g[already] == g[goal] ? "YES" : "NO");
        
        // vector<int> kol{already};
        // set<int> vis{already};
        // bool answer = false;
        // for(int i = 0; i < (int) kol.size(); ++i) {
            // if(kol[i] == goal) {
                // answer = true;
                // break;
            // }
            // for(pair<int,int> cycle : cycles) {
                // int maybe = f2(kol[i], cycle);
                // if(maybe == goal) {
                    // answer = true;
                    // break;
                // }
                // if(vis.insert(maybe).second) {
                    // kol.push_back(maybe);
                // }
            // }
            // if(answer) {
                // break;
            // }
        // }
        // puts(answer ? "YES" : "NO");
    }
}
