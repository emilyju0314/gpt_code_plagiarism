#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const long long UNDEF = -1;
const long long INF = 1e18;
template <typename T>
inline bool chkmax(T& aa, T bb) {
  return aa < bb ? aa = bb, true : false;
}
template <typename T>
inline bool chkmin(T& aa, T bb) {
  return aa > bb ? aa = bb, true : false;
}
static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof(stdinBuffer);
static const char* stdinPos = stdinDataEnd;
void readAhead(size_t amount) {
  size_t remaining = stdinDataEnd - stdinPos;
  if (remaining < amount) {
    memmove(stdinBuffer, stdinPos, remaining);
    size_t sz = fread(stdinBuffer + remaining, 1,
                      sizeof(stdinBuffer) - remaining, stdin);
    stdinPos = stdinBuffer;
    stdinDataEnd = stdinBuffer + remaining + sz;
    if (stdinDataEnd != stdinBuffer + sizeof(stdinBuffer)) *stdinDataEnd = 0;
  }
}
int rint() {
  readAhead(16);
  int x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}
char rch() {
  readAhead(16);
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  char ans = *stdinPos;
  ++stdinPos;
  return ans;
}
long long rlong() {
  readAhead(32);
  long long x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}
const int LIM = 10000 * 10000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n = rint(), m = rint();
  if (m == 3) {
    if (n == 3) {
      printf("0 0\n0 1\n1 0\n");
    } else if (n == 4) {
      printf("0 0\n3 0\n0 3\n1 1\n");
    }
    if (n >= 5) {
      printf("-1\n");
    }
  } else {
    {
      int y = 0;
      for (int x = 0; x < m; x++) {
        printf("%d %d\n", -LIM + x, y);
        y += (x + 1);
      }
    }
    {
      int y = 0;
      for (int x = 0; x < n - m; x++) {
        printf("%d %d\n", LIM - x, y);
        y += (x + 1);
      }
    }
  }
}
