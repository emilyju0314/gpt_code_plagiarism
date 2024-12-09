#include <bits/stdc++.h>
using namespace std;
long long sqr(long long x) { return x * x; }
inline long long gcd(long long a, long long b) {
  while (b) {
    a %= b, swap(a, b);
  }
  return a;
}
inline long long lcm(long long a, long long b) {
  return a * b / max(1LL, gcd(a, b));
}
mt19937 Random((long long)time(0));
inline long long rnd(long long x) { return Random() % x; }
const long long INF = (long long)1e9 + 2017;
const long long MOD = (long long)1e9 + 7;
const long double EPS = 1e-10;
const long double PI = acos(-1.0);
vector<long long> st;
void $main() {
  long long n;
  cin >> n;
  long long a;
  cin >> a;
  st = {a};
  for (long long i = 1; i < n; i++) {
    cin >> a;
    while ((long long)(st).size() && st.back() == a) {
      st.pop_back();
      a++;
    }
    st.push_back(a);
  }
  cout << (long long)(st).size() << endl;
  for (long long i : st) {
    cout << i << " ";
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios_base::fixed, ios_base::floatfield);
  cout.precision(10);
  $main();
}
