#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a[1001];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a[i] = s.substr(4);
  }
  int arr[10] = {1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1989};
  for (int i = 0; i < n; i++) {
    int k = 10;
    int pos = a[i].length() - 1;
    int act = a[i][pos] - '0';
    int l = arr[act];
    while (pos > 0) {
      pos--;
      act += k * (a[i][pos] - '0');
      l += k;
      while (act != l % (10 * k)) l += k;
      k *= 10;
    }
    cout << l << endl;
  }
}
