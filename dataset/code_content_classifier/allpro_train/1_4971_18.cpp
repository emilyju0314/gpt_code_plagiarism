#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int k[n];
  for (long long int i = 0; i < n; i++) {
    cin >> k[i];
  }
  long long int suma = 0;
  long long int llevo = 0;
  long long int mov = 0;
  for (long long int j = 0; j < n; j++) {
    suma = k[j] + suma;
  }
  for (long long int i = 0; i < n; i++) {
    llevo = 0;
    if (k[i] < suma / n) {
      llevo = (suma / n) - k[i];
      k[i] = llevo + k[i];
      k[i + 1] = k[i + 1] - llevo;
    } else if (k[i] > suma / n) {
      llevo = k[i] - (suma / n);
      k[i] = k[i] - llevo;
      k[i + 1] = k[i + 1] + llevo;
    }
    mov += llevo;
  }
  cout << mov << endl;
  return 0;
}
