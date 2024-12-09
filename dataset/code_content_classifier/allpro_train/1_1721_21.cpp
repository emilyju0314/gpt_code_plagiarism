#include<bits/stdc++.h>

using namespace std;

int N, M, L, F[9];
double B[11], H[11], X[9];

double beet[13];

void put(int x, double &v, int l, int r)
{
  if(r - l >= 2) {
    int mx = l + 1;
    for(int i = l + 2; i < r; i++) if(H[i] > H[mx]) mx = i;
    if(x < mx) {
      put(x, v, l, mx);
      put(x, v, mx, r);
    } else {
      put(x, v, mx, r);
      put(x, v, l, mx);
    }
  }
  double w = B[r] - B[l], u = min(H[l], H[r]);
  double dh = v / w;

  if(beet[l] + dh < u) {
    v = 0;
    for(int i = l; i < r; i++) beet[i] += dh;
  } else {
    v -= (u - beet[l]) * w;
    for(int i = l; i < r; i++) beet[i] = u;
  }
}

int main()
{
  int D;
  cin >> D;
  while(D--) {
    cin >> N;
    ++N;
    for(int i = 1; i < N; i++) cin >> B[i] >> H[i];
    B[0] = 0, H[0] = 50;
    B[N] = 100, H[N] = 50;

    cin >> M;
    for(int i = 0; i < M; i++) {
      cin >> F[i] >> X[i];
      X[i] /= 30;
      F[i] = lower_bound(B, B + N, F[i]) - B-1;
    }
    cin >> L;
    while(L--) {
      int P, T;
      cin >> P >> T;
      memset(beet, 0, sizeof(beet));
      for(int i = 0; i < M; i++) {
        double cup = X[i] * T;
        put(F[i], cup, 0, N);
      }
      cout << fixed << setprecision(10) << beet[lower_bound(B, B + N, P) - B - 1] << endl;
    }
  }
}