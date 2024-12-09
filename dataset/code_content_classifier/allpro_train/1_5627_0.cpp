#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

using P = array<int, 2>;
const int INF = TEN(9)+TEN(8);

struct Node {
    using NP = Node*;

    P mi;

    /*
     init_node, update, push
    */
    void init_node() {
        mi = P{INF, -1};
    }
    void update() {
        mi = min(l->mi, r->mi);
    }

    void set(int k, P x) {
        if (sz == 1) {
            mi = x;
            return;
        }
        if (k < sz/2) {
            l->set(k, x);
        } else {
            r->set(k-sz/2, x);
        }
        update();
    }
    P get(int a, int b) {
        if (b <= 0 or sz <= a) return P{INF, -1};
        if (a <= 0 and sz <= b) {
            return mi;
        }
        return min(l->get(a, b), r->get(a-sz/2, b-sz/2));
    }

    NP l, r;
    int sz;
    Node(int sz) : sz(sz) {
        init_node();
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz - sz/2);
        update();
    }
};



/**
 * SCC
 */
template<int N>
struct SCC {
    int n;
    vector<P> v;
    int C;
    using Q = pair<P, int>;
    Node* tr;
    vector<int> xv;
    int geti(int x) {
        return lower_bound(xv.begin(), xv.end(), x) - xv.begin();
    }
    SCC(vector<P> v, int C) : n((int)v.size()), v(v), C(C) {
        for (int i = 0; i < n; i++) {
            xv.push_back(v[i][0]);
        }
        tr = new Node(n);
    }
    void trinit(bool f) {
        for (int i = 0; i < n; i++) {
            if (f == false) {
                tr->set(i, P{v[i][1], i});
            } else {
                tr->set(i, P{-v[i][1], i});                
            }
        }
    }
    vector<int> vs;
    bool used[N];
    void dfs(int p) {
        used[p] = true;
        int i = p;
        while (true) {
            auto q = tr->get(geti(-INF), geti(v[i][0]-C));
            if (q[0] == INF) break;
            int j = q[1];
            tr->set(j, P{INF, -1});
            if (used[j]) continue;
            dfs(j);
        }
        while (true) {
            auto q = tr->get(geti(v[i][0]-C), geti(v[i][0]+C+1));
            if (v[i][1] <= q[0]) break;
            int j = q[1];
            tr->set(j, P{INF, -1});
            if (used[j]) continue;
            dfs(j);
        }
        vs.push_back(p);
    }
    int res[N]; /// res[i] = ??????i????±????????????£????????????ID
    vector<int> scc[N]; /// scc[i] = i??????????????£?????????????±?????????????
    void rdfs(int p, int k) {
        used[p] = true;
        res[p] = k; scc[k].push_back(p);
        int i = p;
        while (true) {
            auto q = tr->get(geti(v[i][0]+C+1), geti(INF));
            if (q[0] == INF) break;
            int j = q[1];
            tr->set(j, P{INF, -1});
            if (used[j]) continue;
            rdfs(j, k);
        }
        while (true) {
            auto q = tr->get(geti(v[i][0]-C), geti(v[i][0]+C+1));
            if (-q[0] <= v[i][1]) break;
            int j = q[1];
            tr->set(j, P{INF, -1});
            if (used[j]) continue;
            rdfs(j, k);
        }        
    }

    int exec(int n) {
        fill_n(used, n, false);
        trinit(false);
        for (int i = 0; i < n; i++) {
            if (!used[i]) dfs(i);
        }
        fill_n(used, n, false);
        trinit(true);
        int k = 0;
        for (int i = vs.size()-1; i >= 0; i--) {
            if (!used[vs[i]]) rdfs(vs[i], k++);
        }
        return k;
    }
};


const int MN = 50500;
int solve(vector<P> v, int C) {
    sort(v.begin(), v.end(), [&](const P &l, const P &r){
        return l[0] < r[0];
    });
    int n = (int)v.size();



    SCC<MN> scc(v, C);
    int gc = scc.exec(n);




    int ma[gc];
    fill_n(ma, gc, 0);
    map<int, vector<int>> mp;
    map<P, int> p2id;
    for (int i = 0; i < n; i++) {
        mp[v[i][1]].push_back(v[i][0]);
        p2id[v[i]] = i;
    }
    for (auto &p: mp) {
        sort(p.second.begin(), p.second.end());
    }
    for (int i = 0; i < n; i++) {
        int x = *(--upper_bound(mp[v[i][1]].begin(), mp[v[i][1]].end(), v[i][0]+C));
        int id = p2id[P{x, v[i][1]}];
        ma[scc.res[i]] = max(ma[scc.res[i]], scc.res[id]);
    }

    int l = 0;
    int ans = 0;
    for (int i = gc-1; i >= l; i--) {
        ans += (int)scc.scc[i].size();
        l = max(l, ma[i]);
    }
    return ans;
}


int main2() {
    int n, c;
    cin >> n >> c;
    vector<P> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(P{x, y});
    }
    cout << solve(v, c) << endl;

    return 0;
}

/*stack size???????????????*/
int main() {
    static ll eord, enew;
    const int sz = 256*1024*1024;
    static unsigned char *p = (unsigned char*)malloc(sz);
    enew = ((ll)(p+sz-1) & ~0xff);
    __asm__ volatile("mov %%rsp, %0" : "=r"(eord));
    __asm__ volatile("mov %0, %%rsp" : : "r"(enew));
    main2();
    __asm__ volatile("mov %0, %%rsp" : : "r"(eord));
    return 0;
}