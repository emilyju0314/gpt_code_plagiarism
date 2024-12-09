#include <bits/stdc++.h>
using namespace std;
class SA_IS {
  vector<int> compress(vector<int>& v) {
    set<int> alph(v.begin(), v.end());
    vector<int> dic(alph.begin(), alph.end());
    vector<int> bucket_size(dic.size(), 0);
    for (int i = 0; i < v.size(); i++) {
      v[i] = lower_bound(dic.begin(), dic.end(), v[i]) - dic.begin();
      bucket_size[v[i]]++;
    }
    return bucket_size;
  }
  class bucket_set {
    vector<int> container;
    vector<vector<int>::iterator> bucket;
    vector<int> front;
    vector<int> back;
    vector<bool> fixed;
    vector<vector<bool>::iterator> bucket_fixed;
    vector<bool> used;
    const vector<int>& str;
    const vector<int>& bucket_size;
    const vector<int>& LS;
    void put_L() {
      for (int i = 0; i < bucket_size.size(); i++) {
        for (int j = 0; j < bucket_size[i]; j++) {
          if (bucket[i][j] - 1 < 0) continue;
          if (LS[bucket[i][j] - 1] == L) {
            if (used[bucket[i][j] - 1]) continue;
            used[bucket[i][j] - 1] = true;
            int c = str[bucket[i][j] - 1];
            bucket[c][front[c]] = bucket[i][j] - 1;
            bucket_fixed[c][front[c]] = true;
            front[c]++;
          }
        }
        back[i] = bucket_size[i] - 1;
      }
    }
    void put_S() {
      for (int i = bucket_size.size() - 1; i >= 0; i--) {
        for (int j = bucket_size[i] - 1; j >= 0; j--) {
          if (bucket[i][j] - 1 < 0) continue;
          if (LS[bucket[i][j] - 1] == S) {
            if (used[bucket[i][j] - 1]) continue;
            used[bucket[i][j] - 1] = true;
            int c = str[bucket[i][j] - 1];
            bucket[c][back[c]] = bucket[i][j] - 1;
            bucket_fixed[c][back[c]] = true;
            back[c]--;
          }
        }
      }
    }
    void init() {
      int sum = 0;
      for (int i = 0; i < bucket_size.size(); i++) {
        bucket[i] = container.begin() + sum;
        bucket_fixed[i] = fixed.begin() + sum;
        front[i] = 0;
        back[i] = bucket_size[i] - 1;
        sum += bucket_size[i];
      }
    }

   public:
    bucket_set(const vector<int>& str_, const vector<int>& bucket_size_,
               const vector<int>& LS_)
        : container(str_.size(), -1),
          bucket(bucket_size_.size()),
          front(bucket_size_.size()),
          back(bucket_size_.size()),
          fixed(str_.size(), false),
          bucket_fixed(bucket_size_.size()),
          used(str_.size(), false),
          str(str_),
          bucket_size(bucket_size_),
          LS(LS_) {
      init();
    }
    void put_initial_LMS(const vector<int>& LMS_pos) {
      for (int i = 0; i < LMS_pos.size() - 1; i++) {
        int c = str[LMS_pos[i]];
        bucket[c][back[c]] = LMS_pos[i];
        back[c]--;
      }
    }
    void put_ordered_LMS(const vector<int>& LMS_pos) {
      for (int i = LMS_pos.size() - 2; i >= 0; i--) {
        int c = str[LMS_pos[i]];
        bucket[c][back[c]] = LMS_pos[i];
        back[c]--;
      }
    }
    void put() {
      put_L();
      for (int i = 0; i < str.size(); i++)
        if (fixed[i] == false) container[i] = -1;
      put_S();
      container[0] = str.size() - 1;
    }
    vector<int> get_LMS_substring_order(const vector<int>& LMS) {
      vector<int> ret;
      for (int i = 0; i < str.size(); i++) {
        if (LS[container[i]] != S) continue;
        if (container[i] > 0 && LS[container[i] - 1] == L)
          ret.push_back(container[i]);
      }
      return ret;
    }
    vector<int> get_result() { return container; }
  };
  struct substring {
    int pos;
    int size;
    vector<int>::iterator str;
    vector<int>::iterator ls;
    substring() {}
    substring(const int pos, const int size, const vector<int>::iterator& str,
              const vector<int>::iterator& ls) {
      this->pos = pos;
      this->size = size;
      this->str = str;
      this->ls = ls;
    }
    bool operator==(const substring& x) const {
      for (int i = 0; i < min(this->size, x.size); i++) {
        if (this->str[i] != x.str[i]) {
          return false;
        } else if (this->ls[i] != x.ls[i]) {
          return false;
        }
      }
      return this->size == x.size;
    }
  };

 public:
  static const int L = 0;
  static const int S = 1;
  string my_s;
  vector<int> sa;
  vector<int> lcp;
  vector<int> rec(vector<int>& v) {
    v.push_back(-1);
    vector<int> bucket_size = compress(v);
    vector<int> LS(v.size());
    LS.back() = S;
    for (int i = v.size() - 2; i >= 0; i--) {
      if (v[i] < v[i + 1])
        LS[i] = S;
      else if (v[i] > v[i + 1])
        LS[i] = L;
      else
        LS[i] = LS[i + 1];
    }
    bucket_set my_bucket(v, bucket_size, LS);
    vector<int> LMS;
    for (int i = 1; i < v.size(); i++) {
      if (LS[i] != S) continue;
      if (LS[i - 1] == L) LMS.push_back(i);
    }
    LMS.push_back(v.size() - 1);
    vector<int> LMS_substring_order(v.size(), -1);
    vector<int> LMS_substring_end(v.size(), -1);
    for (int i = 0; i < LMS.size() - 1; i++) {
      LMS_substring_order[LMS[i]] = i;
      LMS_substring_end[LMS[i]] = LMS[i + 1];
    }
    if (LMS.size() > 1) {
      bucket_set LMS_bucket(v, bucket_size, LS);
      LMS_bucket.put_initial_LMS(LMS);
      LMS_bucket.put();
      vector<int> LMS_order = LMS_bucket.get_LMS_substring_order(LMS);
      vector<int> LMS_order_cnt(LMS_order.size());
      int cnt = 0;
      LMS_order_cnt[0] = 0;
      cnt++;
      for (int i = 1; i < LMS_order.size(); i++, cnt++) {
        substring a(LMS_order[i],
                    LMS_substring_end[LMS_order[i]] - LMS_order[i] + 1,
                    v.begin() + LMS_order[i], LS.begin() + LMS_order[i]);
        substring b(LMS_order[i - 1],
                    LMS_substring_end[LMS_order[i - 1]] - LMS_order[i - 1] + 1,
                    v.begin() + LMS_order[i - 1],
                    LS.begin() + LMS_order[i - 1]);
        if (a == b) cnt--;
        LMS_order_cnt[i] = cnt;
      }
      vector<int> tmp(LMS_order.size());
      for (int i = 0; i < LMS_order.size(); i++) {
        tmp[LMS_substring_order[LMS_order[i]]] = LMS_order_cnt[i];
      }
      swap(tmp, LMS_order);
      if (cnt != LMS_order.size()) {
        vector<int> new_order = rec(LMS_order);
        LMS_order = vector<int>(new_order.begin() + 1, new_order.end());
      }
      tmp = LMS;
      for (int i = 0; i < LMS.size() - 1; i++) {
        tmp[i] = LMS[LMS_order[i]];
      }
      swap(tmp, LMS);
      my_bucket.put_ordered_LMS(LMS);
    }
    my_bucket.put();
    return my_bucket.get_result();
  }
  vector<int> rec(string& s) {
    vector<int> v(s.begin(), s.end());
    return rec(v);
  }
  void constract_lcp() {
    int n = my_s.size();
    lcp.resize(n + 1);
    vector<int> rank(n + 1);
    for (int i = 0; i <= n; i++) rank[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
      int j = sa[rank[i] - 1];
      if (h > 0) h--;
      for (; j + h < n && i + h < n; h++) {
        if (my_s[j + h] != my_s[i + h]) break;
      }
      lcp[rank[i] - 1] = h;
    }
  }
  SA_IS(string s) {
    my_s = s;
    sa = rec(s);
  }
  void dbg_print() {
    for (int i = 0; i <= my_s.size(); i++) {
      string p(my_s.begin() + sa[i], my_s.end());
      cerr << p << " " << sa[i] << endl;
    }
  }
};
class SegmentTreeMIN {
  int n;
  vector<int> T;
  int INF;

 public:
  SegmentTreeMIN(int size) {
    INF = 1 << 29;
    n = 1;
    while (n < size) n <<= 1;
    T.resize(2 * n - 1);
    fill(T.begin(), T.end(), INF);
  }
  void update(int k, int val) {
    k += n - 1;
    T[k] = val;
    while (k > 0) {
      k = (k - 1) / 2;
      T[k] = min(T[k * 2 + 1], T[k * 2 + 2]);
    }
  }
  int RMQ(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b)
      return T[k];
    else {
      int val_left = RMQ(a, b, k * 2 + 1, l, (l + r) / 2);
      int val_right = RMQ(a, b, k * 2 + 2, (l + r) / 2, r);
      return min(val_left, val_right);
    }
  }
  int size() { return n; }
};
int main() {
  string s;
  cin >> s;
  int n = s.size();
  s += s;
  SA_IS sa(s);
  vector<int> arr(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == '(') {
      arr[i] = 1;
    } else {
      arr[i] = -1;
    }
    if (i > 0) arr[i] += arr[i - 1];
  }
  SegmentTreeMIN seg(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    seg.update(i, arr[i]);
  }
  int index = -1;
  int len = 1 << 30;
  int xx = 0;
  int yy = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (sa.sa[i] > n) continue;
    int x = min(0, seg.RMQ(sa.sa[i], sa.sa[i] + n, 0, 0, seg.size()) -
                       (sa.sa[i] > 0 ? arr[sa.sa[i] - 1] : 0));
    int y = max(0, arr[sa.sa[i] + n - 1] -
                       (sa.sa[i] > 0 ? arr[sa.sa[i] - 1] : 0) + abs(x));
    if (len > abs(x) + abs(y) + n) {
      index = i;
      len = abs(x) + abs(y) + n;
      xx = abs(x);
      yy = abs(y);
    }
  }
  string ans;
  for (int j = 0; j < xx; j++) {
    printf("(");
  }
  cout << s.substr(sa.sa[index], n);
  for (int j = 0; j < yy; j++) {
    printf(")");
  }
  printf("\n");
  return 0;
}
