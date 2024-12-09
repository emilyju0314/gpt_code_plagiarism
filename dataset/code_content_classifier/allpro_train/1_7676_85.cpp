#include <bits/stdc++.h>
using namespace std;
const int maxN = 100010;
int main() {
  long long int n, k, m;
  cin >> n >> k >> m;
  vector<pair<long long int, long long int> > fila;
  long long int x, y;
  long long int actual = 1;
  cin >> x;
  y = x;
  for (int i = 0; i < int(n + 1); i++)
    if (i) {
      if (i < n) cin >> x;
      if (y == x && i < n) {
        actual++;
        continue;
      }
      actual %= k;
      if (actual) {
        fila.push_back(make_pair(y, actual));
        actual = 1;
        y = x;
        continue;
      }
      if (fila.size() > 0) {
        y = fila[fila.size() - 1].first;
        actual = fila[fila.size() - 1].second;
      }
      if (y != x) {
        actual = 1;
        y = x;
        continue;
      }
      if (i < n) fila.pop_back();
      actual++;
    }
  if (fila.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  long long int suma = 0;
  long long int mini = 0;
  long long int maxi = fila.size() - 1;
  while (mini < maxi) {
    if (fila[mini].first != fila[maxi].first) break;
    if (fila[mini].second + fila[maxi].second == k) {
      if (n == 100000 && k == 1000000000 && m == 1000000000) cout << "ENTRE";
      suma += k;
      fila[mini].second = 0;
      fila[maxi].second = 0;
      mini += 1;
      maxi -= 1;
    } else {
      if (fila[mini].second + fila[maxi].second > k) suma += k;
      fila[mini].second += fila[maxi].second;
      fila[maxi].second = 0;
      fila[mini].second %= k;
      break;
    }
  }
  if (mini == maxi) {
    fila[mini].second *= m;
    fila[mini].second %= k;
    if (fila[mini].second == 0) {
      suma -= (fila.size() / 2) * k;
      cout << 0;
      return 0;
    }
    suma += fila[mini].second;
    fila[mini].second = 0;
    cout << suma;
    return 0;
  }
  long long int sumita = 0;
  for (int i = 0; i < int(fila.size()); i++) sumita += fila[i].second;
  sumita *= m;
  suma += sumita;
  cout << suma << endl;
  return 0;
}
