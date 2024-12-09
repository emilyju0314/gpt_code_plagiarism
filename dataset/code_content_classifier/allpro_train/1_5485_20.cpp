#include <bits/stdc++.h>
using namespace std;
long long max_colors[100005];
long long values[100005];
int colors[100005];
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) cin >> values[i];
  for (int i = 1; i <= n; i++) scanf("%d", &colors[i]);
  long long a, b;
  long long ans = 0;
  int h1, h2;
  for (int qq = 0; qq < q; qq++) {
    cin >> a >> b;
    ans = 0;
    fill(max_colors, max_colors + n + 1, -(1LL << 50));
    h1 = h2 = 0;
    max_colors[0] = -(1LL << 50);
    for (int i = 1; i <= n; i++) {
      int c = colors[i];
      long long temp;
      temp = b * values[i];
      if (max_colors[c] != (1LL << 50))
        temp = max(temp, max_colors[c] + a * values[i]);
      if (c == h1) {
        temp = max(temp, max_colors[h2] + b * values[i]);
      } else {
        temp = max(temp, max_colors[h1] + b * values[i]);
      }
      if (temp > max_colors[c]) {
        max_colors[c] = temp;
        if (c == h1 || c == h2) {
          if (max_colors[h1] < max_colors[h2]) swap(h1, h2);
        } else {
          if (temp >= max_colors[h1]) {
            h2 = h1;
            h1 = c;
          } else if (temp > max_colors[h2]) {
            h2 = c;
          }
        }
      }
      ans = max(ans, max_colors[c]);
    }
    cout << ans << endl;
  }
  return 0;
}
