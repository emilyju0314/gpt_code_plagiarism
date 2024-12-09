#include <bits/stdc++.h>
using namespace std;
const long long LINF = 1E18;
const int INF = 1E9;
const int MOD = 1E9 + 7;
const int N = 4E5 + 5;
int t = 1;
int n, a[N];
void Input() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
}
void Prepare() {}
int cnt = 0;
pair<int, int> x[N];
int res = 0;
int R, C;
vector<int> Path[N];
bool Cho[N];
bool cmp(pair<int, int> a1, pair<int, int> a2) { return a1.first > a2.first; }
void Solve() {
  sort(a + 1, a + 1 + n);
  x[1] = {1, a[1]};
  cnt = 1;
  for (int i = 2; i <= n; i++)
    if (a[i] == x[cnt].second)
      x[cnt].first++;
    else
      x[++cnt] = {1, a[i]};
  sort(x + 1, x + 1 + cnt, cmp);
  for (int r = 1; r * (r - 20) <= n; r++) {
    int sum = 0;
    for (int i = 1; i <= cnt; i++) sum += min(x[i].first, r);
    int c = sum / r;
    if (c < r) continue;
    if (r * c >= res) {
      res = r * c;
      R = r;
      C = c;
    }
  }
  int r = R, c = C;
  if (r > c) swap(r, c);
  int all = r + c - 1;
  for (int i = 1; i <= r; i++) Path[i].resize(c + 5);
  for (int i = 1; i <= cnt; i++) x[i].first = min(x[i].first, r);
  int Pointer = 1;
  for (int i = r; i <= c; i++) {
    int xx = 1;
    int yy = i - r + 1;
    for (int j = 1; j <= r; j++) {
      Path[xx][yy] = x[Pointer].second;
      x[Pointer].first--;
      if (x[Pointer].first <= 0) Pointer++;
      xx++;
      yy++;
    }
  }
  int dem = r;
  int dem2 = 0;
  for (int i = r - 1; i >= 1; i--) {
    int xx, yy;
    dem--;
    dem2++;
    xx = 1;
    yy = c - dem + 1;
    for (int j = 1; j <= dem; j++) {
      Path[xx][yy] = x[Pointer].second;
      x[Pointer].first--;
      if (x[Pointer].first <= 0) Pointer++;
      xx++;
      yy++;
    }
    xx = r - dem2 + 1;
    yy = 1;
    for (int j = 1; j <= dem2; j++) {
      Path[xx][yy] = x[Pointer].second;
      x[Pointer].first--;
      if (x[Pointer].first <= 0) Pointer++;
      xx++;
      yy++;
    }
  }
  cout << res << endl;
  cout << r << " " << c << endl;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) cout << Path[i][j] << " ";
    cout << endl;
  }
}
void check() {
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++)
      for (int k = j + 1; k <= C; k++)
        if (Path[i][j] == Path[i][k]) {
          cout << "WRONG ANSWER!";
          return;
        }
  }
  for (int i = 1; i <= C; i++) {
    for (int j = 1; j <= R; j++)
      for (int k = j + 1; k <= R; k++)
        if (Path[j][i] == Path[k][i]) {
          cout << "WRONG ANSWER!";
          return;
        }
  }
  cout << "ACCEPT!";
}
int main() {
  if (fopen("606F"
            ".inp",
            "r")) {
    freopen(
        "606F"
        ".inp",
        "r", stdin);
    freopen(
        "606F"
        ".out",
        "w", stdout);
  }
  Input();
  Prepare();
  while (t--) Solve();
}
