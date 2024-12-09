#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <queue>
#include <bitset>
#include <numeric>
#include <array>
#include <cstring>
#include <random>
#include <chrono>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 1e5 + 42;
vector<pair<ll, int> > g[N];
ll dist[2][N][52];
int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n = 0, m = 0;

  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    dist[0][i][0] = dist[1][i][0] = -1;
    for(int j = 0; j <= 50; j++) dist[1][i][j] = -1;
  }

  for(int i = 0; i < m; i++) {
    int v, u, w;
    cin >> v >> u >> w;
    g[--v].pb(mp(w, --u));
    g[u].pb(mp(w, v));
  }

  for(ll i = 0; i < n; i++) sort(all(g[i]));

  dist[0][0][0] = 0;

  priority_queue<pair<ll, pair<pair<ll, int>, int> > > q;

  q.push(mp(0, mp(mp(0, 0), 0)));

  while(!q.empty()) {
    auto cur = q.top(); q.pop();
    ll cdist = -cur.fi, cww = -cur.se.fi.fi; int cv = cur.se.fi.se, cp = cur.se.se;
    if(cp == 0) {
      if(dist[0][cv][cww] != -1 && dist[0][cv][cww] < cdist) continue;
      for(auto& x : g[cv]) {
        ll ndist = cdist;
        if(dist[1][x.se][x.fi] == -1 || dist[1][x.se][x.fi] > ndist) {
          dist[1][x.se][x.fi] = ndist;
          q.push(mp(-ndist, mp(mp(-x.fi, x.se), 1)));
        }
      }
    } else {
      if(dist[1][cv][cww] != -1 && dist[1][cv][cww] < cdist) continue;
      for(auto& x : g[cv]) {
        ll ndist = cdist + x.fi * x.fi + 2 * x.fi * cww + cww * cww;
        if(dist[0][x.se][0] == -1 || dist[0][x.se][0] > ndist) {
          dist[0][x.se][0] = ndist;
          q.push(mp(-ndist, mp(mp(0, x.se), 0)));
        }
      }
    }
  }

  for(int i = 0; i < n; i++) cout << dist[0][i][0] << ' ';

  return 0;
}
/*

*/
