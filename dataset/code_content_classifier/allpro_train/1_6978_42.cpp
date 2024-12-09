#include <bits/stdc++.h>
using namespace std;
const double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230;
long long n, k;
vector<long long> a;
vector<vector<long long> > mat;
vector<vector<long long> > iden;
long long brute() {
  if (*max_element(a.begin(), a.end()) >= k) return 0;
  long long s = 1;
  while (true) {
    for (long long i = (1); i < (n); i++) a[i] = min(a[i - 1] + a[i], k);
    if (a[n - 1] >= k) return s;
    s++;
  }
}
vector<vector<long long> > mult(vector<vector<long long> > mat1,
                                vector<vector<long long> > mat2) {
  vector<vector<long long> > c(n, vector<long long>(n, 0));
  for (long long i = 0; i < (n); i++) {
    for (long long j = 0; j < (n); j++) {
      long long cur = 0;
      for (long long l = 0; l < (n); l++) {
        long long x = mat1[l][j];
        long long y = mat2[i][l];
        if (x != 0 and y > (k / x))
          cur = k;
        else if (x * y > k - cur)
          cur = k;
        else
          cur = min(k, cur + (x * y));
      }
      c[i][j] = cur;
    }
  }
  return c;
}
vector<vector<long long> > expo(vector<vector<long long> > mat, long long b) {
  if (b == 0) return iden;
  if (b == 1) return mat;
  vector<vector<long long> > x = expo(mat, b / 2);
  if (b % 2 == 1) {
    return mult(mult(x, x), mat);
  } else {
    return mult(x, x);
  }
}
bool check(long long mid) {
  if (mid == 0) return *max_element(a.begin(), a.end()) >= k;
  vector<vector<long long> > cur = expo(mat, mid);
  long long res = 0;
  for (long long j = 0; j < (n); j++) {
    long long x = a[j];
    long long y = cur[n - 1][j];
    if (x != 0 and y > (k / x))
      res = k;
    else if (x * y > k - res)
      res = k;
    else
      res = min(k, res + (x * y));
  }
  return res >= k;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  bool zz = false;
  for (long long i = 0; i < (n); i++) {
    long long x;
    cin >> x;
    if (x != 0 or zz) {
      a.push_back(x);
      zz = true;
    }
  }
  n = a.size();
  if (n >= 10) {
    cout << brute() << endl;
    return 0;
  }
  mat.resize(n);
  iden.resize(n);
  for (long long i = 0; i < (n); i++) {
    for (long long j = 0; j < (n); j++) {
      if (i >= j)
        mat[i].push_back(1);
      else
        mat[i].push_back(0);
      if (i == j)
        iden[i].push_back(1);
      else
        iden[i].push_back(0);
    }
  }
  long long low = 0;
  long long high = k;
  long long mid, ans = -1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (check(mid)) {
      high = mid - 1;
      ans = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << endl;
}
