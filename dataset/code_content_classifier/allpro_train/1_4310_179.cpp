#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, D, c{}; cin >> N >> D;
  int X[N][D]; for (int i{}; i < N; ++i) for (int &x : X[i]) cin >> x;
  for (int i{}; i < N; ++i) for (int j{i + 1}; j < N; ++j)
    {int d{}, n{}; for (int k{}, t; k < D; ++k) t = X[i][k] - X[j][k], d += t * t;
    while (n * n < d) ++n; if (n * n == d) ++c;}
  cout << c;}