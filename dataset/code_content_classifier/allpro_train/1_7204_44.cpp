#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[n + 1];
  vector<long long> ar[200010];
  long long dp[200100];
  long long ans[200100];
  for (long long i = 2; i <= 200000; i++) {
    dp[i] = 1;
  }
  for (long long i = 2; i <= 200000; i++) {
    if (dp[i] == 1) {
      ans[i] = i;
      for (long long j = i; j * i <= 200000; j++) {
        ans[j * i] = i;
        dp[j * i] = 0;
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    long long temp = a[i];
    map<long long, long long> m;
    while (temp > 1) {
      m[ans[temp]] += 1;
      temp /= ans[temp];
    }
    for (auto j = m.begin(); j != m.end(); j++) {
      ar[j->first].push_back(j->second);
    }
  }
  long long prod = 1;
  for (long long i = 2; i <= 200000; i++) {
    if (ar[i].size() == n) {
      sort((ar[i]).begin(), (ar[i].end()));
      prod = prod * (pow(i, ar[i][1]));
    } else if (ar[i].size() == n - 1) {
      sort(ar[i].begin(), ar[i].end());
      prod = prod * (pow(i, ar[i][0]));
    }
  }
  cout << prod;
}
