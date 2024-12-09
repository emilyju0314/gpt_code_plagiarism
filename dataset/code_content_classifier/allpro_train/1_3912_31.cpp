#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
template <class T>
void Swap(T &a, T &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}
template <class type>
void show(type name) {
  for (auto &nm : name) cerr << nm << ' ';
  cerr << '\n';
}
using lng = long long;
using ivec = vector<int>;
int main() {
  int n, t;
  cin >> t;
  while (t--) {
    int num, odd = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      if (num & 1) odd++;
    }
    if (odd > 0) {
      if (odd == n && odd % 2 == 0)
        cout << "NO\n";
      else
        cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
