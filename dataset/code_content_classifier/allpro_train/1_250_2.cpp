#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 29;

int N, X, Y, G[14][14];
int tsp[1 << 14][14];
vector< tuple< int, int, int > > vs[14];
int dp1[1 << 7][1001];
int dp2[1 << 7][1001];

int main()
{

  cin >> N >> X >> Y;
  for(int i = 0; i < N; i++) {
    int K;
    cin >> K;
    for(int j = 0; j < K; j++) {
      int a, b, c;
      cin >> a >> b >> c;
      vs[i].emplace_back(a, b, c);
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> G[i][j];
    }
  }


  fill_n(*tsp, (1 << 14) * 14, INF);
  for(int i = 0; i < N; i++) tsp[1 << i][i] = G[0][i];
  for(int i = 0; i < (1 << N); i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        tsp[i | (1 << k)][k] = min(tsp[i | (1 << k)][k], tsp[i][j] + G[j][k]);
      }
    }
  }

  vector< int > st1, st2;
  int mid = N / 2;
  for(int i = 0; i < (1 << mid); i++) st1.emplace_back(i);
  for(int i = 0; i < (1 << (N - mid)); i++) st2.emplace_back(i);

  for(int i = 0; i < mid; i++) {
    for(auto &p : vs[i]) {
      int a, b, c;
      tie(a, b, c) = p;
      for(int k = 0; c > 0; k++) {
        int key = min(c, (int) (1 << k));
        c -= key;
        for(int j = 1000; j >= key * a; j--) {
          dp1[1 << i][j] = max(dp1[1 << i][j], dp1[1 << i][j - key * a] + key * b);
        }
      }
    }

    for(int j = 1; j <= 1000; j++) {
      dp1[1 << i][j] = max(dp1[1 << i][j], dp1[1 << i][j - 1]);
    }
  }

  for(int i = 0; i < N - mid; i++) {
    for(auto &p : vs[i + mid]) {
      int a, b, c;
      tie(a, b, c) = p;
      for(int k = 0; c > 0; k++) {
        int key = min(c, (int) (1 << k));
        c -= key;
        for(int j = 1000; j >= key * a; j--) {
          dp2[1 << i][j] = max(dp2[1 << i][j], dp2[1 << i][j - key * a] + key * b);
        }
      }
    }

    for(int j = 1; j <= 1000; j++) {
      dp2[1 << i][j] = max(dp2[1 << i][j], dp2[1 << i][j - 1]);
    }
  }

  sort(begin(st1), end(st1), [&](int a, int b)
  {
    return (__builtin_popcount(a) < __builtin_popcount(b));
  });
  sort(begin(st2), end(st2), [&](int a, int b)
  {
    return (__builtin_popcount(a) < __builtin_popcount(b));
  });

  for(auto &i : st1) {

    if(__builtin_popcount(i) > 1) {
      int idx = -1;
      for(int j = 0; j < mid; j++) {
        if((i >> j) & 1) {
          idx = j;
          break;
        }
      }
      // cout << idx << endl;

      int bit = i ^(1 << idx);

      for(int j = 0; j <= 1000; j++) {
        dp1[i][j] = dp1[bit][j];
      }

      for(auto &p : vs[idx]) {
        int a, b, c;
        tie(a, b, c) = p;
        for(int k = 0; c > 0; k++) {
          int key = min(c, (int) (1 << k));
          c -= key;
          for(int j = 1000; j >= key * a; j--) {
            dp1[i][j] = max(dp1[i][j], dp1[i][j - key * a] + key * b);
          }
        }
      }
      for(int j = 1; j <= 1000; j++) {
        dp1[i][j] = max(dp1[i][j], dp1[i][j - 1]);
      }
    }
  }

  for(auto &i : st2) {

    if(__builtin_popcount(i) > 1) {
      int idx = -1;
      for(int j = 0; j < N - mid; j++) {
        if((i >> j) & 1) {
          idx = j;
          break;
        }
      }
      // cout << idx << endl;

      int bit = i ^(1 << idx);

      for(int j = 0; j <= 1000; j++) {
        dp2[i][j] = dp2[bit][j];
      }

      for(auto &p : vs[idx + mid]) {
        int a, b, c;
        tie(a, b, c) = p;
        for(int k = 0; c > 0; k++) {
          int key = min(c, (int) (1 << k));
          c -= key;
          for(int j = 1000; j >= key * a; j--) {
            dp2[i][j] = max(dp2[i][j], dp2[i][j - key * a] + key * b);
          }
        }
      }
      for(int j = 1; j <= 1000; j++) {
        dp2[i][j] = max(dp2[i][j], dp2[i][j - 1]);

      }
    }

  }

  int ret = 0;
  for(auto &s : st1) {
    for(auto &t : st2) {
      int bit = (t << mid) | s;
      int rest = X - tsp[bit][0];
      if(rest < 0) continue;
      int cost = min(rest, Y);
      for(int i = 0; i <= cost; i++) {
        ret = max(ret, dp1[s][i] + dp2[t][cost - i]);
      }
    }
  }


  cout << ret << endl;
}