#include <bits/stdc++.h>
using namespace std;
void sc(char& c) {
  char temp[4];
  scanf("%s", temp);
  c = temp[0];
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
void debugarr(int* arr, int n) {
  cout << "[";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "]" << endl;
}
int testnum;
int n, m, k;
int a[10][100];
int b[10][100];
int c[10][100];
int get(vector<pair<int, int> > obj) {
  sort(obj.begin(), obj.end());
  int left = k;
  int sum = 0;
  for (int i = m - 1; i >= 0; i--) {
    if (obj[i].first < 0) break;
    int num = min(left, obj[i].second);
    sum += num * obj[i].first;
    left -= num;
  }
  return sum;
}
void solve() {
  int best = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      vector<pair<int, int> > objs;
      for (int k = 0; k < m; k++)
        objs.push_back(make_pair(b[j][k] - a[i][k], c[i][k]));
      best = max(best, get(objs));
    }
  printf("%d\n", best);
}
bool input() {
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &k);
  char dummy[15];
  for (int i = 0; i < n; i++) {
    scanf("%s", dummy);
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      scanf("%d", &b[i][j]);
      scanf("%d", &c[i][j]);
    }
  }
  return true;
}
int main() {
  int T = 1;
  for (testnum = 1; testnum <= T; testnum++) {
    if (!input()) break;
    solve();
  }
}
