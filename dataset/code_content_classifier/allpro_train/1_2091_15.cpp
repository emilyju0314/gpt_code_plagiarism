#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  auto rewrite = [](string a) {
    int n = a.size();
    map<string, char> m;
    m["00"] = '0';
    m["11"] = '1';
    m["10"] = '2';
    m["01"] = '3';
    string res = "";
    for (int i = 0; i < n; i += 2) {
      res += m[a.substr(i, 2)];
    }
    return res;
  };
  while (t--) {
    string a, b;
    cin >> a >> b;
    a = rewrite(a);
    b = rewrite(b);
    string init_b = b;
    auto get_freq = [&](string &a) {
      map<char, int> m;
      for (auto val : a) m[val] += 1;
      return m;
    };
    auto f_a = get_freq(a);
    auto f_b = get_freq(b);
    if (f_a['1'] != f_b['1'] or f_a['0'] != f_b['0']) {
      cout << "-1\n";
      continue;
    }
    auto good = [](string &a, string &b) -> bool {
      return count(a.begin(), a.end(), '2') == count(b.begin(), b.end(), '3');
    };
    auto apply = [](string &a, int poz) {
      reverse(a.begin(), a.begin() + poz + 1);
      for (int i = 0; i < poz + 1; i += 1) {
        if (a[i] == '2') {
          a[i] = '3';
        } else if (a[i] == '3') {
          a[i] = '2';
        }
      }
    };
    int m = a.size();
    int last = -1;
    vector<int> sol;
    if (not good(a, b)) {
      for (int it = 0; it < m; it += 1) {
        apply(a, it);
        if (good(a, b)) {
          sol.push_back(it);
          break;
        } else {
          apply(a, it);
        }
      }
      if (not good(a, b)) {
        for (int it = 0; it < m; it += 1) {
          apply(b, it);
          if (good(a, b)) {
            last = it;
            break;
          } else {
            apply(b, it);
          }
        }
      }
    }
    auto type = [](char a) { return a >= '0' and a <= '1'; };
    auto matches = [&](char x, char y) {
      assert(x >= '0' and x <= '3' and y >= '0' and y <= '3');
      if (type(x) != type(y)) return false;
      if (type(x)) return x == y;
      return x != y;
    };
    for (int i = m - 1; i >= 0; i -= 1) {
      bool found = false;
      for (int k = m - i - 1; k < m and not found; k += 1)
        if (matches(a[k], b[i])) {
          if (k - 1 >= 0) {
            sol.push_back(k - 1);
            apply(a, k - 1);
          }
          apply(a, k);
          sol.push_back(k);
          found = true;
        }
      assert(found);
    }
    if (last >= 0) {
      sol.push_back(last);
      apply(a, last);
    }
    assert(a == init_b);
    cout << sol.size() << "\n";
    for (auto val : sol) cout << (val + 1) * 2 << " ";
    cout << "\n";
  }
}
