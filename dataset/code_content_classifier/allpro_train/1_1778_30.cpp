#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111, MAXM = 2002;
int gr[MAXN][MAXN];
int deg[MAXN];
int cam[MAXM];
int camalt[MAXM], n, m;
inline void insertG(int a, int b) {
  gr[a][b] = gr[b][a] = 1;
  deg[a]++;
  deg[b]++;
}
inline void deleteG(int a, int b) {
  gr[a][b] = gr[b][a] = 0;
  deg[a]--;
  deg[b]--;
}
bool esConexa(int a, int b) {
  vector<bool> visited(n, false);
  stack<int> S;
  S.push(a);
  int aux;
  while (!S.empty()) {
    aux = S.top();
    S.pop();
    visited[aux] = true;
    if (aux == b) return true;
    for (int i = 1; i <= n; i++) {
      if (gr[aux][i] && (!visited[i])) {
        S.push(i);
      }
    }
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i <= m; i++) {
    cin >> cam[i];
  }
  int leq, aux, act;
  for (leq = m - 1; leq >= 0; leq--) {
    act = cam[leq];
    insertG(act, cam[leq + 1]);
    for (aux = cam[leq + 1] + 1; aux <= n && !gr[act][aux]; aux++)
      ;
    if (aux > n) continue;
    deleteG(act, aux);
    if (esConexa(act, cam[0])) {
      break;
    } else {
      insertG(act, aux);
      for (aux = aux + 1; aux <= n && !gr[act][aux]; aux++)
        ;
      if (aux <= n) {
        deleteG(act, aux);
        break;
      }
    }
  }
  if (leq < 0) {
    cout << "No solution" << endl;
    return 0;
  }
  for (int i = 0; i <= leq; i++) camalt[i] = cam[i];
  camalt[leq + 1] = aux;
  for (int i = leq + 1; i < m; i++) {
    act = camalt[i];
    for (aux = 1; aux <= n && !gr[act][aux]; aux++)
      ;
    assert(aux <= n);
    deleteG(act, aux);
    if (deg[act] == 0 || esConexa(act, cam[0])) {
      camalt[i + 1] = aux;
    } else {
      insertG(act, aux);
      for (aux = aux + 1; aux <= n && !gr[act][aux]; aux++)
        ;
      assert(aux <= n);
      deleteG(act, aux);
      camalt[i + 1] = aux;
    }
  }
  for (int i = 0; i <= m; i++) cout << camalt[i] << ' ';
  cout << endl;
}
