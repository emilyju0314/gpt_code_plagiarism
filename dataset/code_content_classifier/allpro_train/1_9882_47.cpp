#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60000000")
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
template <class T>
T sqr(T x) {
  return x * x;
}
const int NMAX = 100010;
int n, root, a[NMAX], now[NMAX], zn[NMAX];
pair<int, int> b[NMAX];
vector<pair<int, int> > ans;
void solve(int p) {
  if (b[p].second == root) return;
  if (now[root] != p) {
    int tmp = zn[p], pl = now[root];
    swap(now[root], now[tmp]);
    swap(zn[p], zn[pl]);
    ans.push_back(make_pair(p, pl));
  }
  int need = b[p].second;
  if (now[need] != p) {
    int pl = now[need];
    swap(now[root], now[need]);
    swap(zn[p], zn[pl]);
    ans.push_back(make_pair(p, pl));
  }
}
int main() {
  cin >> n;
  int sorted = 1;
  for (int i = 0; i < (int)(n); i++) {
    scanf("%d", &a[i]);
    if (i && a[i] < a[i - 1]) sorted = 0;
    now[i] = i;
    b[i] = make_pair(a[i], i);
  }
  if (sorted) {
    cout << 0 << endl;
    return 0;
  }
  sort(b, b + n);
  for (int i = 0; i < (int)(n); i++) zn[i] = i;
  root = -1;
  for (int i = 0; i < (int)(n); i++) {
    int ok = 1, z = a[i];
    while (z > 0) {
      if (z % 10 != 4 && z % 10 != 7) ok = 0;
      z /= 10;
    }
    if (ok) root = i;
  }
  if (root == -1) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < (int)(n); i++) solve(i);
  cout << ans.size() << endl;
  for (int i = 0; i < (int)(ans.size()); i++)
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  return 0;
}
