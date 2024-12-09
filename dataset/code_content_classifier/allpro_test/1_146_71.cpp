#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(vector<T> a) {
  int n = a.size();
  for (long long i = 0; i < n; ++i) {
    cout << a[i] << (i == n - 1 ? "\n" : " ");
  }
}
int sum_vector(vector<int> v) { return accumulate(v.begin(), v.end(), 0); }
void sort_vector(vector<int> &v) { sort(v.begin(), v.end()); }
void sort_comp(vector<int> &v, bool func(int, int)) {
  sort(v.begin(), v.end(), func);
}
bool comp(int a, int b) { return a < b; }
struct CustomCompare {
  bool operator()(pair<int, int> lhs, pair<int, int> rhs) {
    return lhs.first > rhs.first;
  }
};
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  while (a) {
    long long temp = a;
    a = b % a;
    b = temp;
  }
  return abs(b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
string binary(long long num) {
  string ans = "";
  do {
    ans = to_string(num % 2) + ans;
    num /= 2;
  } while (num);
  return ans;
}
const int mxn = 5e5 + 7;
const int d = 18;
const int mill = 1e6 + 3;
const long long mod = 998244353;
long long pwr(long long num, long long p) {
  long long res = 1;
  while (p > 0) {
    if (p & 1) res = (res * num) % mod;
    num = (num * num) % mod;
    p /= 2;
  }
  return res;
}
long long inverse(long long num) { return pwr(num, mod - 2); }
long long get_rand(long long n) { return ((rand() << 15) + rand()) % n; }
void solve() {
  int n, q;
  const int step = 300;
  cin >> n >> q;
  vector<int> p(n + 1);
  vector<int> wtf(n + 1);
  vector<int> pws(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    wtf[p[i]] = i;
  }
  int temp;
  for (int i = 1; i <= n; i++) {
    temp = i;
    for (int s = 0; s < step; s++) {
      temp = p[temp];
    }
    pws[i] = temp;
  }
  int type;
  int x, y;
  int idx, k;
  vector<int> helpx(step + 1);
  vector<int> helpy(step + 1);
  for (int qq = 0; qq < q; qq++) {
    cin >> type;
    if (type == 1) {
      cin >> x >> y;
      temp = p[x];
      p[x] = p[y];
      p[y] = temp;
      wtf[p[x]] = x;
      wtf[p[y]] = y;
      helpx[0] = x;
      helpy[0] = y;
      for (int s = 1; s <= step; s++) {
        helpx[s] = p[helpx[s - 1]];
        helpy[s] = p[helpy[s - 1]];
      }
      pws[x] = helpx[step];
      pws[y] = helpy[step];
      for (int s = 1; s <= step; s++) {
        x = wtf[x];
        y = wtf[y];
        pws[x] = helpx[step - s];
        pws[y] = helpy[step - s];
      }
    } else {
      cin >> idx >> k;
      while (k >= step) {
        idx = pws[idx];
        k -= step;
      }
      for (int s = 0; s < k; s++) {
        idx = p[idx];
      }
      cout << idx << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  for (int ii = 1; ii <= t; ii++) {
    solve();
  }
  return 0;
}
