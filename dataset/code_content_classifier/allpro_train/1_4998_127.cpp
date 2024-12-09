#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int N = 13, M = 1e9 + 7;
  vector<int> DP(N);
  DP.at(0) = 1;
  char c;
  while (cin >> c) {
    vector<int> V(N);
    for (int i = 0; i < N; i++) {
      if (c != '?') (V.at((i * 10 + c - '0') % 13) += DP.at(i)) %= M;
      else for (int j = 0; j < 10; j++) {
        (V.at((i * 10 + j) % 13) += DP.at(i)) %= M;
      }
    }
    DP = V;
}

cout << DP.at(5) << "\n";
}