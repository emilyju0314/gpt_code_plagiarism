#include <bits/stdc++.h>
int64_t k;
int a, b;
int result[9];
int ascore[9] = {0, 0, 1, 1, 0, 0, 0, 1, 0};
int bscore[9] = {0, 1, 0, 0, 0, 1, 1, 0, 0};
int stack[10];
int64_t atotalscore, btotalscore;
int cyclestart, cycleend, cyclelength;
int acyclescore, bcyclescore;
int64_t cycletime, cycleremain;
int main() {
  int i, j, t;
  scanf("%I64d%d%d", &k, &a, &b);
  stack[0] = 3 * (a - 1) + (b - 1);
  for (i = 0; i < 9; i++) {
    scanf("%d", &t);
    result[i] = 3 * (t - 1);
  }
  for (i = 0; i < 9; i++) {
    scanf("%d", &t);
    result[i] += (t - 1);
  }
  for (i = 1; i < k; i++) {
    stack[i] = result[stack[i - 1]];
    for (j = 0; j < i; j++) {
      if (stack[i] == stack[j]) {
        cyclestart = j;
        cycleend = i - 1;
        cyclelength = i - j;
        break;
      }
    }
    if (cyclelength != 0) break;
  }
  if (cyclelength == 0) {
    for (i = 0; i < k; i++) {
      atotalscore += ascore[stack[i]];
      btotalscore += bscore[stack[i]];
    }
    printf("%I64d %I64d\n", atotalscore, btotalscore);
    return 0;
  }
  for (i = 0; i < cyclestart; i++) {
    atotalscore += ascore[stack[i]];
    btotalscore += bscore[stack[i]];
  }
  for (i = cyclestart; i <= cycleend; i++) {
    acyclescore += ascore[stack[i]];
    bcyclescore += bscore[stack[i]];
  }
  cycletime = (k - cyclestart) / cyclelength;
  cycleremain = (k - cyclestart) % cyclelength;
  atotalscore += acyclescore * cycletime;
  btotalscore += bcyclescore * cycletime;
  for (i = cyclestart; i < cyclestart + cycleremain; i++) {
    atotalscore += ascore[stack[i]];
    btotalscore += bscore[stack[i]];
  }
  printf("%I64d %I64d\n", atotalscore, btotalscore);
  return 0;
}
