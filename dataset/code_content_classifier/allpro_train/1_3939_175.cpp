#include <bits/stdc++.h>
using namespace std;
char s[1000001], t[1000001];
int sol, cnt, length_s, length_t, found;
struct state {
  int start, end;
};
state Left, Right;
state p[1000001];
int total;
int main() {
  scanf("%s %s", s, t);
  length_s = strlen(s);
  length_t = strlen(t);
  Left.start = Left.end = Right.start = Right.end = -1;
  for (int i = 0; i < length_t; ++i) {
    if (t[i] == s[cnt]) {
      ++cnt;
      if (cnt == 1) {
        Left.start = i;
      }
      if (cnt == length_s) {
        Left.end = i;
        break;
      }
    }
  }
  if (Left.end == -1) {
    printf("0\n");
    return 0;
  }
  --cnt;
  for (int i = length_t - 1; i >= Left.end + 1; --i) {
    if (t[i] == s[cnt]) {
      if (cnt == 0) {
        Right.start = i;
        break;
      }
      if (cnt == length_s - 1) {
        Right.end = i;
      }
      --cnt;
    }
  }
  if (Right.start != -1) {
    sol = Right.start - Left.end;
  }
  printf("%d\n", sol);
  return 0;
}
