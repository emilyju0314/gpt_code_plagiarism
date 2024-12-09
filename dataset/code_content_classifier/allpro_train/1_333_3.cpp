#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

int n, m, k;
char input[6][500];
char str[10000100];
set<string> opened;

string Open(int &pos) {
  string ret;
  while (input[5][pos] != '\0' && input[5][pos] != ')') {
    if (isdigit(input[5][pos])) {
      int num = 0;
      while (isdigit(input[5][pos])) {
        num *= 10;
        num += input[5][pos++] - '0';
        num = min(num, m);
      }
      assert(num != 0);
      assert(input[5][pos] == '(');
      pos++;
      string nret = Open(pos);
      assert(input[5][pos] == ')');
      pos++;
      num = min(num, max(2, (m + (int)nret.size() - 1) / (int)nret.size()));
      if (nret.size() >= 400) {
        if (opened.count(nret)) { num = 1; }
        opened.insert(nret);
      }
      string add;
      REP(i, num) { add += nret; }
      if (add.size() >= 400) { opened.insert(add); }
      ret += add;
    } else {
      ret += input[5][pos++];
    }
  }
  assert((int)ret.size() <= 10000000);
  return ret;
}

int main() {
  while (scanf("%d %d %d", &n, &m, &k) > 0) {
    opened.clear();
    scanf("%s", input[5]);
    REP(i, k) {
      scanf("%s", input[i]);
    }
    {
      int pos = 0;
      string s = Open(pos);
      sprintf(str, "%s", s.c_str());
    }
    int ans = -1;
    int maxValue = -1;
    REP(iter, k) {
      int lv = 0;
      REP(r, m) {
        REP(l, r + 1) {
          char c = input[iter][r + 1];
          input[iter][r + 1] = 0;
          lv += strstr(str, input[iter] + l) != NULL;
          input[iter][r + 1] = c;
        }
      }
      if (lv > maxValue) {
        ans = iter + 1;
        maxValue = lv;
      }
    }
    printf("%d %d\n", ans, maxValue);
  }
}