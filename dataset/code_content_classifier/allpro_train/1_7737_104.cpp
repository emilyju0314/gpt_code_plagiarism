#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m, k;
  int* a;
  cin >> n >> m >> k;
  a = new int[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++)
    for (int j = i; j > 0 && a[j - 1] < a[j]; j--) {
      int t = a[j - 1];
      a[j - 1] = a[j];
      a[j] = t;
    }
  int ans = 0;
  for (int i = 0; i < n && k < m; i++, ans++) k += a[i] - 1;
  cout << (k < m ? -1 : ans);
}
