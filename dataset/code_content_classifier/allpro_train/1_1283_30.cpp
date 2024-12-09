#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, M; cin >> N >> M;
  int s = 0; while (M--) {int A; cin >> A; s += A;}
  cout << max(-1, N - s) << endl;}