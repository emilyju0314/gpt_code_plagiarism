#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > q;
int main() {
  char ch[60000];
  scanf("%s", ch);
  long long c = 0;
  long long now = 0;
  int flag = 1;
  for (int i = 0; ch[i] != 0; i++) {
    if (ch[i] == '(')
      now++;
    else
      now--;
    if (ch[i] == '?') {
      int a, b;
      scanf("%d%d", &a, &b);
      ch[i] = ')';
      q.push(make_pair(b - a, i));
      c += b;
    }
    if (flag && now < 0) {
      if (q.empty())
        flag = 0;
      else {
        pair<int, int> x = q.top();
        q.pop();
        ch[x.second] = '(';
        c -= x.first;
        now += 2;
      }
    }
  }
  if (now != 0 || !flag)
    puts("-1");
  else
    cout << c << endl << ch << endl;
  return 0;
}
