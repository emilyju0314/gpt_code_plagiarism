#include <bits/stdc++.h>
using namespace std;
const int sieve_size = 15000002;
bool sieve[sieve_size + 1];
vector<long long> prime;
void Sieve() {
  prime.push_back(2);
  for (int i = 3; i * i <= sieve_size; i += 2) {
    if (!sieve[i]) {
      long long p = i * 2;
      for (int j = i * i; j <= sieve_size; j += p) {
        sieve[j] = true;
      }
    }
  }
  for (int i = 3; i <= sieve_size; i += 2) {
    if (!sieve[i]) prime.push_back(i);
  }
}
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
inline int GA(long long n, vector<long long>& vec) {
  for (int i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    vec.push_back(x);
  }
  return 0;
}
inline int GAEG(long long m, vector<long long> vec[]) {
  for (int i = 0; i < m; ++i) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  return 0;
}
bool isvalid(long long xx, long long yy, long long n, long long m) {
  return (xx >= 0 && xx < n && yy >= 0 && yy < m);
}
long long pw(long long x, long long y) {
  if (y == 0) return 1;
  long long o = y / 2;
  long long f = pw(x, o);
  if (y % 2) {
    return (((f * f)) * x);
  } else
    return (f * f);
}
string s[60];
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    long long ans = 4;
    bool bl = false;
    for (int i = 0; i < n; ++i) {
      int p = s[i].find("A");
      if (p != -1) {
        bl = true;
        break;
      }
    }
    if (!bl) {
      cout << "MORTAL" << endl;
    } else {
      if (s[0].find("A") != -1 || s[n - 1].find("A") != -1) ans = 3;
      for (int i = 0; i < n; ++i) {
        if (s[i][0] == 'A' || s[i][m - 1] == 'A') {
          ans = 3;
          break;
        }
      }
      if (s[0][0] == 'A' || s[n - 1][0] == 'A' || s[n - 1][m - 1] == 'A' ||
          s[0][m - 1] == 'A')
        ans = 2;
      for (int i = 0; i < n; ++i) {
        bool qq = false;
        for (int j = 0; j < m; ++j) {
          if (s[i][j] != 'A') {
            qq = true;
            break;
          }
        }
        if (!qq) {
          if (i == 0 || i == n - 1)
            ans = 1;
          else
            ans = min(ans, 2ll);
        }
      }
      bool isP = false;
      for (int i = 0; i < m; ++i) {
        bool qq = false;
        for (int j = 0; j < n; ++j) {
          if (s[j][i] != 'A') {
            qq = true;
            isP = true;
            break;
          }
        }
        if (!qq) {
          if (i == 0 || i == m - 1)
            ans = 1;
          else
            ans = min(ans, 2ll);
        }
      }
      if (!isP)
        cout << 0 << endl;
      else
        cout << ans << endl;
    }
  }
  return 0;
}
