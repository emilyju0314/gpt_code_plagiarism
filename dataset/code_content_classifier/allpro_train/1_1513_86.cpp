#include <bits/stdc++.h>
char arr[100003];
char good[11] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
int main() {
  scanf("%s", arr);
  int l = strlen(arr);
  bool isGood = true;
  for (int i = 0; i < l / 2; i++)
    if (arr[i] != arr[l - i - 1]) {
      isGood = false;
      break;
    } else {
      isGood = false;
      for (int j = 0; j < 11; j++)
        if (arr[i] == good[j]) {
          isGood = true;
          break;
        }
      if (!isGood) break;
    }
  if ((isGood) && (l % 2 == 1)) {
    isGood = false;
    for (int i = 0; i < 11; i++)
      if (arr[l / 2] == good[i]) {
        isGood = true;
        break;
      }
  }
  if (isGood)
    printf("YES");
  else
    printf("NO");
  return 0;
}
