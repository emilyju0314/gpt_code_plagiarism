#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using vi = vector<int>;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
int t, n, res[N];
int a[N];
bool st[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    if (n % 2 == 0) {
      for (int i = 1; i <= n; i += 2) {
        printf("%d %d ", -a[i + 1], a[i]);
      }
    } else {
      vector<int> v;
      map<int, int> ma;
      for (int i = 4; i <= n; i++) {
        if (ma[a[i]]) {
          res[ma[a[i]]] = -1;
          st[ma[a[i]]] = 1;
          st[i] = 1;
          ma[a[i]] = 0;
          res[i] = 1;
        } else {
          ma[a[i]] = i;
        }
      }
      for (int i = 4; i <= n; i++) {
        if (!st[i]) v.push_back(i);
      }
      int m = v.size();
      for (int i = 0; i < m; i += 2) {
        res[v[i]] = a[v[i + 1]];
        res[v[i + 1]] = -a[v[i]];
      }
      if (a[2] + a[3] != 0) {
        res[1] = a[2] + a[3];
        res[2] = -a[1];
        res[3] = -a[1];
      } else if (a[1] + a[3] != 0) {
        res[2] = a[1] + a[3];
        res[1] = -a[2];
        res[3] = -a[2];
      } else if (a[1] + a[2] != 0) {
        res[3] = a[1] + a[2];
        res[1] = -a[3];
        res[2] = -a[3];
      }
      for (int i = 1; i <= n; i++) printf("%d ", res[i]), st[i] = 0, res[i] = 0;
    }
    puts("");
  }
  return 0;
}
