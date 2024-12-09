#include <bits/stdc++.h>
using namespace std;
int n, alvo, aux, aux2;
int numbers[16] = {0};
bool posNumbers[16] = {0};
int tab[4][4];
bool flag = 0;
int t;
void magic(int x, int y, int sum) {
  for (int i = 0; i < t; i++) {
    if (!posNumbers[i]) {
      posNumbers[i] = 1;
      tab[x][y] = numbers[i];
      if (y == n - 1) {
        if (sum + numbers[i] == alvo) {
          if (x < n - 1) {
            magic(x + 1, 0, 0);
            if (flag) return;
            posNumbers[i] = 0;
            tab[x][y] = 0;
          } else {
            flag = true;
          }
        } else {
          posNumbers[i] = 0;
          tab[x][y] = 0;
        }
      } else {
        magic(x, y + 1, sum + numbers[i]);
        if (flag) return;
        posNumbers[i] = 0;
        tab[x][y] = 0;
      }
    }
    if (flag && x == n - 1 && y == n - 1) {
      aux2 = 0;
      aux = 0;
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          aux += tab[k][j];
        }
        if (aux != alvo) {
          flag = 0;
          posNumbers[i] = 0;
          tab[x][y] = 0;
          break;
        }
        aux = 0;
      }
      if (!flag) continue;
      aux = 0;
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (j == k) aux += tab[j][k];
          if (j + k == n - 1) aux2 += tab[j][k];
        }
      }
      if (aux != alvo || aux2 != alvo) {
        flag = 0;
        posNumbers[i] = 0;
        tab[x][y] = 0;
      }
    }
  }
}
int main() {
  long long int gui = 0;
  scanf("%d", &n);
  t = n * n;
  for (long long int i = 0; i < t; i++) {
    scanf("%d", &numbers[i]);
    gui += numbers[i];
  }
  alvo = gui / n;
  cout << alvo;
  cout << "\n";
  magic(0, 0, 0);
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      if (j) cout << " ";
      cout << tab[i][j];
    }
    cout << "\n";
  }
  return 0;
}
