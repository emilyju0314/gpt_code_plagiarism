#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-6;
const long double pi = acos(-1);
const long long oo = 1e18 + 10;
const long long N = 1e5;
const long long MOD = 1000000007;
int main() {
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    vector<string> v(n);
    string s = "<3";
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      s += v[i];
      s += "<3";
    }
    string r;
    cin >> r;
    long long cnt = 0;
    for (long long i = 0, j = 0; i < r.size(); i++) {
      while (i < r.size() && j < s.size() && s[j] == r[i]) {
        i++;
        j++;
        cnt++;
      }
    }
    if (cnt == s.size()) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
