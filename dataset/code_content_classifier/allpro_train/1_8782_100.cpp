#include <bits/stdc++.h>
using namespace std;
int get();
queue<int> q1, q2, q3;
int k, n1, n2, n3, t1, t2, t3;
int main() {
  cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
  int i;
  int t = 0;
  for (i = 0; i < n1; i++) q1.push(0);
  for (i = 0; i < n2; i++) q2.push(0);
  for (i = 0; i < n3; i++) q3.push(0);
  while (k--) {
    int time = get();
    q1.push(time);
    q2.push(time + t2);
    q3.push(time + t2 + t3);
    q1.pop();
    q2.pop();
    q3.pop();
  }
  int ans = q3.back();
  printf("%d\n", ans);
  return 0;
}
int get() {
  int num1 = q1.front();
  int res = num1;
  int num2 = q2.front();
  int num3 = q3.front();
  int res2 = num3 - t1 - t2;
  int res3 = num2 - t1;
  if (res < res2) res = res2;
  if (res < res3) res = res3;
  return res + t1;
}
