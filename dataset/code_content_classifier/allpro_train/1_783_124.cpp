#include <bits/stdc++.h>
using namespace std;
inline void read(long long &x) {
  char ch;
  bool flag = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') flag = true;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  x = flag ? -x : x;
}
inline void write(long long x) {
  static const long long maxlen = 100;
  static char s[maxlen];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  long long len = 0;
  for (; x; x /= 10) s[len++] = x % 10 + '0';
  for (long long i = len - 1; i >= 0; --i) putchar(s[i]);
}
inline void read(int &x) {
  char ch;
  bool flag = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') flag = true;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  x = flag ? -x : x;
}
inline void write(int x) {
  static const long long maxlen = 100;
  static char s[maxlen];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  long long len = 0;
  for (; x; x /= 10) s[len++] = x % 10 + '0';
  for (long long i = len - 1; i >= 0; --i) putchar(s[i]);
}
const int MAXN = 101000;
vector<int> full[MAXN];
set<int> l;
vector<int> lack[MAXN];
int lim[MAXN];
int sum[MAXN];
vector<int> a[MAXN];
int n, m;
pair<int, int> id[MAXN];
int main() {
  read(n);
  read(m);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    read(sum[i]);
    for (int j = 1; j <= sum[i]; j++) {
      int x;
      read(x);
      a[i].push_back(x);
    }
    id[i].first = -sum[i];
    id[i].second = i;
    cnt += sum[i];
  }
  for (int i = 1; i <= n; i++) {
    lim[i] = cnt / n + ((i <= cnt % n) ? 1 : 0);
  }
  sort(id + 1, id + n + 1);
  int cnt_ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = id[i].second;
    if (sum[x] > lim[i]) {
      for (int j = 0; j < sum[x]; j++) full[a[x][j]].push_back(x);
    }
    if (sum[x] < lim[i]) {
      l.insert(x);
      for (int j = 0; j < sum[x]; j++) lack[a[x][j]].push_back(x);
    }
    sum[x] = sum[x] - lim[i];
    cnt_ans += abs(sum[x]);
  }
  printf("%d\n", cnt_ans / 2);
  for (int i = 1; i <= m; i++) {
    lack[i].push_back(n + 1);
    sort(lack[i].begin(), lack[i].end());
  }
  for (int i = 1; i <= m; i++) {
    int now = 0;
    auto pos = l.begin();
    for (int j = 0; j < full[i].size(); j++) {
      int x = full[i][j];
      if (sum[x] <= 0) continue;
      if (pos == l.end()) break;
      while (lack[i][now] < (*pos)) now++;
      while ((pos != l.end()) && ((*pos) == lack[i][now])) {
        pos++;
        if (pos == l.end()) break;
        while (lack[i][now] < (*pos)) now++;
      }
      if (pos == l.end()) break;
      int val = *pos;
      sum[val]++;
      sum[x]--;
      printf("%d %d %d\n", x, val, i);
      pos++;
      if (sum[val] >= 0) l.erase(val);
    }
  }
  return 0;
}
