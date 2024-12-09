/**
 *    author:  tourist
 *    created: 21.03.2020 16:03:59       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string foo;
  cin >> foo;
  vector<int> good(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    good[i] = (foo[i] == '1');
  }
  if (!good[0]) {
    cout << "Impossible" << '\n';
    return 0;
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (!(i & (1 << j)) && !good[i] && good[i | (1 << j)]) {
        cout << "Impossible" << '\n';
        return 0;
      }
    }
  }
  cout << "Possible" << '\n';
  if (good[(1 << n) - 1]) {
    cout << 0 << '\n';
    cout << "1 1" << '\n';
    return 0;
  }
  string path = "";
  for (int mask = 0; mask < (1 << n); mask++) {
    if (!good[mask]) {
      bool ok = true;
      for (int j = 0; j < n; j++) {
        if ((mask & (1 << j)) && !good[mask ^ (1 << j)]) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        continue;
      }
      string cur = "";
      for (int j = n - 1; j >= 0; j--) {
        char C = (char) ('A' + j);
        char c = (char) ('a' + j);
        if (mask & (1 << j)) {
          if (cur != "") {
            cur = C + cur + C + c + string(cur.rbegin(), cur.rend()) + c;
          } else {
            cur += C;
            cur += c;
          }
        } else {
          if (cur != "") {
            cur = C + cur + C;
          }
        }
      }
      path += cur;
      debug(mask, cur);
    }
  }
  debug(path);
  for (int t = 0; t < (1 << n); t++) {
    string tmp = path;
    for (char& c : tmp) {
      int d = (int) (toupper(c) - 'A');
      if (!(t & (1 << d))) {
        c = toupper(c);
      }
    }
    vector<char> st;
    for (char c : tmp) {
      if (!st.empty() && st.back() == c) {
        st.pop_back();
      } else {
        st.push_back(c);
      }
    }
    assert(st.empty() == good[t]);
  }
  vector<pair<int, int>> ret;
  ret.emplace_back(0, 0);
  for (char c : path) {
    int x = ret.back().first;
    int y = ret.back().second;
    if (isupper(c) && y == 0) {
      y = 1;
      ret.emplace_back(x, y);
    }
    if (islower(c) && y == 1) {
      y = 0;
      ret.emplace_back(x, y);
    }
    int z = (int) (toupper(c) - 'A');
    assert(z == x || z == x - 1);
    if (z == x) {
      ++x;
      ret.emplace_back(x, y);
    } else {
      --x;
      ret.emplace_back(x, y);
    }
  }
  assert(ret.back().first == 0);
  if (ret.back().second == 1) {
    ret.emplace_back(0, 0);
  }
  cout << ret.size() - 1 << '\n';
  for (auto& p : ret) {
    cout << p.first << " " << p.second << '\n';
  }
  return 0;
}
