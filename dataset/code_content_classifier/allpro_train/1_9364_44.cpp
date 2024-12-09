#include <bits/stdc++.h>
using namespace std;
int n;
set<int> AdjList[200001];
int nChild[200001];
int d[200001];
int p[200001];
int d_x;
int cur_sz = 0;
int lim;
void cal_d(int u, int par) {
  for (set<int>::iterator it = AdjList[u].begin(); it != AdjList[u].end();
       it++) {
    int v = *it;
    if (v != par) {
      p[v] = u;
      d[v] = d[u] + 1;
      cal_d(v, u);
    }
  }
}
void cal_sz(int u, int par) {
  cur_sz++;
  nChild[u] = 1;
  for (set<int>::iterator it = AdjList[u].begin(); it != AdjList[u].end();
       it++) {
    int v = *it;
    if (v != par) {
      cal_sz(v, u);
      nChild[u] += nChild[v];
    }
  }
}
int find_c(int u, int par) {
  for (set<int>::iterator it = AdjList[u].begin(); it != AdjList[u].end();
       it++) {
    int v = *it;
    if (v != par && nChild[v] > lim) return find_c(v, u);
  }
  return u;
}
void decomp(int u) {
  cur_sz = 0;
  cal_sz(u, -1);
  lim = cur_sz / 2;
  int c = find_c(u, -1);
  int cur_d;
  cout << "d " << c << endl;
  cin >> cur_d;
  if (cur_d == 0) {
    cout << "! " << c << endl;
    exit(0);
  }
  if (d_x - d[c] == cur_d) {
    cout << "s " << c << endl;
    int nxt;
    cin >> nxt;
    AdjList[nxt].erase(c);
    decomp(nxt);
  } else {
    AdjList[p[c]].erase(c);
    decomp(p[c]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    AdjList[u].insert(v);
    AdjList[v].insert(u);
  }
  cal_d(1, -1);
  cout << "d 1" << endl;
  cin >> d_x;
  decomp(1);
}
