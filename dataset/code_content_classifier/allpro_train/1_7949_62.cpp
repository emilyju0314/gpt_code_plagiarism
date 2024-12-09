// ABC075-D
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n, m) for (int (i) = (n); (i) < (m); ++(i))

int main() {
   int N, K;
   ll x[60], y[60];
   cin >> N >> K;
   rep (i, 0, N) cin >> x[i] >> y[i];

   ll area = 1LL << 62;
   rep (xi, 0, N) rep (xj, 0, N) rep (yi, 0, N) rep (yj, 0, N) {
      if (x[xi] <= x[xj] && y[yi] <= y[yj]) {
         int cnt = 0;
         rep (p, 0, N) {
            if (x[p] >= x[xi] && x[p] <= x[xj] && y[p] >= y[yi] && y[p] <= y [yj]) cnt++;
         }

         if (cnt >= K) area = min(area, (x[xj]-x[xi]) * (y[yj]-y[yi]));
      }
   }
   cout << area << endl;

   return 0;
}