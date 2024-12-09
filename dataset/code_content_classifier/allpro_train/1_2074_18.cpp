#include <stdio.h>
#include <string.h>

int main(void) {
  int i, j, k, ans = 1, bef = 0, num = 1, mnum = 1;
  char s[10010];
  scanf("%s", s);
  for(i = 0; i < strlen(s); ) {
    if(s[i] == 'e') {
      if(!i) {
        bef = 0;
        i += 3;
        continue;
      }
      if(bef == 1) {
        num++;
        bef = 0;
        if(mnum < num) mnum = num, ans = 0;
      } else {
        bef = 0;
        num = 1;
      }
      i += 3;
    } else {
      if(!i) {
        bef = 1;
        i += 7;
        continue;
      }
      if(bef == 0) {
        num++;
        bef = 1;
        if(mnum < num) mnum = num, ans = 1;
      } else {
        bef = 1;
        num = 1;
      }
      i += 7;
    }
  }
  if(ans == -1) ans = bef;
  if(ans) printf("chicken\n");
  else printf("egg\n");
  return 0;
}
