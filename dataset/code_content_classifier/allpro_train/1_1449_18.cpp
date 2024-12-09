#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> XXX(int, vector<bool>&);
vector<int> calc(int c, vector<bool>& XX, int diff) {
  int N = (1 << (c + 1)) + 1;
  vector<bool> BB = vector<bool>((1 << (c)) + 10, false);
  for (int i = 0; i < N; ++i)
    if (i != (1 << c)) {
      int z = ((i - (1 << c)) & 1) ? -diff : 0;
      int ll = ((i - (1 << c) + z) >> 1) + (1 << (c - 1));
      BB[ll] = BB[ll] || XX[i];
    }
  vector<int> XXXX = XXX(c - 1, BB);
  for (auto& z : XXXX) {
    z <<= 1;
  }
  XXXX.push_back(diff);
  return XXXX;
}
vector<int> XXX(int c, vector<bool>& XX) {
  if (c == 0) {
    vector<int> XXXXX;
    if (XX[0]) XXXXX.push_back(-1);
    if (XX[1]) XXXXX.push_back(1);
    return XXXXX;
  }
  bool ver = false;
  bool done = true;
  int N = (1 << (c + 1)) + 1;
  for (int i = 0; i < N; ++i) {
    if (i == (1 << c)) continue;
    done &= !XX[i];
    int w = i - (1 << c);
    if ((w & 1) && XX[i]) {
      ver = true;
      break;
    }
  }
  if (done) return vector<int>();
  if (!ver) {
    vector<bool> BB = vector<bool>((1 << (c)) + 10, false);
    for (int i = 0; i < N; ++i)
      if (i != (1 << c)) {
        int ll = ((i - (1 << c)) >> 1) + (1 << (c - 1));
        BB[ll] = BB[ll] || XX[i];
      }
    vector<int> XXXX = XXX(c - 1, BB);
    for (auto& z : XXXX) {
      z <<= 1;
    }
    return XXXX;
  }
  vector<int> v0 = calc(c, XX, 1);
  vector<int> v1 = calc(c, XX, -1);
  return (int)v0.size() > (int)v1.size() ? v1 : v0;
}
signed main() {
  cin >> n;
  vector<bool> v0 = vector<bool>((1 << 21) + 10, false);
  for (int i = 0; i < n; ++i) {
    cin >> x;
    v0[x + (1 << 20)] = true;
  }
  vector<int> ans;
  ans = XXX(20, v0);
  cout << (int)ans.size() << endl;
  for (auto x : ans) cout << x << " ";
  return cout << endl, 0;
}
