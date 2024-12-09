#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> G;
vector<pair<int, int> > V;

int erase(int s) {
  int res = N;
  while(res) {
    int a, b;
    for(a = s + 1; a <= N; ++a) {
      if(a == N || G[s] != G[a]) break;
    }
    --a;
    for(b = s - 1; b >= -1; --b) {
      if(b == -1 || G[s] != G[b]) break;
    }
    ++b;
    if(a - b + 1 >= 4) {
      s = min(N - 1, a + 1);
      res -= a - b + 1;
      for(int i = b; i <= a; ++i) G[i] = 0;
      for(int i = N - 1, j = N - 1; i >= 0; --i) {
        if(G[i] != 0) {
          int tmp = G[i];
          G[i] = 0;
          G[j--] = tmp;
        }
      }
    } else {
      break;
    }
  }
  return res;
}

int main() {
  while(cin >> N && N) {
    G.resize(N);
    for(int i = 0; i < N; ++i) {
      cin >> G[i];
    }
    int res = N;
    for(int i = 0; i < N; ++i) {
      for(int j = 1; j <= 3; ++j) {
        vector<int> tmp = G;
        G[i] = j;
        res = min(res, erase(i));
        G = tmp;
      }
    }
    cout << res << endl;
  }
  return 0;
}