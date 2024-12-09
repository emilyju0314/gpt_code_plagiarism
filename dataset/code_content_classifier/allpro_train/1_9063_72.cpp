#include <bits/stdc++.h>
void quit();
using namespace std;
const long double PI = acos(-1);
const long double EPS = 1e-10;
double __t;
long long powSum[16];
bool largest[16];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    largest[s[0] - 'a'] = 1;
    long long curPow = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
      powSum[s[i] - 'a'] += curPow;
      curPow *= 10;
    }
  }
  vector<int> p;
  for (int i = 0; i < 10; ++i) {
    p.push_back(i);
  }
  long long ans = numeric_limits<long long>::max();
  do {
    bool ok = 1;
    for (int i = 0; i < 10; ++i) {
      if (p[i] == 0 && largest[i]) ok = 0;
    }
    if (!ok) continue;
    long long cur = 0;
    for (int i = 0; i < 10; ++i) {
      cur += p[i] * powSum[i];
    }
    ans = min(ans, cur);
  } while (next_permutation(p.begin(), p.end()));
  cout << ans;
  quit();
}
void quit() { exit(0); }
