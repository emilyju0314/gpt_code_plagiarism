#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int s[1001];
  while(cin >> n) {
    if (n == 0) break;
    double m = 0, result = 0;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      m += s[i];
    }
    m /= n;
    for (int i = 0; i < n; i++) {
      result += pow((s[i] - m), 2);
    }
    cout << fixed << setprecision(8);
    cout << sqrt(result / n) << endl;
  }
}
