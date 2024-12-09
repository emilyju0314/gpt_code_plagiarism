#include <bits/stdc++.h>
using namespace std;
const int limit = 1000000;
int identifier[limit];
int first[limit];
int last[limit];
int amount[limit];
int nnex;
int nex[limit];
int who[limit];
unordered_set<int> u2setid[limit];
int computeidentifier(int u) {
  int &idu = identifier[u];
  if (idu == 0) return u;
  idu = computeidentifier(idu);
  return idu;
}
void addsetid(int u, int v) {
  int idv = computeidentifier(v);
  amount[idv]++;
  int pos = ++nnex;
  who[pos] = u;
  nex[pos] = first[idv];
  first[idv] = pos;
  if (!last[idv]) last[idv] = pos;
  u2setid[u].insert(idv);
}
void fusion(int u, int v) {
  u = computeidentifier(u);
  v = computeidentifier(v);
  if (u == v) return;
  if (amount[u] > amount[v]) swap(u, v);
  identifier[u] = v;
  amount[v] += amount[u];
  for (int ind = first[u]; ind; ind = nex[ind]) {
    int w = who[ind];
    unordered_set<int> &setid = u2setid[w];
    setid.erase(u);
    setid.insert(v);
  }
  if (!first[v]) {
    first[v] = first[u];
    last[v] = last[u];
    return;
  }
  nex[last[v]] = first[u];
  if (last[u]) last[v] = last[u];
}
int n, m, cases;
unordered_map<int, int> u2c2v[limit];
void addarrow(int u, int v, int c) {
  unordered_map<int, int> &c2v = u2c2v[u];
  if (c2v.count(c)) {
    fusion(c2v[c], v);
    return;
  }
  c2v[c] = v;
}
void addedge(int u, int v, int c) {
  addarrow(u, v, c);
  addarrow(v, u, c);
  addsetid(u, v);
  addsetid(v, u);
}
bool thereispath(int u, int v) {
  int idu = computeidentifier(u);
  int idv = computeidentifier(v);
  if (idu == idv) return true;
  return u2setid[v].count(idu);
}
int maxnumcolors;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> maxnumcolors >> cases;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    addedge(u, v, c);
  }
  for (int cas = 0; cas < cases; cas++) {
    char car;
    cin >> car;
    if (car == '+') {
      int u, v, c;
      cin >> u >> v >> c;
      addedge(u, v, c);
    } else {
      int u, v;
      cin >> u >> v;
      if (thereispath(u, v))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
}
