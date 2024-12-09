#include <bits/stdc++.h>
using namespace std;
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
const int N = 2010;
const int M = 2010;
long long dp[N + 1][M + 1];
void calc() {
  for (int j = (int)(1); j <= (int)(M); j++) dp[1][j] = 1;
  for (int i = (int)(2); i <= (int)(N); i++) {
    long long cumSum = 0;
    dp[i][1] = 1;
    for (int j = (int)(2); j <= (int)(M); j++) {
      (cumSum += dp[i - 1][j]) %= 1000000007;
      dp[i][j] = (dp[i][j - 1] + cumSum) % 1000000007;
    }
  }
}
int main() {
  calc();
  int n, m;
  cin >> n >> m;
  long long answer1 = 0;
  for (int i = (int)(1); i <= (int)(n); i++) {
    for (int j = (int)(2); j <= (int)(m); j++) {
      answer1 =
          (answer1 + (((m - j + 1) * (dp[i][j] - dp[i - 1][j] + 1000000007)) %
                      1000000007 * dp[n - i + 1][j]) %
                         1000000007) %
          1000000007;
    }
  }
  cout << answer1 << "\n";
}
