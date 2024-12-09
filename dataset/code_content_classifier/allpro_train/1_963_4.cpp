#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxNodos = 210000;
int numeroNodos;
vector<int> Grafo[maxNodos + 1];
vector<int> Tree[maxNodos + 1];
vector<int> S(maxNodos + 1);
vector<long long> factorial(maxNodos + 1);
void precalcularFactorial() {
  factorial[0] = 1;
  for (long long i = 1; i <= maxNodos; i++) {
    factorial[i] = (factorial[i - 1] * i) % mod;
  }
}
void construirArbol_visit(int x) {
  S[x] = 1;
  for (int i = 0; i < Grafo[x].size(); i++) {
    int y = Grafo[x][i];
    if (S[y] == 0) {
      Tree[x].push_back(y);
      construirArbol_visit(y);
    }
  }
}
void construirArbol() {
  for (int i = 0; i <= numeroNodos; i++) {
    S[i] = 0;
  }
  construirArbol_visit(1);
}
long long solver(int x) {
  if (Tree[x].size() == 0) return 1;
  long long ans = 1;
  for (int i = 0; i < Tree[x].size(); i++) {
    ans = (ans * solver(Tree[x][i])) % mod;
  }
  if (x == 1) {
    ans = (ans * factorial[Tree[x].size()]) % mod;
    ans = (ans * numeroNodos) % mod;
  } else
    ans = (ans * factorial[Tree[x].size() + 1]) % mod;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  precalcularFactorial();
  int n, x, y, i;
  long long ans;
  cin >> n;
  numeroNodos = n;
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    Grafo[x].push_back(y);
    Grafo[y].push_back(x);
  }
  construirArbol();
  ans = solver(1);
  cout << ans << '\n';
}
