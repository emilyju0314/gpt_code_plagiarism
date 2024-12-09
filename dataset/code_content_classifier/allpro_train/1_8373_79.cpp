#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long n;
vector<vector<long long> > G;
vector<long long> met;
vector<long long> t(4 * n + 1, 0);
void dfs(long long k) {
  met[k] = 1;
  for (int i = 0; i < G[k].size(); i++) {
    if (met[G[k][i]] == 0) dfs(G[k][i]);
  }
}
long long nod(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return nod(b, a % b);
}
long long BS(vector<long long> arr, long long zn) {
  int l = 1;
  int r = arr.size() - 1;
  while (l <= r) {
    long long sr = (l + r) / 2;
    if (arr[sr] == zn) return sr;
    if (arr[sr] < zn) l = sr + 1;
    if (arr[sr] > zn) r = sr - 1;
  }
  return -1;
}
long long rsr(long long a) {
  long long k = 0;
  set<long long> z;
  while (a > 0) {
    k++;
    z.insert(a % 10);
    a /= 10;
  }
  return k;
}
long long pr(long long k) {
  long long t = 0, r = 0;
  if (k == 1) return 1;
  for (long long i = 1; i * i <= k; i++) {
    if (i * i == k) {
      t++;
      r = 1;
      break;
    }
    if (k % i == 0) {
      t++;
    }
  }
  if (r == 1)
    t = 2 * t - 1;
  else
    t = 2 * t;
  return t;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string second;
  long long n, mx = -1, pr = -1, rec = 0;
  cin >> n;
  vector<long long> a(n + 1, 0), b(n + 1, -1), c(n + 1, 0), vv(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vv[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > mx) {
      b[a[i]] = 0;
      pr = mx;
      mx = a[i];
      rec++;
    } else if (a[i] > pr) {
      b[a[i]] = mx;
      pr = a[i];
    }
  }
  set<long long> ss;
  for (long long i = 1; i <= n; i++)
    if (b[i] == 0) ss.insert(i);
  for (int i = 1; i <= n; i++)
    if (b[i] != -1) c[b[i]]++;
  mx = -1;
  pr = n + 1;
  for (long long i = 1; i <= n; i++) {
    if (ss.find(i) != ss.end()) {
      if (rec - 1 + c[i] > mx) {
        mx = rec - 1 + c[i];
        pr = i;
      }
      if (rec - 1 + c[i] == mx) {
        pr = min(pr, i);
      }
    }
    if (ss.find(i) == ss.end()) {
      if (rec + c[i] > mx) {
        mx = rec + c[i];
        pr = i;
      }
      if (rec + c[i] == mx) pr = min(pr, i);
    }
  }
  cout << pr;
}
