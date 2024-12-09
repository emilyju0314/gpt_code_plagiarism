#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
double pi = acos((double)-1);
const int MOD = 1000000007;
const int INF = 2147483647;
long long binpow(int a, long long n) {
  long long res = 1;
  while (n)
    if (n & 1) {
      res = (res * a) % MOD;
      --n;
    } else {
      a = (a * 1ll * a) % MOD;
      n >>= 1;
    }
  return res;
}
int main() {
  clock_t tStart = clock();
  int tests = 1;
  for (int test = 1; test <= tests; test++) {
    string s;
    int n;
    cin >> s;
    cin >> n;
    vector<int> query_di(n + 1);
    vector<string> query_ti(n + 1);
    query_di[0] = 0;
    query_ti[0] = "0->" + s;
    for (int i = 1; i <= n; i++) {
      string query;
      cin >> query;
      int di = (int)(query[0] - '0');
      query_di[i] = di;
      query_ti[i] = query;
    }
    vector<int> val;
    vector<long long> len, lenwhole;
    for (int i = 0; i <= 9; i++) {
      val.push_back(i);
      len.push_back(1);
      lenwhole.push_back(10);
    }
    for (int i = n; i >= 0; i--) {
      int di = query_di[i], newvaldi = 0;
      long long newlendiwhole = 1;
      long long binpowres = 1;
      for (int j = query_ti[i].size() - 1; j >= 3; j--) {
        int tij = query_ti[i][j] - '0';
        newvaldi += (val[tij] * binpowres) % MOD;
        newvaldi %= MOD;
        long long mult = lenwhole[tij];
        binpowres *= mult;
        binpowres %= MOD;
        newlendiwhole *= mult;
        newlendiwhole %= MOD;
      }
      val[di] = newvaldi;
      lenwhole[di] = newlendiwhole;
    }
    cout << val[0] << endl;
  }
}
