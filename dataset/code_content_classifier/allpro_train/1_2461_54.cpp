#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Node {
  int maxx, max_index;
  int minn, min_index;
} node1[N], node2[N];
int n, a[N];
int main() {
  cin >> n;
  for (register int i = 1; i <= n; i++) cin >> a[i];
  int maxx = -0x3f3f3f3f, minn = 0x3f3f3f3f;
  for (register int i = 1; i <= n; i++) {
    if (maxx < a[i]) {
      maxx = a[i];
      node1[i].maxx = maxx;
      node1[i].max_index = i;
    } else {
      node1[i].maxx = node1[i - 1].maxx;
      node1[i].max_index = node1[i - 1].max_index;
    }
    if (minn > a[i]) {
      minn = a[i];
      node1[i].minn = minn;
      node1[i].min_index = i;
    } else {
      node1[i].minn = node1[i - 1].minn;
      node1[i].min_index = node1[i - 1].min_index;
    }
  }
  maxx = -0x3f3f3f3f, minn = 0x3f3f3f3f;
  for (register int i = n; i >= 1; i--) {
    if (maxx < a[i]) {
      maxx = a[i];
      node2[i].maxx = maxx;
      node2[i].max_index = i;
    } else {
      node2[i].maxx = node2[i + 1].maxx;
      node2[i].max_index = node2[i + 1].max_index;
    }
    if (minn > a[i]) {
      minn = a[i];
      node2[i].minn = minn;
      node2[i].min_index = i;
    } else {
      node2[i].minn = node2[i + 1].minn;
      node2[i].min_index = node2[i + 1].min_index;
    }
  }
  for (register int i = 2; i <= n - 1; i++) {
    if (a[i] > node1[i - 1].minn && a[i] > node2[i + 1].minn) {
      puts("3");
      printf("%d %d %d", node1[i - 1].min_index, i, node2[i + 1].min_index);
      return 0;
    }
    if (a[i] < node1[i - 1].maxx && a[i] < node2[i + 1].maxx) {
      puts("3");
      printf("%d %d %d", node1[i - 1].max_index, i, node2[i + 1].max_index);
      return 0;
    }
  }
  printf("0");
  return 0;
}
