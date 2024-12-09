#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long Sum = 0;
  for (long long i = 0; i < n; i++) {
    Sum = Sum + a[i];
  }
  long long Flag = 0;
  long long m;
  cin >> m;
  long long Num1, Num2;
  for (long long i = 0; i < m; i++) {
    cin >> Num1 >> Num2;
    if (Sum < Num1) {
      cout << Num1 << endl;
      Flag = 1;
      break;
    } else if (Sum >= Num1 && Sum <= Num2) {
      cout << Sum << endl;
      Flag = 1;
      break;
    }
  }
  if (Flag == 0) {
    cout << "-1" << endl;
  }
}
