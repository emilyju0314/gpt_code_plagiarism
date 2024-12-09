#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string Str;
  cin >> Str;
  char num[10];
  for (int i = 1; i < 10; i++) cin >> num[i];
  for (int i = 0; i < n; i++) {
    if (Str[i] < num[(int)Str[i] - 48]) {
      for (int j = i; j < n; j++) {
        if (Str[j] <= num[(int)Str[j] - 48]) {
          Str[j] = num[(int)Str[j] - 48];
        } else {
          cout << Str;
          return 0;
        }
      }
      cout << Str;
      return 0;
    }
  }
  cout << Str;
  return 0;
}
