#include <bits/stdc++.h>
using namespace std;
int ABS(int a) { return max(a, -a); }
long long ABS(long long a) { return max(a, -a); }
double ABS(double a) { return max(a, -a); }
const int N = 105;
int arr[N];
int SIZE[N];
vector<int> v[N];
void initialise() {
  for (int i = 0; i < N; i++) {
    arr[i] = i;
    SIZE[i] = 1;
  }
}
int root(int i) {
  while (arr[i] != i) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}
void merge(int a, int b) {
  int roota = root(a);
  int rootb = root(b);
  if (SIZE[roota] < SIZE[rootb]) {
    arr[roota] = arr[rootb];
    SIZE[rootb] += SIZE[roota];
  } else {
    arr[rootb] = arr[roota];
    SIZE[roota] += SIZE[rootb];
  }
}
bool find(int a, int b) {
  if (root(a) == root(b)) return true;
  return false;
}
void solve() {
  initialise();
  int n, m;
  cin >> n >> m;
  int count = 0;
  for (int i = 1; i <= n; i++) {
    int s;
    cin >> s;
    if (s == 0) {
      count++;
    }
    for (int j = 1; j <= s; j++) {
      int x;
      cin >> x;
      v[x].push_back(i);
    }
  }
  for (int i = 1; i <= m; i++) {
    int s = v[i].size();
    for (int j = 0; j < s - 1; j++) {
      merge(v[i][j], v[i][j + 1]);
    }
  }
  int comp = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == i) {
      comp++;
    }
  }
  if (comp == count) {
    cout << n;
  } else {
    cout << comp - 1;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
}
