#include <bits/stdc++.h>
using namespace std;
int number[200005];
int main() {
  int n, total = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", number + i);
    total += number[i];
  }
  vector<int> idx;
  for (int i = 0; i < n; i++)
    if ((total - number[i]) == number[i] * (n - 1)) idx.push_back(i + 1);
  printf("%d\n", (int)idx.size());
  for (unsigned int i = 0; i < idx.size(); i++) printf("%d ", idx[i]);
  puts("");
  return 0;
}
