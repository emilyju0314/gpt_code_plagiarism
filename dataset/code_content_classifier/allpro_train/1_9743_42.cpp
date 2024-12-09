#include <bits/stdc++.h>
using namespace std;
int mod(int i, int p) { return (i + p) % p; }
const int MAXN = 36;
int n, m;
set<vector<int>> poss;
int mtry[11][MAXN];
int c[15];
void dfsGen(int v[], int d, int ucnt, int ccnt) {
  if (d == n) {
    if (ucnt == ccnt) {
      vector<int> nv;
      for (int i = 0; i < n; i++) {
        nv.push_back(v[i]);
      }
      poss.insert(nv);
    }
    return;
  }
  int p = n - 1 - d;
  if (!(ccnt <= ucnt + p + 1)) {
    return;
  }
  if (ucnt < ccnt) {
    v[d] = mtry[0][d];
    dfsGen(v, d + 1, ucnt + 1, ccnt);
  }
  v[d] = !mtry[0][d];
  dfsGen(v, d + 1, ucnt, ccnt);
}
int eqcmp(int a[], const vector<int>& b) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      cnt++;
    }
  }
  return cnt;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s >> c[i];
    for (int j = 0; j < n; j++) {
      mtry[i][j] = s[j] - '0';
    }
  }
  int v[MAXN];
  dfsGen(v, 0, 0, c[0]);
  for (int i = 1; i < m; i++) {
    auto it = poss.begin();
    for (; it != poss.end();) {
      int ocnt = eqcmp(mtry[i], *it);
      if (c[i] != ocnt) {
        poss.erase(it++);
      } else {
        ++it;
      }
    }
  }
  cout << poss.size() << endl;
  return 0;
}
