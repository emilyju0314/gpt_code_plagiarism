#include <bits/stdc++.h>
using namespace std;
struct info {
  int d, f, t, cst;
} inp[100006];
int forw[1000005];
int forw2[1000005];
long long cforw[1000005];
long long cforw2[1000005];
int ok[1000006];
int ok2[1000006];
bool cmp(info a, info b) { return a.d < b.d; }
void process1(int prev, int day) {
  while (prev < day) {
    cforw[prev + 1] = cforw[prev];
    forw[prev + 1] = forw[prev];
    prev++;
  }
}
void process2(int prev, int day) {
  while (prev > day) {
    cforw2[prev - 1] = cforw2[prev];
    forw2[prev - 1] = forw2[prev];
    prev--;
  }
}
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d %d", &inp[i].d, &inp[i].f, &inp[i].t, &inp[i].cst);
  }
  sort(inp + 1, inp + m + 1, cmp);
  int prev = 0;
  for (int i = 1; i <= m; i++) {
    int day = inp[i].d;
    process1(prev, day);
    prev = day;
    if (inp[i].f != 0) {
      int pos = inp[i].f;
      if (ok[pos] == 0) {
        ok[pos] = inp[i].cst;
        cforw[day] += inp[i].cst;
        forw[day]++;
      } else if (ok[pos] > inp[i].cst) {
        cforw[day] += (-ok[pos] + inp[i].cst);
        ok[pos] = inp[i].cst;
      }
    }
  }
  process1(prev, 1000000);
  prev = n + 1;
  for (int i = m; i >= 1; i--) {
    if (inp[i].f != 0) continue;
    int pos = inp[i].t;
    int day = inp[i].d;
    process2(prev, day);
    prev = day;
    if (ok2[pos] == 0) {
      ok2[pos] = inp[i].cst;
      cforw2[day] += inp[i].cst;
      forw2[day]++;
    } else if (ok2[pos] > inp[i].cst) {
      cforw2[day] += (-ok2[pos] + inp[i].cst);
      ok2[pos] = inp[i].cst;
    }
  }
  process2(prev, 1);
  long long ans = -1;
  for (int i = 1; i <= 1000000 - k - 1; i++) {
    int t = i + k + 1;
    if (forw[i] != n || (forw2[t] != n)) continue;
    long long tot = cforw[i] + cforw2[t];
    if (ans == -1)
      ans = tot;
    else
      ans = min(ans, tot);
  }
  cout << ans << endl;
}
