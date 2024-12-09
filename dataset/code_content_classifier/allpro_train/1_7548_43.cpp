#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353ll;
string S, T;
vector<vector<long long>> memo, memo2;
long long modpow(long long b, long long e) {
  long long ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}
long long solve2(int is, int start, int end) {
  if (is == -1) return 1;
  if (memo2[start][end] != -1) return memo2[start][end];
  long long res1 = 0, res2 = 0;
  if (S[is] == T[start]) res1 = solve2(is - 1, start + 1, end);
  if (S[is] == T[end]) res2 = solve2(is - 1, start, end - 1);
  return memo2[start][end] = (res1 + res2) % mod;
}
long long solve(int is, int it) {
  if (it == (int)(T).size()) return modpow(2, is + 1);
  if (is + 1 < (int)(T).size() - it) return 0;
  if (is + 1 == (int)(T).size() - it)
    return solve2(is, it, (int)(T).size() - 1);
  if (memo[is][it] != -1) return memo[is][it];
  long long res = solve(is - 1, it);
  if (S[is] == T[it]) res = (res + solve(is - 1, it + 1)) % mod;
  return memo[is][it] = res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> S >> T;
  memo = vector<vector<long long>>((int)(S).size(),
                                   vector<long long>((int)(T).size(), -1));
  memo2 = vector<vector<long long>>((int)(T).size(),
                                    vector<long long>((int)(T).size(), -1));
  long long ans = 0;
  for (int i = 0; i < ((int)(S).size()); i++) {
    int is = (int)(S).size() - 1 - i;
    if (is + 1 < (int)(T).size()) break;
    if (is + 1 == (int)(T).size()) {
      ans = (ans + (i + 1) * solve2(is, 0, (int)(T).size() - 1)) % mod;
      break;
    }
    if (S[(int)(S).size() - 1 - i] == T[0]) {
      ans = (ans + (i + 1) * solve(is - 1, 1)) % mod;
    }
  }
  cout << ans << '\n';
  return 0;
}
