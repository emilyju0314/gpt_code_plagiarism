#include <bits/stdc++.h>
using namespace std;
char S[(100005)];
stack<pair<pair<int, int>, char> > ST;
int main() {
  int i;
  scanf("%s", S);
  int L = strlen(S);
  int sol = 0;
  int start = 0;
  int len = 0;
  ST.push((pair<pair<int, int>, char>(pair<int, int>(0, 0), 0)));
  for (i = 0; i < L; ++i) {
    if (S[i] == '(' || S[i] == '[') {
      ST.push((pair<pair<int, int>, char>(pair<int, int>(0, 0), S[i])));
    } else {
      if ((S[i] == ')' && ST.top().second == '(') ||
          (S[i] == ']' && ST.top().second == '[')) {
        pair<pair<int, int>, char> p = ST.top();
        ST.pop();
        int l = p.first.second;
        pair<pair<int, int>, char> &t = ST.top();
        t.first.second += l + (S[i] == ']');
        t.first.first += p.first.first + 2;
        if (sol < t.first.second) {
          sol = t.first.second;
          len = t.first.first;
          start = i - len + 1;
        }
      } else
        ST.push((pair<pair<int, int>, char>(pair<int, int>(0, 0), 0)));
    }
  }
  printf("%d\n", sol);
  if (sol > 0) {
    for (i = 0; i < len; ++i) putchar(S[start + i]);
    putchar('\n');
  }
  return 0;
}
