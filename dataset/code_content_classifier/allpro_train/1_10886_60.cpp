#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 3;
string toString(long long n) {
  string res;
  for (; n > 0; n /= 10) {
    int now = n % 10;
    res += char(now + '0');
  }
  reverse(res.begin(), res.end());
  return res;
}
map<long long, string> repr;
map<long long, set<long long>> fromSize;
void mapPlease(long long x, const string& str) {
  if (toString(x).size() <= str.size()) {
    return;
  }
  if (!repr.count(x)) {
    repr[x] = str;
    fromSize[repr[x].size()].insert(x);
    return;
  }
  if (str.size() < repr[x].size()) {
    fromSize[repr[x].size()].erase(x);
    if (fromSize[repr[x].size()].empty()) {
      fromSize.erase(repr[x].size());
    }
    repr[x] = str;
    fromSize[repr[x].size()].insert(x);
  }
}
string get(long long x) {
  if (repr.count(x)) return repr[x];
  return toString(x);
}
long long Pow(long long a, long long b) {
  long long res = 1;
  for (int(i) = (0); (i) < (b); (i)++) res *= a;
  return res;
}
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(0);
  long long n;
  cin >> n;
  int nLen = toString(n).size();
  for (long long x = 2; x * x <= n; x++) {
    int p = 2;
    long long now = x * x;
    for (; now <= n;) {
      string tmp = toString(x) + "^" + toString(p);
      mapPlease(now, tmp);
      now *= x;
      p++;
    }
  }
  for (auto& d : repr) {
    int now = d.second.size();
    int left = 7 - now;
    if (left <= 0) continue;
    for (int len = 1; len <= left; len++) {
      for (auto& d2 : fromSize[len]) {
        long long have = d.first * d2;
        if (have > n) break;
        string tmp = d.second + "*" + repr[d2];
        mapPlease(have, tmp);
      }
    }
  }
  for (auto& d : repr) {
    if (d.second.size() >= 5) continue;
    long long aMax = (n + d.first - 1) / d.first;
    for (long long a = 2; a <= min(aMax, (long long)1e4); a++) {
      long long now = a * d.first;
      string tmp = get(a) + "*" + d.second;
      mapPlease(now, tmp);
    }
  }
  string ans = toString(n);
  if (repr.count(n)) {
    ans = repr[n];
  }
  for (auto& d : repr) {
    long long now = d.first;
    if (now > n) break;
    long long rem = n - now;
    string tmp;
    if (repr.count(rem)) {
      tmp = repr[rem];
    } else {
      tmp = toString(rem);
    }
    string res = repr[now] + "+" + tmp;
    if (res.size() < ans.size()) {
      ans = res;
    }
  }
  for (long long a = 1; a <= 1e5; a++) {
    if (n % a != 0) continue;
    long long div = n / a;
    string tmp;
    if (repr.count(div)) {
      tmp = repr[div];
    } else {
      tmp = toString(div);
    }
    string res = toString(a) + "*" + tmp;
    if (res.size() < ans.size()) {
      ans = res;
    }
  }
  cout << ans << endl;
  return 0;
}
