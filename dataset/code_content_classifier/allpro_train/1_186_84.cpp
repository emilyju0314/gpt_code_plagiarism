#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
template <class T>
void read(T &x) {
  char ch;
  bool neg = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar()) neg = ch == '-';
  x = ch - '0';
  for (ch = getchar(); isdigit(ch); ch = getchar()) (x *= 10) += ch - '0';
  x *= neg ? -1 : 1;
}
template <class T, class... Args>
void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
template <class T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
void writei(T x) {
  write(x);
  putchar(' ');
}
template <class T>
void writeln(T x) {
  write(x);
  putchar('\n');
}
template <class T, class... Args>
void write(T x, Args &...args) {
  writei(x);
  writei(args...);
}
long long a[N];
int t = 1;
void solve() {
  long long n;
  read(n);
  for (long long i = 1; i <= n; i++) read(a[i]);
  if (n == 1) {
    cout << "1 1\n" << -a[1] << "\n1 1\n0\n1 1\n0\n";
    return;
  }
  cout << "1 1\n" << -a[1] << endl;
  cout << "2 " << n << endl;
  for (long long i = 2; i <= n; i++) {
    cout << a[i] * (n - 1) << " ";
  }
  cout << "\n1 " << n << "\n0 ";
  for (long long i = 2; i <= n; i++) {
    cout << -a[i] * n << " ";
  }
  cout << endl;
}
int main() {
  if (fopen("..."
            ".inp",
            "r")) {
    freopen(
        "..."
        ".inp",
        "r", stdin);
    freopen(
        "..."
        ".out",
        "w", stdout);
  }
  while (t--) {
    solve();
  }
}
