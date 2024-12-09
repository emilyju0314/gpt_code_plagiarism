#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> s, psum;
  int sum = 0;
  for (int i = (int)0; i < (int)n; ++i) {
    int temp;
    cin >> temp;
    s.push_back(temp);
    psum.push_back(temp + sum);
    sum = sum + temp;
  };
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << (psum[r - 1] - psum[l - 1] + s[l - 1]) / 10 << "\n";
  }
  return 0;
}
