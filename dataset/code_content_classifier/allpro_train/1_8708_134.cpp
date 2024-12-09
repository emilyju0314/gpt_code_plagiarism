#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int vi[100000], m, n, k, p1, p2, p3, p, f, t;
long long int powmod(long long int a1, long long int b1) {
  long long int res = 1;
  a1 %= mod;
  for (; b1; b1 >>= 1) {
    if (b1 & 1) res = res * a1 % mod;
    a1 = (a1 * a1) % mod;
  }
  return res;
}
vector<long long int> v[20000];
void dfs(long long int s) {
  vi[s] = 1;
  long long int x = v[s].size();
  for (long long int i1 = 0; i1 < (int)(x); i1++)
    if (!vi[v[s][i1]]) dfs(v[s][i1]);
}
int main() {
  cin >> n;
  for (long long int i = 0; i < (int)(n); i++) {
    cin >> p1;
    p1--;
    v[p1].push_back(i);
    v[i].push_back(p1);
  }
  long long int o = 0;
  for (long long int i = 0; i < (int)(n); i++) {
    if (!vi[i]) {
      o++;
      dfs(i);
    }
  }
  cout << o;
  return 0;
}
