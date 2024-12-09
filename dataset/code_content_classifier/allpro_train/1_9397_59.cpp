#include <bits/stdc++.h>
using namespace std;
int n, a[2001000];
priority_queue<int> q;
void init() {
  int first;
  a[0] = -1e9;
  while (!q.empty()) q.pop();
  for (int i = (1); i <= (n); ++i) {
    scanf("%d", &first);
    q.push(-(first + (i - 1)));
  }
}
void work() {
  for (int i = (1); i <= (n); ++i) {
    int first = -q.top();
    q.pop();
    first += (1 - i);
    if (first < a[i - 1]) {
      puts(":(");
      return;
    }
    a[i] = first;
  }
  for (int i = (1); i <= (n); ++i) printf("%d%c", a[i], i == n ? '\n' : ' ');
}
int main() {
  while (cin >> n) {
    init();
    work();
  }
  return 0;
}
