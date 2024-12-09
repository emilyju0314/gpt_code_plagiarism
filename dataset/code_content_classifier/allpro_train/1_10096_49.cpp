#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long vec[n];
  for (long long i = 0; i < n; i++) cin >> vec[i];
  long long c = 1, maximo = 1;
  for (long long i = 1; i < n; i++) {
    if (vec[i] > vec[i - 1])
      c++;
    else {
      if (c > maximo) maximo = c;
      c = 1;
    }
  }
  if (c > maximo) maximo = c;
  cout << maximo << endl;
  return 0;
}
