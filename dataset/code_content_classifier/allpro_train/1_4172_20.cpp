#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
double s[N];
vector<int> stk;
int main(void) {
  int n;
  scanf("%d", &n);
  stk.push_back(0);
  for (int i = 1, val; i <= n; i++) {
    scanf("%d", &val);
    s[i] = s[i - 1] + val;
    while (stk.size() >= 2 &&
           (s[stk.back()] - s[stk[stk.size() - 2]]) /
                   (stk.back() - stk[stk.size() - 2]) >
               (s[i] - s[stk[stk.size() - 2]]) / (i - stk[stk.size() - 2]))
      stk.pop_back();
    stk.push_back(i);
  }
  int pre = 0;
  for (int& e : stk) {
    if (e == 0) continue;
    double v = (s[e] - s[pre]) / (e - pre);
    for (int i = pre + 1; i <= e; i++) printf("%.9f\n", v);
    pre = e;
  }
}
