#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 200005;
typedef pair<int, int> pii;

int N, fa[MAX_N];
bool vis[MAX_N], on[MAX_N];

vector<int> G[MAX_N], cir;

void find_circle(int u) {
  static bool pass[MAX_N];
  vis[u] = 1, pass[u] = 1;
  for (int v : G[u]) 
    if (!vis[v]) {
      find_circle(v);
    } else if (pass[v]) {
      int temp = u;
      while (true) {
	cir.push_back(temp), on[temp] = 1;
	if (temp == v) break;
	temp = fa[temp];
      }
    }
  pass[u] = 0;
}

pii SG[MAX_N];

void dfs(int u) {
  static int stamp, mex[MAX_N];
  for (int v : G[u]) 
    if (!on[v]) {
      dfs(v);
    }

  ++stamp;
  if (!on[u]) {
    for (int v : G[u])
      if (!on[v])
	mex[SG[v].first] = stamp;
    SG[u].first = 0;
    while (mex[SG[u].first] == stamp) SG[u].first++;
  } else {
    for (int v : G[u]) 
      if (!on[v])
	mex[SG[v].first] = stamp;
    SG[u].first = 0;
    while (mex[SG[u].first] == stamp) SG[u].first++;
    SG[u].second = SG[u].first + 1;
    while (mex[SG[u].second] == stamp) SG[u].second++;
  }
}

int value[MAX_N];

bool solve(int x) {
  int sz = cir.size();
  value[0] = x;
  
  for (int i = 1; i < sz; ++i) {
    if (value[i - 1] != SG[cir[i]].first) value[i] = SG[cir[i]].first;
    else value[i] = SG[cir[i]].second;
  }

  return value[sz - 1] != value[0];
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &fa[i]);
    G[fa[i]].push_back(i);
  }

  for (int i = 1; i <= N; ++i)
    if (!vis[i]) find_circle(i);

  for (int u : cir) 
    dfs(u);

  if (solve(SG[cir[0]].first) || (solve(SG[cir[0]].second) && value[cir.size() - 1] == SG[cir[0]].first)) {
    puts("POSSIBLE");
  } else {
    puts("IMPOSSIBLE");
  }
  
  return 0;
}
