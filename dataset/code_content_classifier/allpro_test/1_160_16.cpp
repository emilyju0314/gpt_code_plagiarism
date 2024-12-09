#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int countDivisors(int n) {
  int cnt = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
long long int merge(long long arr[], long long l, long long m, long long r) {
  long long int ans = 0, n1 = m - l + 1, n2 = r - m, a[n1], b[n2], ma = INT_MIN,
                mi = INT_MAX;
  for (long long int i = 0; i < n1; i++) {
    {
      a[i] = arr[l + i];
      ma = max(ma, a[i]);
    }
  }
  for (long long int i = 0; i < n2; i++) {
    {
      b[i] = arr[m + i + 1];
      mi = min(mi, b[i]);
    }
  }
  long long int i = 0, j = 0, k = l, c1 = 0;
  while (i < n1 && j < n2) {
    if (a[i] <= b[j])
      arr[k++] = a[i++];
    else {
      arr[k++] = b[j++];
      c1 = 1;
    }
  }
  while (i < n1) {
    arr[k++] = a[i++];
  }
  while (j < n2) {
    arr[k++] = b[j++];
  }
  if (c1 == 1)
    ans = ma - mi;
  else
    ans = 0;
  return ans;
}
long long int mergeSort(long long arr[], long long l, long long r) {
  long long int ans = 0, mid = 0;
  if (r > l) {
    mid = (r + l) / 2;
    ans += mergeSort(arr, l, mid);
    ans += mergeSort(arr, mid + 1, r);
    ans += merge(arr, l, mid, r);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  long long t, n, m, r1, c1, r2, c2;
  cin >> t;
  while (t--) {
    cin >> n >> m >> r1 >> c1 >> r2 >> c2;
    long long ans = INT_MAX, an2 = INT_MAX, ans1 = INT_MAX;
    if (r2 >= r1) ans = r2 - r1;
    if (c2 >= c1) ans = min(c2 - c1, ans);
    long long an1 = INT_MAX;
    an1 = (n - r1) + (n - r2);
    an2 = (m - c1) + (m - c2);
    ans1 = min(an1, an2);
    ans = min(ans1, ans);
    cout << ans << '\n';
  }
  return 0;
}
