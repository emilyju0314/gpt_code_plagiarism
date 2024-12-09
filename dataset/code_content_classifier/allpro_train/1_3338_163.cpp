#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    string s;
    cin >> s;
    int c = 0, A[101], k = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == 'B') c++;
      if (s[j] == 'W') {
        if (c) A[k++] = c;
        c = 0;
      }
    }
    if (s[s.size() - 1] == 'B') A[k++] = c;
    if (!k)
      cout << "0\n";
    else {
      cout << k << "\n";
      for (int j = 0; j < k; j++) cout << A[j] << " ";
      cout << "\n";
    }
  }
  return 0;
}
