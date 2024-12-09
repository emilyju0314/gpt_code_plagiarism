#include <bits/stdc++.h>
using namespace std;
int v[110];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i];
  int i = 0;
  while (i < n - 1) {
    if (v[i] != v[i + 1]) {
      if (v[i] > v[i + 1]) {
        v[i] = v[i] - v[i + 1];
        i = 0;
      } else {
        v[i + 1] = v[i + 1] - v[i];
        i = 0;
      }
      continue;
    }
    i++;
  }
  int soma = 0;
  for (int i = 0; i < n; i++) soma += v[i];
  cout << soma << endl;
}
