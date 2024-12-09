#include <bits/stdc++.h>
using namespace std;
struct fastIO {
  inline fastIO operator>>(int& num) {
    num = 0;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    bool foo = 0;
    if (c == '-') {
      foo = 1;
      c = getchar();
    }
    while (c >= '0' && c <= '9') {
      num = (num << 3) + (num << 1) + c - '0';
      c = getchar();
    }
    if (foo) num = -num;
    return *this;
  }
  inline fastIO operator>>(long long& num) {
    num = 0;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    bool foo = 0;
    if (c == '-') {
      foo = 1;
      c = getchar();
    }
    while (c >= '0' && c <= '9') {
      num = (num << 3) + (num << 1) + c - '0';
      c = getchar();
    }
    if (foo) num = -num;
    return *this;
  }
  inline fastIO operator>>(float& num) {
    scanf("%f", &num);
    return *this;
  }
  inline fastIO operator>>(double& num) {
    scanf("%lf", &num);
    return *this;
  }
  inline fastIO operator>>(long double& num) {
    scanf("%Lf", &num);
    return *this;
  }
  inline fastIO operator>>(char& num) {
    num = getchar();
    while (num == ' ' || num == '\n') num = getchar();
    return *this;
  }
  inline fastIO operator>>(char* num) {
    int cnt = 0;
    char c = getchar();
    while (c == ' ' || c == '\n') c = getchar();
    while (c != ' ' && c != '\n') {
      num[cnt++] = c;
      c = getchar();
    }
    num[cnt] = 0;
    return *this;
  }
  inline fastIO operator>>(string& num) {
    cin >> num;
    return *this;
  }
  inline void printInt(const int& num) {
    if (num < 10) {
      putchar(num + '0');
      return;
    }
    printInt(num / 10);
    putchar((num % 10) + '0');
  }
  inline void printINT(const long long& num) {
    if (num < 10) {
      putchar(num + '0');
      return;
    }
    printINT(num / 10);
    putchar((num % 10) + '0');
  }
  inline fastIO operator<<(const int& num) {
    if (num < 0)
      putchar('-'), printInt(-num);
    else
      printInt(num);
    return *this;
  }
  inline fastIO operator<<(const long long& num) {
    if (num < 0)
      putchar('-'), printINT(-num);
    else
      printINT(num);
    return *this;
  }
  inline fastIO operator<<(const float& num) {
    printf("%.10f", num);
    return *this;
  }
  inline fastIO operator<<(const double& num) {
    printf("%.16lf", num);
    return *this;
  }
  inline fastIO operator<<(const long double& num) {
    printf("%.20Lf", num);
    return *this;
  }
  inline fastIO operator<<(const char& num) {
    putchar(num);
    return *this;
  }
  inline fastIO operator<<(const char* num) {
    for (int i = 0; num[i]; i++) putchar(num[i]);
    return *this;
  }
  inline fastIO operator<<(const string& num) {
    cout << num;
    return *this;
  }
} fio;
int n, m, k;
int fuck[17][17];
int shit[17][17][17];
int dy[17];
int ans = 0;
void dfs(int x, int y, int mx) {
  if (x == n) {
    for (int i = 1; i <= mx; i++)
      for (int j = i + 1; j <= mx; j++)
        if (dy[i] && dy[j] && dy[i] == dy[j]) return;
    int fri = 0, bb = k;
    for (int i = 1; i <= mx; i++) {
      if (!dy[i])
        fri++;
      else
        bb--;
    }
    int fk = 1;
    for (int i = 0; i < fri; i++) {
      fk *= bb;
      bb--;
    }
    ans += fk;
    if (ans > 1000000007) ans -= 1000000007;
    return;
  }
  for (int i = 1; i <= mx + 1; i++) {
    if (shit[x][y][i]) continue;
    for (int ii = x; ii < n; ii++)
      for (int jj = y; jj < m; jj++) shit[ii][jj][i]++;
    bool fau = 1;
    if (fuck[x][y] && dy[i] && fuck[x][y] != dy[i]) fau = 0;
    if (fau) {
      bool dyed = 0;
      if (!dy[i]) {
        dy[i] = fuck[x][y];
        dyed = 1;
      }
      if (y < m - 1)
        dfs(x, y + 1, min(max(mx, i), k - 1));
      else
        dfs(x + 1, 0, min(max(mx, i), k));
      if (dyed) dy[i] = 0;
    }
    for (int ii = x; ii < n; ii++)
      for (int jj = y; jj < m; jj++) shit[ii][jj][i]--;
  }
}
int main() {
  fio >> n >> m >> k;
  if (n + m - 1 > k) {
    fio << "0\n";
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) fio >> fuck[i][j];
  dfs(0, 0, 0);
  fio << ans << '\n';
  return 0;
}
