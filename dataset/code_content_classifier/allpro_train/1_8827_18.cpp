// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;

int N, dpc[210][210], dpn[210][210];
vector<int> G[210];

vector<int> merge(vector<int> A, vector<int> B, int cur, int nxt) {
    vector<int> res((int)A.size() + (int)B.size() - 1);
    dpc[0][0] = 1;
    for(size_t i=0; i<A.size(); i++) {
        for(size_t j=0; j<B.size(); j++) {
            for(size_t k=0; k<=j; k++) {
                {
                    (dpc[j+1][k  ] += dpc[j][k]) %= MOD; // 被らせず置く
                    (dpn[j+1][k+1] += dpc[j][k]) %= MOD; // 被らせて進む
                    (dpn[j  ][k  ] += dpc[j][k]) %= MOD; // そのまま進む
                }

                // マージ (i 個の要素 A と j 個の要素 B を k 個被りで)
                (res[i+j-k] += A[i] * B[j] % MOD * dpc[j][k] % MOD) %= MOD;
            }
        }
        fill(dpc[0], dpc[B.size() + 2], 0);
        swap(dpc, dpn);
    }
    fill(dpc[0], dpc[B.size() + 2], 0);
    return res;
}

void dump_vec(vector<int> res) {
    for(size_t i=0; i<res.size(); i++) {
        fprintf(stderr, "%lld%c", res[i], " \n"[i+1 == res.size()]);
    }
}

vector<int> solve(int cur) {
    vector<int> res(1, 1);
    for(auto to : G[cur]) {
        auto vec = solve(to);
        res = merge(res, vec, cur, to);
    }
    res.insert(res.begin(), 0LL);
    // dump_vec(res);
    return res;
}

signed main() {
    cin >> N;
    vector<int> deg(N);
    for(int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        deg[v]++;
    }

    for(int i=0; i<N; i++) {
        if(deg[i] == 0) {
            int sum = 0;
            auto res = solve(i);
            for(auto e : res) (sum += e) %= MOD;
            cout << sum << endl;
            return 0;
        }
    }
    return 0;
}

