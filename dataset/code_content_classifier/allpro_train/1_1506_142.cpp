#include <bits/stdc++.h>
using namespace std;
int n, c, a[100005], sign[100005];
bool sign_ch[100005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sign[n] = 1;
  c = a[n];
  for (int i = n - 1; i >= 1; i--) {
    if (c >= a[i]) {
      c -= a[i];
      sign[i] = -1;
    } else {
      c = a[i] - c;
      sign[i] = 1;
      sign_ch[i + 1] = true;
    }
  }
  int flip = 0;
  for (int i = 1; i <= n; i++) {
    if (sign_ch[i] == true) flip = !flip;
    char ch;
    ch = sign[i] == 1 ? '+' : '-';
    if (flip) ch = ch == '+' ? '-' : '+';
    putchar(ch);
  }
  putchar('\n');
  return 0;
}
