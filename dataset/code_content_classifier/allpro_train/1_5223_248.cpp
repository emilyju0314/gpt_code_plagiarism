#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
int n, a[N], b[N], A[N], B[N], c[N];
map<int, int> M;
int main() {
  scanf("%d", &n);
  for (int i = n; i >= 1; i--) {
    scanf("%d", &b[i]);
    B[b[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    scanf("%d", &a[i]);
    A[a[i]] = i;
  }
  M.clear();
  for (int i = 1; i <= n; i++) {
    c[i] = A[i] - B[i];
    M[c[i]]++;
  }
  for (int i = 0; i < n; i++) {
    map<int, int>::iterator t1 = M.lower_bound(-i);
    int ans = 10000000;
    if (t1 != M.end()) {
      ans = (*t1).first + i;
    }
    if (t1 != M.begin()) {
      t1--;
      ans = min(ans, -i - (*t1).first);
    }
    printf("%d\n", ans);
    M[c[a[n - i]]]--;
    if (M[c[a[n - i]]] == 0) M.erase(c[a[n - i]]);
    M[-i - B[a[n - i]]]++;
  }
}
