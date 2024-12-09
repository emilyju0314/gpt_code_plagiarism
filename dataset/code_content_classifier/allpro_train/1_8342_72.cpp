#include <bits/stdc++.h>
using namespace std;
char buf[1000000 + 1];
struct entry {
  char *start;
  int len;
} input[2000];
char str_buf[2000 + 1];
int str_len;
int arrange[2000];
long long arrange_len[2000 + 1];
long long dp[2000][2000];
int nearest[26][1000000 + 1];
int N, M;
long long find_nearest(int M, long long start_offset, struct entry *input,
                       int *arrange, long long *arrange_len, int nearest_ch[]) {
  if (start_offset >= arrange_len[M]) {
    return -1;
  }
  int high = M, low = 0;
  while (low != high - 1) {
    int mid = (high + low) >> 1;
    if (arrange_len[mid] > start_offset) {
      high = mid;
    } else {
      low = mid;
    }
  }
  int i = low;
  int j = start_offset - arrange_len[low];
  int ans = nearest_ch[(input[arrange[i]].start - buf) + j];
  while (ans == -1 && ++i != M) {
    ans = nearest_ch[(input[arrange[i]].start - buf)];
  }
  return ans == -1 ? -1 : arrange_len[i] + ans;
}
void build_nearest(int N, struct entry *input, int nearest[][1000000 + 1]) {
  for (int i = 0; i < N; i++) {
    int len = (input[i].start - buf) + input[i].len;
    int j = input[i].len;
    while (j--) {
      --len;
      int ch = input[i].start[j] - 'a';
      nearest[ch][len] = j;
    }
  }
  for (int k = 0; k < 26; k++) {
    for (int i = 0; i < N; i++) {
      int offset = (input[i].start - buf);
      for (int j = input[i].len - 2 + offset; j != offset - 1; j--) {
        if (nearest[k][j] == -1) {
          nearest[k][j] = nearest[k][j + 1];
        }
      }
    }
  }
}
int main() {
  scanf("%d\n", &N);
  char *cur_buf = buf;
  for (int i = 0; i < N; i++) {
    scanf(" %s ", cur_buf);
    input[i].start = cur_buf;
    input[i].len = strlen(cur_buf);
    cur_buf += input[i].len;
  }
  scanf("%d\n", &M);
  long long len = 0;
  for (int i = 0; i < M; i++) {
    scanf("%d", arrange + i);
    --arrange[i];
    arrange_len[i] = len;
    len += input[arrange[i]].len;
  }
  arrange_len[M] = len;
  scanf(" %s ", str_buf);
  str_len = strlen(str_buf);
  memset(nearest, 255, sizeof(nearest));
  build_nearest(N, input, nearest);
  memset(dp, 255, sizeof(dp));
  for (int i = 0; i < str_len; i++) {
    for (int j = 0; j <= i; j++) {
      if (i != 0) {
        dp[i][j] = dp[i - 1][j];
      }
      int ch = str_buf[i] - 'a';
      long long next = -1LL;
      if (j == 0) {
        next = find_nearest(M, 0, input, arrange, arrange_len, nearest[ch]);
      } else if (dp[i - 1][j - 1] != -1LL) {
        next = find_nearest(M, dp[i - 1][j - 1] + 1, input, arrange,
                            arrange_len, nearest[ch]);
      }
      if (next != -1 && (dp[i][j] == -1 || dp[i][j] > next)) {
        dp[i][j] = next;
      }
    }
  }
  int ans = str_len - 1;
  while (ans != -1 && dp[str_len - 1][ans] == -1LL) {
    --ans;
  }
  printf("%d\n", ans + 1);
}
