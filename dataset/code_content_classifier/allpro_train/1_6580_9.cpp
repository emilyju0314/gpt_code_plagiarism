#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

/* Strongly Connected Component */

/*
  1. dfsをして、戻るときに1から順に番号を付ける
  2. 数値が大きいノードから逆辺を使ってdfsをする。
  すでに訪れているノードには行かない。
  たどり着けるノードが同じ連結成分に属する。
*/

struct SCC{
  int n;
  vector<vector<int> > G, rG;
  vector<int> vs, cmp;
  vector<bool> used;

  SCC(int n):n(n), G(n), rG(n), cmp(n){}

  void add_edge(int from, int to){
    G[from].push_back(to);
    rG[to].push_back(from);
  }

  void dfs(int v){
    used[v] = true;
    for(int to : G[v])
      if(!used[to]) dfs(to);
    vs.push_back(v);
  }

  void rdfs(int v, int k){
    used[v] = true;
    cmp[v] = k;
    for(int to : rG[v])
      if(!used[to]) rdfs(to, k);
  }

  int solve(){
    used.assign(n, false);
    vs.clear();
    for(int i=0; i<n; i++)
      if(!used[i]) dfs(i);
    used.assign(n, false);
    int k = 0;
    for(int i=(int)vs.size()-1; i>=0; i--)
      if(!used[vs[i]]) rdfs(vs[i], k++);
    return k; //強連結成分数
  }

  //属する強連結成分番号(トポロジカル順)
  int operator[](int k) const {
    return cmp[k];
  }
};


vector<int> groups[SIZE];
vector<int> G[SIZE];
vector<int> vecMax[SIZE], vecMin[SIZE];
int ans[SIZE];


int main(){
  int N, M;
  vector<vector<int> > points;


  scanf("%d%d", &N, &M);

  SCC scc(N);

  for(int i=0; i<N; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);

    vector<int> vec;

    for(int s1=-1; s1<=1; s1+=2)
      for(int s2=-1; s2<=1; s2+=2)
        for(int s3=-1; s3<=1; s3+=2)
          vec.push_back(x * s1 + y * s2 + z * s3);

    points.push_back(vec);
  }

  for(int i=0; i<M; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;

    scc.add_edge(u, v);
    G[u].push_back(v);
  }


  scc.solve();

  for(int i=0; i<N; i++) {
    groups[scc[i]].push_back(i);
  }


  for(int i=N-1; i>=0; i--) {
    vecMin[i].assign(8, INF);
    vecMax[i].assign(8, -INF);

    for(int p : groups[i]) {
      for(int q : G[p]) {

        debug(q);
        debug(scc[q]);

        for(int j=0; j<8; j++) {
          vecMin[i][j] = min(vecMin[i][j], vecMin[scc[q]][j]);
          vecMax[i][j] = max(vecMax[i][j], vecMax[scc[q]][j]);
        }
      }

      for(int j=0; j<8; j++) {
        vecMin[i][j] = min(vecMin[i][j], points[p][j]);
        vecMax[i][j] = max(vecMax[i][j], points[p][j]);
      }

      debug(vecMin[i]);
      debug(vecMax[i]);
    }

    for(int p : groups[i]) {
      for(int j=0; j<8; j++) {
        ans[p] = max(ans[p], abs(vecMin[i][j] - points[p][j]));
        ans[p] = max(ans[p], abs(vecMax[i][j] - points[p][j]));
      }
    }
  }

  for(int i=0; i<N; i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}

