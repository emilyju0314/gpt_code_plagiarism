#include <bits/stdc++.h>
using namespace std;
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
template <typename T>
inline T BigMod(T A, T B) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % 998244353;
    A = (A * A) % 998244353;
    B = B >> 1;
  }
  return ret;
}
template <typename T>
inline T InvMod(T A, T M = 998244353) {
  return BigMod(A, M - 2);
}
string tostring(long long int res) {
  string curstr = "";
  if (!res) curstr += ((char)res + '0');
  while (res != 0) {
    long long int temp = (res % 10);
    curstr += ((char)temp + '0');
    res /= 10;
  }
  reverse(curstr.begin(), curstr.end());
  return curstr;
}
long long int toint(string ss) {
  long long int inss = 0;
  for (int i = 0; i < ss.size(); i++) {
    inss = (inss * 10) + ((int)(ss[i] - '0'));
  }
  return inss;
}
int n, m, low[300005], disc[300005], vis[300005], par[300005], dis[300005],
    dsupar[300005];
vector<int> graph[300005], vv[300005];
struct st {
  int u, v;
};
vector<st> bridges;
int findpar(int p) {
  if (dsupar[p] == p)
    return p;
  else
    return dsupar[p] = findpar(dsupar[p]);
}
void findbridge(int cur, int curpar, int dep) {
  vis[cur] = 1;
  disc[cur] = low[cur] = dep;
  for (int i = 0; i < graph[cur].size(); i++) {
    int v = graph[cur][i];
    if (v == curpar) continue;
    if (!vis[v]) {
      par[v] = cur;
      findbridge(v, cur, dep + 1);
      if (low[v] > dep) {
        st get;
        get.u = cur;
        get.v = v;
        bridges.push_back(get);
      } else {
        int paru = findpar(cur);
        int parv = findpar(v);
        dsupar[paru] = parv;
      }
      low[cur] = min(low[cur], low[v]);
    } else
      low[cur] = min(low[cur], disc[v]);
  }
}
pair<int, int> bfs(int sr) {
  for (int i = 1; i <= n; i++) dis[i] = 2e9;
  dis[sr] = 0;
  queue<int> q;
  q.push(sr);
  int last;
  while (!q.empty()) {
    last = q.front();
    q.pop();
    for (int i = 0; i < vv[last].size(); i++) {
      int v = vv[last][i];
      if (dis[v] > dis[last] + 1) {
        dis[v] = dis[last] + 1;
        q.push(v);
      }
    }
  }
  return make_pair(last, dis[last]);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= 300003; i++) dsupar[i] = i;
  int u, v;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  findbridge(1, -1, 0);
  int sr;
  for (int i = 0; i < bridges.size(); i++) {
    int u = bridges[i].u;
    int v = bridges[i].v;
    int paru = findpar(u);
    int parv = findpar(v);
    sr = paru;
    vv[paru].push_back(parv);
    vv[parv].push_back(paru);
  }
  int cur = sr;
  int maxdistance = 2e9, finalnode;
  int iter = 3, fl = 0;
  while (iter--) {
    pair<int, int> now = bfs(cur);
    int node = now.first;
    int distance = now.second;
    if (distance < maxdistance && fl) {
      maxdistance = distance;
      finalnode = node;
    }
    cur = node;
    fl = 1;
  }
  printf("%d\n", maxdistance);
  return 0;
}
