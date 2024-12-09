#include <bits/stdc++.h>
using namespace std;
map<int, int> mapa;
int n;
vector<int> vek;
long long int rjesenje = 0;
bool cmp(int a, int b) { return a > b; }
int main() {
  int koliko;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    vek.push_back(x);
    mapa[x]++;
  }
  sort(vek.begin(), vek.end(), cmp);
  koliko = n / 4;
  int kreni = 0;
  while (koliko--) {
    long long int prva = 0, druga = 0;
    for (int i = kreni; i < vek.size(); i++) {
      if (mapa[vek[i]] >= 2) {
        mapa[vek[i]] -= 2;
        prva = vek[i];
        kreni = i;
        break;
      } else if (mapa[vek[i]] == 1 && mapa[vek[i] - 1] >= 1) {
        mapa[vek[i]]--;
        mapa[vek[i] - 1]--;
        prva = vek[i] - 1;
        kreni = i;
        break;
      }
    }
    for (int i = kreni; i < vek.size(); i++) {
      if (mapa[vek[i]] >= 2) {
        mapa[vek[i]] -= 2;
        druga = vek[i];
        kreni = i;
        break;
      } else if (mapa[vek[i]] == 1 && mapa[vek[i] - 1] >= 1) {
        mapa[vek[i]]--;
        mapa[vek[i] - 1]--;
        druga = vek[i] - 1;
        kreni = i;
        break;
      }
    }
    rjesenje += (long long int)(prva * druga);
  }
  printf("%I64d", rjesenje);
  return 0;
}
