#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  map<string, int> mapp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mapp[s]++;
  }
  int best = 0;
  for (auto it = mapp.begin(); it != mapp.end(); it++)
    best = max(best, it->second);
  cout << best;
  return 0;
}
