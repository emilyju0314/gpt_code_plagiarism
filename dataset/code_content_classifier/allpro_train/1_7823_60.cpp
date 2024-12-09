#include <bits/stdc++.h>
using namespace std;
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
void pairsort(int a[], int b[], int n) {
  pair<int, int> pairt[n];
  for (int i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  for (int i = 0; i < n; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
}
void pairsortlli(long long int a[], long long int b[], long long int n) {
  pair<long long int, long long int> pairt[n];
  for (long long int i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  for (long long int i = 0; i < n; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
}
long long int binomialCoeff(long long int n, long long int k) {
  long long int C[k + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = min(i, k); j > 0; j--)
      C[j] = (C[j] + C[j - 1]) % 1000000007;
  }
  return C[k];
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int bins(long long int arr[], long long int l, long long int r,
                   long long int x) {
  if (r >= l) {
    long long int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return bins(arr, l, mid - 1, x);
    return bins(arr, mid + 1, r, x);
  }
  return -1;
}
void swap(long long int* a, long long int* b) {
  long long int t;
  t = *a;
  *a = *b;
  *b = t;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int y1, y2, yw, xb, yb, r;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  long long int p = yb + 2 * (yw - r - yb);
  double m = ((p - y1 - r) * 1.0) / xb;
  long long int q = y2 - y1 - r;
  double a = 1 + m * m;
  if ((q * q * 1.0) / a > r * r) {
    cout << fixed << setprecision(20) << abs((yw - r - y1 - r) / m) << "\n";
  } else {
    cout << -1 << "\n";
  }
}
