#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, Min, Max, cnt = 0, x;
  scanf("%d", &n);
  scanf("%d", &x);
  Max = x;
  Min = x;
  while (n--) {
    scanf("%d", &x);
    if (x > Max) {
      cnt++;
      Max = x;
    }
    if (x < Min) {
      cnt++;
      Min = x;
    }
  }
  printf("%d", cnt);
}
