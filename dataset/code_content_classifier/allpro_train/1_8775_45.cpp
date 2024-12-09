#include <bits/stdc++.h>
using namespace std;
unsigned long long N;
unsigned long long result = 0;
vector<int> E[80010];
unsigned long long solve(int u, int p) {
  unsigned long long ret = 1;
  vector<unsigned long long> H(1, 1);
  for (int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if (v == p) continue;
    H.push_back(solve(v, u));
    ret += H.back();
  }
  H.push_back(N - ret);
  unsigned long long inner = 0;
  for (int i = 0; i < H.size(); i++) {
    inner += H[i] * H[i];
  }
  for (int i = 1; i < H.size(); i++) {
    result += H[i] * (N * N - inner) +
              H[i] * (N - H[i]) *
                  ((N - H[i]) * N - (inner - H[i] * H[i]) - (N - H[i]) * H[i]);
  }
  return ret;
}
int main() {
  int nn;
  cin >> nn;
  N = nn;
  for (int i = 1; i < nn; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  solve(0, -1);
  cout << (N * (N - 1) * N * (N - 1) - result) / 4 << endl;
  return 0;
}
