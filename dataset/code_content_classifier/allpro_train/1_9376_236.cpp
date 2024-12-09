#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
using namespace chrono;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int advceil(long long int num, long long int den) {
  return (num % den == 0 ? num / den : num / den + 1);
}
long long int lstbt(long long int val) {
  long long int msk = val & (val - 1);
  return log2(val ^ msk);
}
long long int modmul(long long int a, long long int b) {
  return (a * b) % 998244353;
}
long long int modexpo(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = modmul(res, a);
    a = modmul(a, a);
    b /= 2;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return a == 0 ? b : gcd(b % a, a);
}
vector<long long int> CALCfactor(long long int n) {
  vector<long long int> factor(n + 2, 0);
  for (long long int i = 4; i <= n; i += 2) factor[i] = 2;
  for (long long int j = 3; j <= n; j += 2) {
    if (factor[j]) continue;
    for (long long int i = 2 * j; i <= n; i += j) factor[i] = j;
  }
  return factor;
}
vector<long long int> CALCprimeNUM(long long int n) {
  vector<long long int> factor = CALCfactor(n);
  vector<long long int> primeNUM;
  primeNUM.reserve(n + 2);
  for (long long int i = 2; i <= n; i++)
    if (!factor[i]) primeNUM.push_back(i);
  return primeNUM;
}
vector<long long int> CALCprimeFACTOR(long long int n) {
  vector<long long int> factor = CALCfactor(n);
  vector<long long int> ans;
  while (factor[n] != 0) {
    ans.push_back(factor[n]);
    n /= factor[n];
  }
  if (n > 1) ans.push_back(n);
  return ans;
}
vector<long long int> unique(vector<long long int> x) {
  sort(x.begin(), x.end());
  set<long long int> s;
  vector<long long int> ans;
  ans.reserve(x.size());
  for (auto elem : x) s.insert(elem);
  for (auto elem : s) ans.push_back(elem);
  return ans;
}
pair<vector<long long int>, vector<long long int> > getFact(long long int n) {
  vector<long long int> fact(n + 1, 1), invfact(n + 1, 1);
  for (long long int i = 1; i <= n; i++)
    fact[i] = (i * (fact[i - 1])) % 998244353;
  for (long long int i = 1; i <= n; i++)
    invfact[i] = (modexpo(i, 998244353 - 2) * invfact[i - 1]) % 998244353;
  return {fact, invfact};
}
void compress(vector<long long int>& arr, long long int n) {
  map<long long int, vector<long long int> > pos;
  for (long long int i = 1; i <= n; i++) pos[arr[i]].push_back(i);
  long long int cnt = 1;
  for (auto itr : pos) {
    for (auto elem : itr.second) arr[elem] = cnt;
    cnt++;
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(2 * n);
  for (long long int i = 0; i < 2 * n; i++) cin >> arr[i];
  ;
  sort(arr.begin(), arr.end());
  pair<vector<long long int>, vector<long long int> > EF = getFact(2 * n + 2);
  long long int res =
      ((EF.first[2 * n] * EF.second[n]) % 998244353 * EF.second[n]) % 998244353;
  long long int ans = 0;
  for (long long int i = 0; i < n; i++)
    ans += abs(arr[i] - arr[2 * n - i - 1]), ans %= 998244353;
  cout << (ans * res) % 998244353 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
}
