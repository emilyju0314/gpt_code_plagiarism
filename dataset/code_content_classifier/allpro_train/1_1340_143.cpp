#include <bits/stdc++.h>
using namespace std;
int modo(int a) {
  if (a > 0) return a;
  return -a;
}
long long a[100005], b[100005];
char a1[100005], b1[100005];
int main() {
  int n;
  cin >> n;
  int p, q;
  p = q = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    a1[i] = b1[i] = '0';
  }
  int k = 0;
  p = q = 0;
  for (int i = 0; i < k; i++) {
    a1[i] = b1[i] = '1';
  }
  p = q = k;
  for (int i = 0; i < n - 2 * k; i++) {
    if (a[p] < b[q]) {
      a1[p++] = '1';
    } else {
      b1[q++] = '1';
    }
  }
  k = n / 2;
  p = q = 0;
  for (int i = 0; i < k; i++) {
    a1[i] = b1[i] = '1';
  }
  p = q = k;
  for (int i = 0; i < n - 2 * k; i++) {
    if (a[p] < b[q]) {
      a1[p++] = '1';
    } else {
      b1[q++] = '1';
    }
  }
  cout << a1 << endl;
  cout << b1 << endl;
  return 0;
}
