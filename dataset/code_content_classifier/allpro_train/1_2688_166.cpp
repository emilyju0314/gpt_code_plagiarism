#include <bits/stdc++.h>
using namespace std;
int n, f, maxf = -0x3f3f3f3f, maxfind = 0, book[301000], num[301000];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    if (num[i] == 0)
      book[i] = 1;
    else if (num[i] < 0) {
      f++;
      if (maxf < num[i]) maxf = num[i], maxfind = i;
    }
  }
  if (f & 1 == 1) book[maxfind] = 1;
  int ind = 1, flag = 0;
  while (book[ind] == 1) ind++;
  for (int i = ind + 1; i <= n; i++)
    if (book[i] == 0) {
      cout << 1 << " " << i << " " << ind << endl;
      flag++;
    }
  ind = 1;
  while (book[ind] == 0) ind++;
  for (int i = ind + 1; i <= n; i++)
    if (book[i]) {
      cout << 1 << " " << i << " " << ind << endl;
      flag++;
    }
  if (flag < n - 1) cout << 2 << " " << ind << endl;
  return 0;
}
