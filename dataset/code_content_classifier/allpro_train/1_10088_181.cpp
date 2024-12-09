#include <bits/stdc++.h>
using namespace std;
char str[105][105];
int lengt[105];
int n;
int mapp[40][40];
struct node {
  char zf;
  int num;
} ans[30];
void Init() {
  for (int i = 0; i < 26; i++) {
    ans[i].zf = 'a' + i;
    ans[i].num = 0;
  }
}
bool cl(int l, int r, int now) {
  int start, en;
  while (str[l][now] == '\0') l++;
  if (l == r) return false;
  for (int i = l + 1; i <= r; i++) {
    if (now == lengt[i] && now < lengt[i - 1]) return true;
    start = i - 1;
    while (str[i][now] == str[i - 1][now] && i <= r) i++;
    if (start != i - 1)
      if (cl(start, i - 1, now + 1)) return true;
    if (i > r) break;
    int q2 = str[i][now] - 'a';
    int q1 = str[start][now] - 'a';
    mapp[q1][q2] = 1;
  }
  return false;
}
void floyd() {
  for (int k = 0; k < 26; k++)
    for (int j = 0; j < 26; j++)
      for (int i = 0; i < 26; i++)
        if (mapp[i][k] && mapp[k][j]) mapp[i][j] = 1;
}
bool pd() {
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (j == i) continue;
      if (mapp[i][j] && mapp[j][i]) {
        return false;
      } else if (mapp[i][j])
        ans[i].num++;
    }
  }
  return true;
}
int cmp(node a, node b) { return a.num > b.num; }
int main() {
  cin >> n;
  memset(mapp, 0, sizeof(mapp));
  for (int i = 0; i < n; i++) cin >> str[i], lengt[i] = strlen(str[i]);
  Init();
  if (cl(0, n - 1, 0)) {
    cout << "Impossible" << endl;
    return 0;
  }
  floyd();
  if (!pd()) {
    cout << "Impossible" << endl;
    return 0;
  }
  sort(ans, ans + 26, cmp);
  for (int i = 0; i < 26; i++) cout << ans[i].zf;
  cout << endl;
  return 0;
}
