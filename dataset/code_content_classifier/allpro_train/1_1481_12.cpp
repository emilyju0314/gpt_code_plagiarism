#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  return x * f;
}
template <typename T>
inline bool Max(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool Min(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
string pulld = "s10utsusdteds";
string pullr = "s10ltslsrters";
string pulll = "s10rtsrsltels";
string pull_all;
void make_pull_all() {
  for (int i = 0; i < 36; i++) {
    pull_all += pulld;
    pull_all += "ls";
  }
  for (int i = 0; i < 36; i++) {
    pull_all += "r";
  }
}
int main() {
  make_pull_all();
  string ans;
  ans += "d" + pull_all;
  ans += "d" + pull_all;
  ans += "uu" + pull_all;
  ans += "d";
  ans += "l0r";
  for (int i = 0; i < 32; i++) {
    ans += "1010utdtlt";
    ans += "r" + pullr + "l";
    ans += "1100utdtlt";
    ans += "l" + pulll + "l" + pulll + "rr";
    ans += "l";
  }
  ans += "rr";
  cout << ans << endl;
}
