#include <bits/stdc++.h>
using namespace std;
void SO() { cout << endl; }
template <typename S, typename... Strings>
void SO(S x, const Strings &...rest) {
  cout << x << ' ';
  SO(rest...);
}
const long double PI = 3.1415926535897932384626433832795;
const int v5 = 100000;
const int v9 = 1000000000;
const int v6 = 1000000;
inline long long int ABS(long long int a) {
  if (a < 0) return (-a);
  return a;
}
inline long long int min(long long int a, long long int b, long long int c) {
  return min(a, min(b, c));
}
inline long long int max(long long int a, long long int b, long long int c) {
  return max(a, max(b, c));
}
inline void AI(long long int x[], long long int n) {
  for (long long int i = 0; i < (n); ++i) cin >> (x[i]);
}
inline void VI(vector<long long int> &arr, long long int n) {
  for (long long int i = 0; i < (n); ++i) {
    long long int x;
    cin >> (x);
    arr.push_back(x);
  };
}
long long int n, m, k, c = 0;
long long int a[4000001];
map<long long int, vector<long long int> > g;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s, nw;
  cin >> (s);
  long long int i = 0, ln = s.length();
  while (i < ln and s[i] == 'a') {
    nw += 'a';
    i++;
  }
  while (i < ln and s[i] != 'a') {
    nw += char(int(s[i]) - 1);
    i++;
  }
  while (i < ln) {
    nw += s[i];
    i++;
  }
  if (nw == s) {
    if (nw[ln - 1] == 'a')
      nw[ln - 1] = 'z';
    else
      nw[ln - 1] = char(int(s[ln - 1]) - 1);
  }
  SO(nw);
  return 0;
}
