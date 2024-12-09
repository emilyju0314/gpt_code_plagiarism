#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  long long n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    cout << (-1 * n) + 1 << " " << n << '\n';
  }
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sort_descending(int a, int b) { return (a > b); }
