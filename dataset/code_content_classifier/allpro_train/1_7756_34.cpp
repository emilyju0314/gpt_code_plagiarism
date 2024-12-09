#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int N = 200005;
const double EPS = 1e-9;
int n, m, sl, k;
char arr[N];
string str;
int solve(int test) {
  scanf("%d", &n), scanf("%d", &m), scanf("%d", &sl), scanf("%d", &k);
  scanf("%s", arr);
  str = arr;
  int cnt = 0, sum = 0;
  vector<int> out;
  for (int i = 0;; i++) {
    if (i == n) {
      sum += cnt / sl;
      break;
    }
    if (str[i] == '0')
      cnt++;
    else
      sum += cnt / sl, cnt = 0;
  }
  cnt = 0;
  for (int i = 0;; i++) {
    if (sum == m - 1) break;
    if (str[i] == '0') {
      if (cnt == sl - 1)
        cnt = 0, sum--, out.push_back(i + 1);
      else
        cnt++;
    } else
      cnt = 0;
  }
  printf("%d\n", ((int)((out).size())));
  for (register int i = 0; i < ((int)((out).size())); i++)
    printf("%d ", out[i]);
  printf("\n");
  return test;
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) solve(i);
  return 0;
}
