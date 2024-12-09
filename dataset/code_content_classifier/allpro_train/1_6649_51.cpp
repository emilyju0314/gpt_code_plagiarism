#include <iostream>
#include <cstring>

#include <string>
#include <vector>
#include <algorithm>

#include <cassert>

using namespace std;

#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define MAXM 100004
llong N, nblocks;
int K;
VI A;

int MM;
char B[7][MAXM];

int ncomps;
int C[7][MAXM];
void flood_fill(int r, int c) {
   if (r < 0 || r >= MM || c < 0 || c >= 7) return;
   if (B[c][r] == '#') return;
   if (C[c][r]) return;
   C[c][r] = ncomps;

   flood_fill(r-1, c);
   flood_fill(r, c-1);
   flood_fill(r, c+1);
   flood_fill(r+1, c);
}

int dfs(const VVI& adj, VI& vis, int u) {
   int res = 1;
   vis[u] = 1;
   for (int v : adj[u]) {
      if (!vis[v])
         res += dfs(adj, vis, v);
   }
   return res;
}

llong solve() {
   MM = (K % 7) ? K : K/7;

   //cerr << "MM: " << MM << endl;

   for (int rem : A) {
      for (; rem < 7*MM; rem += K) {
         int r = rem / 7;
         int c = rem % 7;
         B[c][r] = '#';
      }
   }

   /*
   REP(r, MM) {
      REP(c, 7)
         cerr << B[c][r];
      cerr << endl;
   }
   */

   REP(r, MM) {
      REP(c, 7) {
         if (B[c][r] != '#' && C[c][r] == 0) {
            ++ncomps;
            flood_fill(r, c);
         }
      }
   }

   /*
   REP(r, MM) {
      REP(c, 7)
         cerr << C[c][r] << ' ';
      cerr << endl;
   }
   */
   
   VVI adj(ncomps);
   REP(c, 7) {
      int u = C[c][0] - 1, v = C[c][MM-1] - 1;
      if (u >= 0 && v >= 0) {
         adj[u].push_back(v);
         if (u != v)
            adj[v].push_back(u);
      }
   }

   llong nblocks = N / MM;
   //cerr << "Number of blocks = " << nblocks << endl;
   llong res = 0;
   VI vis(ncomps);
   REP(u, ncomps) {
      if (vis[u]) continue;
      if (adj[u].empty())
         res += nblocks;
      else {
         bool self = find(adj[u].begin(), adj[u].end(), u) != adj[u].end();
         int cnt = dfs(adj, vis, u);
         if (self)
            ++res;
         else {
            FOR(len, 1, cnt-1) {
               if (nblocks >= len)
                  res += 2;
            }
            res += max(nblocks - cnt + 1, 0LL);
         }
      }
   }

   return res;
}


int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int Q;
   cin >> N >> K >> Q;
   memset(B, '.', sizeof(B));

   A = VI(Q);
   REP(j, Q)
      cin >> A[j];

   llong res = solve();
   cout << res << endl;

   return 0;
}
