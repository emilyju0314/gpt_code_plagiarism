#include <bits/stdc++.h>
using namespace std;
struct triple {
  int typ, ind, past;
  triple(int a = 0, int b = 0, int c = 0) { typ = a, ind = b, past = c; }
};
int parent[200005], sz[200005], up[200005], bip[200005];
pair<int, int> road[200005];
int find_parent(int v) {
  if (v == parent[v]) return v;
  return find_parent(parent[v]);
}
int find_colour(int v) {
  if (v == parent[v]) return 0;
  return (find_colour(parent[v]) ^ up[v]);
}
void unions(int a, int b, vector<triple> &qu) {
  int first = (find_colour(a) == find_colour(b));
  a = find_parent(a), b = find_parent(b);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    qu.push_back(triple(1, b, parent[b]));
    qu.push_back(triple(2, a, sz[a]));
    qu.push_back(triple(3, b, up[b]));
    parent[b] = a, sz[a] += sz[b], up[b] = first;
  }
  return;
}
bool bipart(int a, int b) {
  if (find_parent(a) != find_parent(b)) return true;
  if (find_colour(a) != find_colour(b)) return true;
  return false;
}
void build(int lef, int rig, int L, int R) {
  vector<triple> upd1, upd2;
  int mid = (lef + rig) / 2;
  for (int i = lef; i <= mid; i++) unions(road[i].first, road[i].second, upd1);
  int gran = R + 1;
  while (gran > L && bipart(road[gran - 1].first, road[gran - 1].second)) {
    gran--;
    unions(road[gran].first, road[gran].second, upd2);
  }
  bip[mid] = gran;
  for (int i = 0; i < (int)upd2.size(); i++) {
    triple A = upd2[i];
    if (A.typ == 1) parent[A.ind] = A.past;
    if (A.typ == 2) sz[A.ind] = A.past;
    if (A.typ == 3) up[A.ind] = A.past;
  }
  for (int i = 0; i < (int)upd1.size(); i++) {
    triple A = upd1[i];
    if (A.typ == 1) parent[A.ind] = A.past;
    if (A.typ == 2) sz[A.ind] = A.past;
    if (A.typ == 3) up[A.ind] = A.past;
  }
  upd1.clear(), upd2.clear();
  if (mid != lef) {
    for (int i = gran; i <= R; i++) unions(road[i].first, road[i].second, upd2);
    build(lef, mid - 1, L, gran - 1);
    for (int i = 0; i < (int)upd2.size(); i++) {
      triple A = upd2[i];
      if (A.typ == 1) parent[A.ind] = A.past;
      if (A.typ == 2) sz[A.ind] = A.past;
      if (A.typ == 3) up[A.ind] = A.past;
    }
    upd2.clear();
  }
  if (mid != rig) {
    for (int i = lef; i <= mid; i++)
      unions(road[i].first, road[i].second, upd1);
    build(mid + 1, rig, gran, R);
    for (int i = 0; i < (int)upd1.size(); i++) {
      triple A = upd1[i];
      if (A.typ == 1) parent[A.ind] = A.past;
      if (A.typ == 2) sz[A.ind] = A.past;
      if (A.typ == 3) up[A.ind] = A.past;
    }
    upd1.clear();
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, quer;
  cin >> n >> m >> quer;
  for (int i = 1; i <= m; i++) cin >> road[i].first >> road[i].second;
  vector<triple> upd;
  for (int i = 1; i <= n; i++) parent[i] = i, sz[i] = 1, up[i] = 0;
  int gran = m + 1;
  while (gran > 1 && bipart(road[gran - 1].first, road[gran - 1].second)) {
    gran--;
    unions(road[gran].first, road[gran].second, upd);
  }
  bip[0] = gran;
  for (int i = 1; i <= n; i++) parent[i] = i, sz[i] = 1, up[i] = 0;
  gran = 0;
  while (gran < m && bipart(road[gran + 1].first, road[gran + 1].second)) {
    gran++;
    unions(road[gran].first, road[gran].second, upd);
  }
  upd.clear();
  for (int i = 1; i <= n; i++) parent[i] = i, sz[i] = 1, up[i] = 0;
  if (gran != m)
    build(1, gran, 1, m);
  else {
    for (int i = 0; i <= m; i++) bip[i] = i + 1;
  }
  for (int rep = 1; rep <= quer; rep++) {
    int lef, rig;
    cin >> lef >> rig;
    if (bip[lef - 1] == 0 || bip[lef - 1] > rig + 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
