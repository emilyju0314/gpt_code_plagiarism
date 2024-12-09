#include <bits/stdc++.h>
using namespace std;
struct node {
  int x;
  int times;
};
const int N = 105 * 2;
int num[N];
int cont[N];
vector<int> g[N];
int xx[2][105];
int b[N];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 10; i <= 99; i++) g[i].clear();
    memset(cont, 0, sizeof(cont));
    memset(xx, 0, sizeof(xx));
    for (int i = 0; i < n * 2; i++) {
      cin >> num[i];
      cont[num[i]]++;
      g[num[i]].push_back(i);
    }
    for (int i = 10; i <= 99; i++)
      if (cont[i] == 1) cont[i] = -1;
    for (int i = 10; i <= 99; i++) {
      if (cont[i] >= 2) {
        if (cont[i] & 1) {
          xx[0][i] += (cont[i] / 2);
          xx[1][i] += (cont[i] / 2);
          cont[i] = 1;
        } else {
          xx[0][i] += (cont[i] / 2);
          xx[1][i] += (cont[i] / 2);
          cont[i] = 0;
        }
      }
    }
    int suml = 0;
    int sumr = 0;
    for (int i = 10; i <= 99; i++) {
      suml += xx[0][i];
      sumr += xx[1][i];
    }
    int t = 1;
    for (int i = 10; i <= 99; i++) {
      if (cont[i] == -1 && suml < n && t & 1) {
        xx[0][i] += 1;
        suml += 1;
        cont[i] = 0;
        t++;
      } else if (cont[i] == -1 && sumr < n && t % 2 == 0) {
        xx[1][i] += 1;
        sumr += 1;
        cont[i] = 0;
        t++;
      }
    }
    for (int i = 10; i <= 99; i++) {
      if (cont[i] == 1 && suml < n) {
        xx[0][i] += 1;
        suml += 1;
        cont[i] = 0;
      }
    }
    for (int i = 10; i <= 99; i++) {
      if (cont[i] != 0) {
        xx[1][i] += 1;
      }
    }
    int p, q;
    p = 0;
    q = 0;
    for (int i = 10; i <= 99; i++) {
      if (xx[0][i] != 0) p++;
      if (xx[1][i] != 0) q++;
    }
    for (int i = 10; i <= 99; i++) {
      if (xx[0][i] != 0) {
        for (int j = 0; j < xx[0][i]; j++) {
          b[g[i][j]] = 1;
        }
      }
    }
    for (int i = 10; i <= 99; i++) {
      if (xx[1][i] != 0) {
        for (int j = xx[0][i]; j < g[i].size(); j++) {
          b[g[i][j]] = 2;
        }
      }
    }
    cout << p * q << endl;
    for (int i = 0; i < n * 2; i++) {
      if (i == n * 2 - 1)
        cout << b[i] << endl;
      else
        cout << b[i] << ' ';
    }
  }
}
