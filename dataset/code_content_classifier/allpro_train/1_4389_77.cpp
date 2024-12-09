#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
const double PI = 3.1415926535897932384626433832795;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
mt19937 rnd(time(NULL));
string proc(string s) {
  for (auto& x : s) {
    x = tolower(x);
    if (x == 'o') x = '0';
    if (x == 'i') x = '1';
    if (x == 'l') x = '1';
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  string s;
  cin >> s;
  s = proc(s);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string q;
    cin >> q;
    if (proc(q) == s) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
