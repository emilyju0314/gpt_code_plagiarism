#include <bits/stdc++.h>
using namespace std;
char str[100];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    unordered_map<char, int> M;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) M[a[i]] = i;
    int res = 0;
    for (int i = 1; i < b.size(); i++) {
      res += abs(M[b[i]] - M[b[i - 1]]);
    }
    printf("%d\n", res);
  }
  return 0;
}
