#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007ll;
int cnt[101];
long long dp[101];
vector<vector<long long> > b;
vector<vector<long long> > clone(vector<vector<long long> > t) { return t; }
void print(vector<vector<long long> > &a) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) cout << a[i][j] << " ";
    cout << endl;
  }
  cout << "#####################" << endl;
}
void multiply(vector<vector<long long> > &res, vector<vector<long long> > y) {
  vector<vector<long long> > x;
  x.resize(res.size());
  for (int i = 0; i < x.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      long long temp = 0;
      for (int l = 0; l < res[i].size(); l++) {
        temp = (temp + res[i][l] * y[l][j]) % MOD;
      }
      x[i].push_back(temp);
    }
  }
  res = x;
}
void binpow(vector<vector<long long> > &res, vector<vector<long long> > y,
            int n) {
  res.clear();
  res.resize(y.size());
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < y[i].size(); j++)
      if (i == j)
        res[i].push_back(1);
      else
        res[i].push_back(0);
  }
  while (n) {
    if (n & 1) {
      multiply(res, y);
    }
    multiply(y, y);
    n >>= 1;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  int d;
  for (int i = 0; i < n; i++) {
    cin >> d;
    cnt[d]++;
  }
  dp[0] = 1;
  for (int i = 1; i < 101; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i] += dp[i - j] * cnt[j];
    }
    dp[i] %= MOD;
  }
  if (x <= 100) {
    long long ans = 0;
    for (int i = 0; i <= x; i++) ans = (ans + dp[i]) % MOD;
    cout << ans << endl;
    return 0;
  }
  long long sum = 0;
  for (int i = 0; i <= 100; i++) sum = (sum + dp[i]) % MOD;
  vector<vector<long long> > t;
  t.resize(1);
  for (int i = 1; i <= 100; i++) {
    t[0].push_back(dp[i]);
  }
  t[0].push_back(sum);
  b.resize(101);
  for (int i = 0; i < 101; i++) {
    for (int j = 1; j <= 99; j++) {
      if (i == j)
        b[i].push_back(1);
      else
        b[i].push_back(0);
    }
    if (i < 100) {
      b[i].push_back(cnt[100 - i]);
      b[i].push_back(cnt[100 - i]);
    } else {
      b[i].push_back(0);
      b[i].push_back(1);
    }
  }
  binpow(b, b, x - 100);
  multiply(t, b);
  cout << t[0].back() << endl;
  return 0;
}
