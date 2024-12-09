#include <bits/stdc++.h>
using namespace std;
bool isprime(long long a) {
  for (long long i = 2; i <= pow(a, 0.5); ++i) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}
long long ceil(long long a, long long b) {
  long long c = (a + b - 1) / b;
  return c;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long power_mod(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long temp = power_mod(a, b / 2);
  temp = (temp * temp) % 1000000007;
  if (b % 2) {
    temp = (temp * a) % 1000000007;
  }
  return temp;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    vector<int> v(26, 0);
    for (char c : s) {
      v[c - 'a']++;
    }
    string ans[1000];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < l; ++j) {
        ans[i] += '.';
      }
    }
    int l1 = 0, r1 = k, m = 0;
    for (int i = 0; i < l; ++i) {
      for (int j = l1; j < r1; ++j) {
        while (v[m] == 0) {
          ++m;
          l1 = j;
        }
        v[m]--;
        ans[j][i] = (m + 'a');
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < l; ++j) {
        if (ans[i][j] == '.') {
          while (v[m] == 0) {
            ++m;
          }
          v[m]--;
          ans[i][j] = m + 'a';
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << "\n";
    }
  }
}
