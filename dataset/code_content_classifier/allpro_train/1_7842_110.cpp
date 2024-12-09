#include <bits/stdc++.h>
using namespace std;
int lens[101];
int n, k;
int lenpick;
int main() {
  char read[101];
  scanf("%d%d", &n, &k);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%s", read);
    lens[i] = (int)strlen(read);
  }
  scanf("%s", read);
  lenpick = (int)strlen(read);
  std::sort(lens, lens + n);
  int minth = -1;
  int maxth = -1;
  for (i = 0; i < n; i++) {
    if ((lens[i] == lenpick) && (minth == -1)) minth = i + 1;
    if ((lens[i] != lenpick) && (minth != -1) && (maxth == -1)) {
      maxth = i;
      break;
    }
  }
  if (maxth == -1) maxth = n;
  printf("%d %d\n", minth + ((minth - 1) / k) * 5,
         maxth + ((maxth - 1) / k) * 5);
}
