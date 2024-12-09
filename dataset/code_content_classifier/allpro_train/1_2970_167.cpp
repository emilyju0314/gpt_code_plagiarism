#include <bits/stdc++.h>
using namespace std;
vector<string> save;
int n;
map<int, string> ind_val;
map<string, int> val_ind;
int memo[55][55][55][55];
bool sol(int first, int second, int third, int id) {
  string cad1 = ind_val[first], cad2 = ind_val[second], cad3 = ind_val[third];
  if (id == n) {
    if ((cad1[0] == cad2[0] || cad1[1] == cad2[1]) &&
        (cad1[0] == cad3[0] || cad1[1] == cad3[1])) {
      return 1;
    }
    return 0;
  }
  bool ans = 0;
  if (memo[first][second][third][id] != -1)
    return memo[first][second][third][id];
  string cad4 = ind_val[id];
  if (cad1[0] == cad2[0] || cad1[1] == cad2[1]) {
    ans |= sol(val_ind[cad1], third, id, id + 1);
  }
  if (cad1[0] == cad4[0] || cad1[1] == cad4[1]) {
    ans |= sol(second, third, val_ind[cad1], id + 1);
  }
  return memo[first][second][third][id] = ans;
}
int main() {
  scanf("%d", &n);
  string cad;
  for (int i = 0; i < n; i++) {
    cin >> cad;
    save.push_back(cad);
  }
  reverse(save.begin(), save.end());
  for (int i = 0; i < n; i++) {
    cad = save[i];
    ind_val[i] = cad;
    val_ind[cad] = i;
  }
  memset(memo, -1, sizeof memo);
  string last = save[0];
  bool ans = false;
  if (n <= 3) {
    bool tmp = true;
    ;
    for (int i = 0; i < n; i++) {
      if (last[0] == save[i][0] || last[1] == save[i][1])
        ;
      else
        tmp = false;
    }
    ans = tmp;
  } else {
    ans = sol(0, 1, 2, 3);
  }
  printf("%s\n", (ans) ? "YES" : "NO");
  return 0;
}
