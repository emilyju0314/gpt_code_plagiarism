#include <bits/stdc++.h>
using namespace std;
template <typename T>
void resize(int n, vector<T> &u) {
  u.resize(n);
}
template <typename Head, typename... Tail>
void resize(int n, Head &H, Tail &...T) {
  resize(n, H);
  resize(n, T...);
}
template <typename T>
void debug_out(T t) {
  cerr << t;
}
template <typename A, typename B>
void debug_out(pair<A, B> &u) {
  cerr << "(" << u.first << " " << u.second << ")";
}
template <typename T>
void debug_out(vector<T> &t) {
  int sz = t.size();
  for (int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if (i != sz - 1) cerr << ", ";
  }
}
template <typename T>
void debug_out(vector<vector<T>> &t) {
  int sz = t.size();
  for (int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if (i != sz - 1) cerr << endl;
  }
}
vector<char> lowchar = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                        's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
vector<char> hichar = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                       'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                       'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<char> base_10 = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
template <typename T>
string to_string(T t) {
  ostringstream ss;
  ss << t;
  return ss.str();
}
long long to_num(string t) {
  long long res = 0;
  for (int i = 0; i < (int)t.length(); i++) {
    res *= 10;
    res += t[i] - '0';
  }
  return res;
}
int n;
vector<int> t, dp;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  resize(n, t);
  resize(n + 1, dp);
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 1; i < n + 1; i++) {
    dp[i] = dp[i - 1] + 20;
    auto u = upper_bound(t.begin(), t.end(), t[i - 1] - 90),
         v = upper_bound(t.begin(), t.end(), t[i - 1] - 1440);
    int x = u - t.begin(), y = v - t.begin();
    dp[i] = min(dp[x] + 50, dp[i]);
    dp[i] = min(dp[y] + 120, dp[i]);
  }
  for (int i = 1; i <= n; i++) cout << dp[i] - dp[i - 1] << endl;
  return 0;
}
