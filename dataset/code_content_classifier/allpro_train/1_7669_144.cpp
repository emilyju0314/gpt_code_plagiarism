#include <bits/stdc++.h>
using namespace std;
string names[104] = {
    "",   "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne", "Na",
    "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca", "Sc", "Ti", "V",
    "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
    "Kr", "Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag",
    "Cd", "In", "Sn", "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr",
    "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu",
    "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi",
    "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am",
    "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr"};
map<string, int> em;
int N, K;
string ns[20], ks[20];
bool dp[20][200000];
pair<int, int> parent[20][200000];
vector<string> ans[20];
int sumto(int k) {
  int ret = 0;
  for (int i = 0; i <= k; i++) ret += em[ks[i]];
  return ret;
}
int maskTotal(int mask) {
  int ret = 0;
  for (int i = 0; i < 18; i++)
    if (mask & (1 << i)) ret += em[ns[i]];
  return ret;
}
bool solve(int k, int mask) {
  if (k == K) return true;
  if (dp[k][mask]) return false;
  int needed = sumto(k) - maskTotal(mask);
  for (int i = 0; i < N; i++)
    if (!(mask & (1 << i)))
      if (needed >= em[ns[i]]) {
        if (solve(k + (needed == em[ns[i]]), mask | (1 << i))) {
          ans[k].push_back(ns[i]);
          return true;
        }
      }
  dp[k][mask] = true;
  return false;
}
int main() {
  for (int i = 1; i < 101; i++) em[names[i]] = i;
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> ns[i];
  for (int i = 0; i < K; i++) cin >> ks[i];
  if (solve(0, 0)) {
    cout << "YES" << endl;
    for (int i = 0; i < K; i++) {
      int ss = ans[i].size();
      for (int j = 0; j < ss - 1; j++) cout << ans[i][j] << "+";
      cout << ans[i][ss - 1] << "->" << ks[i] << endl;
    }
  } else
    cout << "NO" << endl;
  return 0;
}
