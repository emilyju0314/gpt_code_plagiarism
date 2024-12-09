#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<T> &operator+=(vector<T> &v, T x) {
  v.push_back(x);
  return v;
}
void solve() {
  int arr[91];
  memset(arr, 0, sizeof(arr));
  string s1, s2, s;
  cin >> s1 >> s2 >> s;
  for (int i = (0), _b_ = (s.length()); i < _b_; i++) arr[s[i]]++;
  for (int i = (0), _b_ = (s1.length()); i < _b_; i++) {
    if (arr[s1[i]] == 0) {
      cout << "NO";
      return;
    }
    arr[s1[i]]--;
  }
  for (int i = (0), _b_ = (s2.length()); i < _b_; i++) {
    if (arr[s2[i]] == 0) {
      cout << "NO";
      return;
    }
    arr[s2[i]]--;
  }
  for (int i = (65), _b_ = (91); i < _b_; i++) {
    if (arr[i] != 0) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
