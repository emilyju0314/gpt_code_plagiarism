#include <bits/stdc++.h>
using namespace std;
template <typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  typename vector<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  typename set<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &v) {
  os << "[";
  typename unordered_set<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, const map<F, S> &v) {
  os << "[";
  typename map<F, S>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  return os << "]";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, const unordered_map<F, S> &v) {
  os << "[";
  typename unordered_map<F, S>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  return os << "]";
}
int n, k;
vector<string> a;
vector<pair<int, int> > cb, rb;
void read_input() {
  cin >> n >> k;
  a.resize(n);
  cb.resize(n, {INT_MAX, INT_MIN});
  rb.resize(n, {INT_MAX, INT_MIN});
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 'B') {
        cb[j].first = min(cb[j].first, i);
        cb[j].second = max(cb[j].second, i);
        rb[i].first = min(rb[i].first, j);
        rb[i].second = max(rb[i].second, j);
      }
    }
  }
}
int white_lines() {
  long long lines = 0;
  for (int i = 0; i < n; i++) {
    if (cb[i].first == INT_MAX && cb[i].second == INT_MIN) lines++;
    if (rb[i].first == INT_MAX && rb[i].second == INT_MIN) lines++;
  }
  return lines;
}
void solve() {
  int lines = white_lines(), curr_lines, max_lines = 0;
  vector<vector<int> > lines_c(n, vector<int>(n, 0)),
      lines_r(n, vector<int>(n, 0));
  for (int i = 0; i <= n - k; i++) {
    curr_lines = 0;
    for (int t = 0; t < k; t++) {
      if (cb[t].first != INT_MAX && cb[t].first >= i && cb[t].second < i + k)
        curr_lines++;
    }
    lines_c[i][0] = max(lines_c[i][0], curr_lines);
    for (int j = 1; j <= n - k; j++) {
      if (cb[j - 1].first != INT_MAX && cb[j - 1].first >= i &&
          cb[j - 1].second < i + k)
        curr_lines--;
      if (cb[j + k - 1].first != INT_MAX && cb[j + k - 1].first >= i &&
          cb[j + k - 1].second < i + k)
        curr_lines++;
      lines_c[i][j] = max(lines_c[i][j], curr_lines);
    }
  }
  for (int i = 0; i <= n - k; i++) {
    curr_lines = 0;
    for (int t = 0; t < k; t++) {
      if (rb[t].second != INT_MIN && rb[t].first >= i && rb[t].second < i + k)
        curr_lines++;
    }
    lines_r[0][i] = max(lines_r[0][i], curr_lines);
    for (int j = 1; j <= n - k; j++) {
      if (rb[j - 1].first != INT_MAX && rb[j - 1].first >= i &&
          rb[j - 1].second < i + k)
        curr_lines--;
      if (rb[j + k - 1].first != INT_MAX && rb[j + k - 1].first >= i &&
          rb[j + k - 1].second < i + k)
        curr_lines++;
      lines_r[j][i] = max(lines_r[j][i], curr_lines);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      max_lines = max(max_lines, lines_c[i][j] + lines_r[i][j]);
    }
  }
  cout << lines + max_lines << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  read_input();
  solve();
  return 0;
}
