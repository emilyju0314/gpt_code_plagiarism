#include <bits/stdc++.h>
using namespace std;
const long long sz = 105;
long long dp[sz][sz][sz], len1, len2, len3;
long long prefMatch[sz][26];
char s1[sz], s2[sz], s3[sz];
string ans;
long long solve(long long pos1, long long pos2, long long pos3) {
  if (pos3 > len3) return -(1LL << 61);
  if (pos1 > len1 || pos2 > len2) return 0;
  long long &ret = dp[pos1][pos2][pos3];
  if (ret != -1) return ret;
  ret = solve(pos1 + 1, pos2, pos3);
  ret = max(ret, solve(pos1, pos2 + 1, pos3));
  if (s1[pos1] == s2[pos2]) {
    if (s3[pos3] == s1[pos1])
      ret = max(ret, 1 + solve(pos1 + 1, pos2 + 1, pos3 + 1));
    else {
      long long mx = (s3[1] == s1[pos1]) ? 1 : 0, ch = s1[pos1] - 'A';
      ;
      mx = max(mx, prefMatch[pos3 - 1][ch]);
      ret = max(ret, 1 + solve(pos1 + 1, pos2 + 1, mx + 1));
    }
  }
  return ret;
}
void make_ans(long long pos1, long long pos2, long long pos3, long long res) {
  if (pos1 > len1 || pos2 > len2) return;
  if (solve(pos1 + 1, pos2, pos3) == res)
    make_ans(pos1 + 1, pos2, pos3, res);
  else if (solve(pos1, pos2 + 1, pos3) == res)
    make_ans(pos1, pos2 + 1, pos3, res);
  else {
    ans.push_back(s1[pos1]);
    if (s3[pos3] == s1[pos1])
      make_ans(pos1 + 1, pos2 + 1, pos3 + 1, res - 1);
    else {
      long long mx = (s3[1] == s1[pos1]) ? 1 : 0, ch = s1[pos1] - 'A';
      mx = max(mx, prefMatch[pos3 - 1][ch]);
      make_ans(pos1 + 1, pos2 + 1, mx + 1, res - 1);
    }
  }
}
int main() {
  scanf("%s %s %s", s1 + 1, s2 + 1, s3 + 1);
  len1 = strlen(s1 + 1);
  len2 = strlen(s2 + 1);
  len3 = strlen(s3 + 1);
  for (long long i = 1; i <= len3; ++i) {
    for (long long j = i, k = 1; j <= len3; j++, k++) {
      if (s3[j] != s3[k]) break;
      if (k + 1 <= len3) {
        long long ch = s3[k + 1] - 'A';
        prefMatch[j][ch] = max(prefMatch[j][ch], k + 1);
      }
    }
  }
  memset(dp, -1, sizeof(dp));
  long long got = solve(1, 1, 1);
  if (got == 0) {
    cout << 0 << '\n';
    return 0;
  }
  make_ans(1, 1, 1, got);
  cout << ans << '\n';
  return 0;
}
