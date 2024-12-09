#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
const int inf = 1000000007;
const long long llinf = 800000000000000119;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int __builtin_popcount(long long x) {
  int res = 0;
  while (x) {
    res += x & 1;
    x >>= 1;
  }
  return res;
}
string to_string(string s) {
  return '"' + s + '"';
  return s;
}
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) {
  return (b ? "true" : "false");
  return to_string((int)b);
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <class T>
ostream& operator<<(ostream& stream, vector<T> v) {
  for (T i : v) {
    stream << i << " ";
  }
  stream << "\b";
  return stream;
}
void hi() { printf("hi\n"); }
void hi(string flag) {
  cerr << "["
       << "\"hi (%s)\\n\", flag.c_str()"
       << "]:",
      debug_out("hi (%s)\n", flag.c_str());
}
int n;
int main() {
  string s;
  cin >> s;
  n = s.size();
  int bad = 2;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] < '7') {
      bad = 0;
      break;
    }
    if (s[i] > '7') {
      bad = 1;
      break;
    }
  }
  if (bad == 2) {
    for (int i = n / 2; i < n; i++) {
      if (s[i] < '4') {
        bad = 0;
        break;
      }
      if (s[i] > '4') break;
    }
  }
  if (n % 2 == 1 || bad) {
    for (int i = 0; i < (n + 2) / 2; i++) {
      cout << 4;
    }
    for (int i = 0; i < (n + 2) / 2; i++) {
      cout << 7;
    }
    cout << endl;
    return 0;
  }
  int ind = 0, num4 = 0, num7 = 0;
  string ans;
  while (ind < n) {
    if (s[ind] == '4')
      num4++;
    else if (s[ind] == '7')
      num7++;
    else
      break;
    ans += s[ind];
    ind++;
  }
  if (ind < n) {
    if (s[ind] > '7') {
      int x = ind - 1;
      while (x >= 0 && ans[x] == '7') {
        ans[x] = '4';
        num7--;
        num4++;
        x--;
      }
      ans[x] = '7';
      num4--;
      num7++;
    } else if (s[ind] > '4') {
      ans += '7';
      num7++;
      ind++;
    } else {
      ans += '4';
      num4++;
      ind++;
    }
  }
  int z = ind - 1;
  while (num7 > n / 2) {
    while (ans[z] == '7') {
      ans[z] = '4';
      num4++;
      num7--;
      z--;
    }
    ans[z] = '7';
    num4--;
    num7++;
  }
  z = ind - 1;
  while (z >= 0 && num4 > n / 2) {
    if (ans[z] == '4') {
      ans[z] = '7';
      num7++;
      num4--;
    }
    z--;
  }
  for (int i = num4; i < n / 2; i++) {
    ans += '4';
  }
  for (int i = num7; i < n / 2; i++) {
    ans += '7';
  }
  cout << ans;
  return 0;
}
