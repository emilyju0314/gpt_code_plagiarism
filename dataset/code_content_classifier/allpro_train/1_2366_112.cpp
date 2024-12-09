#include <bits/stdc++.h>
using namespace std;
class SuffixArray {
 public:
  SuffixArray(const string& s) : s(s), sa(s.size() + 1), rank(s.size() + 1) {
    size = 1;
    while (size < sa.size()) {
      size *= 2;
    }
    assert(size >= sa.size());
    min_idx.resize(2 * size - 1);
    max_idx.resize(2 * size - 1);
    fill(min_idx.begin(), min_idx.end(), INT_MAX);
    fill(max_idx.begin(), max_idx.end(), INT_MIN);
  }
  void Init() {
    for (int i = 0; i <= s.size(); ++i) {
      sa[i] = i;
      rank[i] = (i < s.size()) ? s[i] : -1;
    }
    for (int len = 1; len <= s.size() + 1; len *= 2) {
      Compare comp(len, rank);
      sort(sa.begin(), sa.end(), comp);
      vector<int> tmp(sa.size());
      tmp[sa[0]] = 0;
      for (int i = 1; i < sa.size(); ++i) {
        tmp[sa[i]] = tmp[sa[i - 1]] + (comp(sa[i - 1], sa[i]) ? 1 : 0);
      }
      for (int i = 0; i < tmp.size(); ++i) {
        rank[i] = tmp[i];
      }
    }
    for (int i = 0; i < sa.size(); ++i) {
      Insert(i, sa[i]);
    }
  }
  void Insert(int idx, int value) {
    idx += size - 1;
    min_idx[idx] = value;
    max_idx[idx] = value;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      min_idx[idx] = min(min_idx[2 * idx + 1], min_idx[2 * idx + 2]);
      max_idx[idx] = max(max_idx[2 * idx + 1], max_idx[2 * idx + 2]);
    }
  }
  void DoQuery(int idx, int ql, int qr, int l, int r, int& min_val,
               int& max_val) {
    assert(l < r);
    if (idx >= min_idx.size()) {
      return;
    }
    if (qr <= l || r <= ql) {
      return;
    }
    if (ql <= l && r <= qr) {
      min_val = min(min_val, min_idx[idx]);
      max_val = max(max_val, max_idx[idx]);
      return;
    }
    DoQuery(2 * idx + 1, ql, qr, l, (l + r) / 2, min_val, max_val);
    DoQuery(2 * idx + 2, ql, qr, (l + r) / 2, r, min_val, max_val);
  }
  void Query(int ql, int qr, int& min_val, int& max_val) {
    min_val = INT_MAX;
    max_val = INT_MIN;
    DoQuery(0, ql, qr, 0, size, min_val, max_val);
  }
  int Find(const string& needle, bool lower) {
    int l = 0, r = sa.size();
    while (l + 1 < r) {
      int c = (l + r) / 2;
      if (lower ? (s.compare(sa[c], string::npos, needle) < 0)
                : (s.compare(sa[c], needle.size(), needle) <= 0)) {
        l = c;
      } else {
        r = c;
      }
    }
    return r;
  }
  void FindMinMax(const string& needle, int& min_val, int& max_val) {
    Query(Find(needle, true), Find(needle, false), min_val, max_val);
  }
  struct Compare {
    int len;
    const vector<int>& rank;
    Compare(int len, const vector<int>& rank) : len(len), rank(rank) {}
    bool operator()(int lhs, int rhs) {
      if (rank[lhs] != rank[rhs]) {
        return rank[lhs] < rank[rhs];
      } else {
        const int lhs_val = lhs + len < rank.size() ? rank[lhs + len] : -1;
        const int rhs_val = rhs + len < rank.size() ? rank[rhs + len] : -1;
        return lhs_val < rhs_val;
      }
    }
  };
  string s;
  int size;
  vector<int> sa;
  vector<int> rank;
  vector<int> min_idx;
  vector<int> max_idx;
};
int main() {
  string s;
  cin >> s;
  SuffixArray sa(s);
  sa.Init();
  int m;
  cin >> m;
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    string p;
    cin >> p;
    bool valid = false;
    for (int j = 1; j < p.size(); ++j) {
      int min_x, max_x, min_y, max_y;
      sa.FindMinMax(p.substr(0, j), min_x, max_x);
      sa.FindMinMax(p.substr(j), min_y, max_y);
      if (min_x != INT_MAX && max_y != INT_MIN && min_x + j <= max_y) {
        valid = true;
        break;
      }
    }
    if (valid) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
