#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265358979323846;
const long double EPS = 0.000000001;
const long long MD_7 = 1000000007;
const long long MD_9 = 1000000009;
const long long MD = 228228227;
const long long INF = INT64_MAX;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long nt;
  cin >> nt;
  while (nt--) {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long> > arr1(n, vector<long long>(m)),
        arr2(n, vector<long long>(m));
    for (long long i = 0; i < (n); ++i) {
      for (long long j = 0; j < (m); ++j) {
        cin >> arr1[i][j];
      }
    }
    vector<long long> q;
    for (long long j = 0; j < (m); ++j) {
      for (long long i = 0; i < (n); ++i) {
        long long a;
        cin >> a;
        if (j == 0) q.push_back(a);
      }
    }
    vector<long long> ans(n);
    for (long long i = 0; i < (n); ++i) {
      long long now = q[i];
      for (long long j = 0; j < (n); ++j) {
        for (long long k = 0; k < (m); ++k) {
          if (arr1[j][k] == now) {
            ans[i] = j;
          }
        }
      }
    }
    for (long long i : ans) {
      for (long long j = 0; j < (m); ++j) {
        cout << arr1[i][j] << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
