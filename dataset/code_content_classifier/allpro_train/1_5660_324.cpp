#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const long long MOD = 1000000007ll;
const long double PI = acos(-1.0);
const long long INF = 2000000000000000000ll;
const long double EPS = 1e-9;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
T sqr(T a) {
  return a * a;
}
bool pal(string &x) {
  int n = x.length();
  for (int i = 0; i < n / 2; i++) {
    if (x[i] != x[n - i - 1]) return 0;
  }
  return 1;
}
int a[111111];
stack<int> st;
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int answer = 0;
  for (int i = 0; i < n; i++) {
    while (!st.empty()) {
      int x = st.top();
      answer = max(answer, x ^ a[i]);
      if (x > a[i]) break;
      st.pop();
    }
    st.push(a[i]);
  }
  cout << answer;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  getchar();
  getchar();
  return 0;
}
