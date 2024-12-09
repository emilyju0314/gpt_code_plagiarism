#include <bits/stdc++.h>
using namespace std;
const int mod = (1e9) + 7;
const int siz = 2e5 + 5, siz2 = 105e4 + 5;
int n, centroid, mn, last, lim = 1 << 19, let[siz], treesz[siz], nodemask[siz],
                           dfsnodes[siz], dfsmasks[siz], parent[siz],
                           mask[siz2];
pair<int, int> lims[siz];
vector<int> adj[siz];
char arr[siz];
bool done[siz];
long long ans[siz], curans[siz];
void getcentroid(int node, int par, int tot) {
  int mx = INT_MIN, mxnode = node;
  treesz[node] = 1;
  int sz = adj[node].size();
  for (int i = 0; i < sz; i++) {
    int nex = adj[node][i];
    if (!done[nex] && nex != par) {
      getcentroid(nex, node, tot);
      treesz[node] += treesz[nex];
      mx = max(mx, treesz[nex]);
    }
  }
  mx = max(mx, tot - treesz[node]);
  if (mx < mn) {
    mn = mx;
    centroid = node;
  }
}
void calcmask(int node, int par, int parmask) {
  int curmask = nodemask[node] ^ parmask;
  dfsnodes[last] = node;
  dfsmasks[last++] = curmask;
  parent[node] = par;
  mask[curmask]++;
  treesz[node] = 1;
  int sz = adj[node].size();
  for (int i = 0; i < sz; i++) {
    int nex = adj[node][i];
    if (!done[nex] && nex != par) {
      calcmask(nex, node, curmask);
      treesz[node] += treesz[nex];
    }
  }
}
void calcans(int l, int r) {
  int centmask = nodemask[centroid];
  for (int i = l; i <= r; i++) {
    mask[dfsmasks[i]]--;
  }
  for (int i = r; i >= l; i--) {
    int node = dfsnodes[i], wocent = dfsmasks[i] ^ centmask;
    curans[node] += mask[wocent];
    for (int i = 1; i <= lim; i <<= 1) {
      int val = wocent ^ i;
      curans[node] += mask[val];
    }
    curans[parent[node]] += curans[node];
    ans[node] += curans[node];
    curans[node] = 0;
  }
  for (int i = l; i <= r; i++) {
    mask[dfsmasks[i]]++;
  }
}
void clearmask() {
  int centmask = nodemask[centroid];
  mask[centmask] = 0;
  for (int i = 0; i < last; i++) mask[dfsmasks[i]] = 0;
}
void solve(int start) {
  stack<int> st;
  st.push(start);
  while (st.size() != 0) {
    int cur = st.top();
    st.pop();
    mn = INT_MAX;
    getcentroid(cur, 0, treesz[cur]);
    mask[nodemask[centroid]]++;
    int centmask = nodemask[centroid];
    int sz = adj[centroid].size();
    int c = 0;
    for (int i = 0; i < sz; i++) {
      int node = adj[centroid][i];
      if (!done[node]) {
        calcmask(node, centroid, centmask);
        lims[c] = {c ? lims[c - 1].second + 1 : 0, last - 1};
        c++;
      }
    }
    for (int i = c - 1; i >= 0; i--) {
      int l = lims[i].first, r = lims[i].second;
      calcans(l, r);
    }
    curans[centroid] += mask[0];
    for (int i = 1; i <= lim; i <<= 1) {
      curans[centroid] += mask[i];
    }
    curans[centroid]++;
    ans[centroid] += curans[centroid] / 2;
    curans[centroid] = 0;
    clearmask();
    last = 0;
    done[centroid] = true;
    for (int i = 0; i < sz; i++) {
      int node = adj[centroid][i];
      if (!done[node]) {
        st.push(node);
      }
    }
  }
}
void pre() {
  for (int i = 1; i <= n; i++) nodemask[i] = 1 << (arr[i - 1] - 97);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  scanf("%s", arr);
  int sz = strlen(arr);
  for (int i = 0; i < sz; i++) let[i + 1] = arr[i] - 97;
  pre();
  treesz[1] = n;
  solve(1);
  for (int i = 1; i <= n; i++) {
    printf("%I64d", ans[i]);
    if (i != n)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
}
