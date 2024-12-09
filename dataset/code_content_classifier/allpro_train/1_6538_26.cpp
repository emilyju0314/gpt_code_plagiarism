#include <bits/stdc++.h>
using namespace std;
const int MAX_STRING_LENGTH = 5e3 + 10;
struct _io {
  char buff[MAX_STRING_LENGTH];
  _io &operator>>(int &x) {
    scanf("%d", &x);
    return *this;
  }
  _io &operator>>(long long &x) {
    scanf("%lld", &x);
    return *this;
  }
  _io &operator>>(float &x) {
    scanf("%f", &x);
    return *this;
  }
  _io &operator>>(double &x) {
    scanf("%lf", &x);
    return *this;
  }
  _io &operator>>(long double &x) {
    scanf("%Lf", &x);
    return *this;
  }
  _io &operator>>(char &c) {
    do {
      scanf("%c", &c);
    } while (c == ' ' || c == '\n');
    return *this;
  }
  _io &operator>>(char *s) {
    scanf("%s", s);
    return *this;
  }
  _io &operator>>(string &s) {
    scanf("%s", buff);
    s = string(buff, strlen(buff));
    return *this;
  }
  _io &operator<<(const int x) {
    printf("%d", x);
    return *this;
  }
  _io &operator<<(const long long x) {
    printf("%lld", x);
    return *this;
  }
  _io &operator<<(const float x) {
    printf("%f", x);
    return *this;
  }
  _io &operator<<(const double &x) {
    printf("%lf", x);
    return *this;
  }
  _io &operator<<(const long double &x) {
    printf("%Lf", x);
    return *this;
  }
  _io operator<<(const char &c) {
    printf("%c", c);
    return *this;
  }
  _io &operator<<(const string &s) {
    printf("%s", s.c_str());
    return *this;
  }
  _io &operator<<(const char *s) {
    printf("%s", s);
    return *this;
  }
} io;
const int maxn = 5e2 + 10;
const long long MOD = 1e9 + 7;
int g[maxn][maxn];
int getA(int n) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      if (g[i][j] == 0) {
        return i;
      }
    }
  }
  return -1;
}
int main() {
  int n, m;
  io >> n >> m;
  if (m == (n * (n - 1)) / 2) {
    io << "Yes"
       << "\n";
    for (int i = 0; i < n; ++i) {
      io << "a";
    }
  } else {
    for (int i = 0; i < m; ++i) {
      int u, v;
      io >> u >> v;
      g[u][v] = g[v][u] = 1;
    }
    int au = getA(n);
    if (au == -1) {
      io << "No";
      return 0;
    }
    int colors[n + 1];
    for (int i = 0; i <= n; ++i) colors[i] = -1;
    colors[au] = 1;
    for (int i = 1; i <= n; ++i) {
      if (i == au) continue;
      if (g[au][i] == 0) {
        colors[i] = 3;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (i == au) continue;
      if (colors[i] == 3) {
        for (int j = 1; j <= n; ++j) {
          if (j == au or j == i) continue;
          if (g[au][j] == 1 and g[i][j] == 1) {
            colors[j] = 2;
          } else if (g[au][j] == 1 and g[i][j] == 0) {
            colors[j] = 1;
          }
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (colors[i] == -1) {
        io << "No";
        return 0;
      }
      for (int j = 1; j <= n; ++j) {
        if (i == j) continue;
        if (colors[i] == colors[j] and g[i][j] == 0) {
          io << "No";
          return 0;
        }
        if (colors[i] == 2 and g[i][j] == 0) {
          io << "No";
          return 0;
        }
        if (colors[i] == 1 and colors[j] == 3 and g[i][j] == 1) {
          io << "No";
          return 0;
        }
      }
    }
    io << "Yes"
       << "\n";
    string s = "#abc";
    for (int i = 1; i <= n; ++i) {
      io << s[colors[i]];
    }
  }
  return 0;
}
