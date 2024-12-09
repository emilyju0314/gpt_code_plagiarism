#include <bits/stdc++.h>
using namespace std;
int a[100000];
int st[32];
bool del[32];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int size = 0;
  set<int> ans;
  for (int i = 0; i < n; i++) {
    memset(del, 0, size);
    for (int j = size - 1, x = a[i]; j >= 0; j--) {
      if ((x | st[j]) == x) del[j] = 1;
      x |= st[j];
    }
    int osize = size;
    size = 0;
    for (int j = 0; j < osize; j++)
      if (!del[j]) st[size++] = st[j] | a[i];
    st[size++] = a[i];
    for (int j = 0; j < size; j++) ans.insert(st[j]);
  }
  printf("%d\n", ans.size());
  return 0;
}
