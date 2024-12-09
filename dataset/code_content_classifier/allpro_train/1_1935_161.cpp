#include <bits/stdc++.h>
using namespace std;
string st;
int cnt[5];
int main() {
  cin >> st;
  for (int i = 0; i < st.length(); i++)
    if (st[i] == 'x')
      cnt[0]++;
    else
      cnt[1]++;
  if (cnt[0] > cnt[1])
    for (int i = 1; i <= cnt[0] - cnt[1]; i++) printf("x");
  else
    for (int i = 1; i <= cnt[1] - cnt[0]; i++) printf("y");
}
