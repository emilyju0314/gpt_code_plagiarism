#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[8][11];
  char nums[10][11];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 10; j++) cin >> s[i][j];
    s[i][10] = '\0';
  }
  for (int i = 0; i < 10; i++) cin >> nums[i];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 10; j++)
      if (!strcmp(nums[j], s[i])) {
        cout << j;
        break;
      }
  }
  return 0;
}
