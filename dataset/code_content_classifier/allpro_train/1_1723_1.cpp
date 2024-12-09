#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef long long int LL;
const LL INF = 1000000000;

int comp[1005];
int len[1005];
char str[1005][20];
int cost[1 << 17];
int n;
priority_queue<pair<int,int> > Q;

int getLen(int mask) {
  int ret = 0;
  while (mask > 1) {
    mask /= 2;
    ret++;
  }
  return ret;
}

int rev(int mask, int l) {
  int ret = 0;
  for (int i = 0; i < l; i++) {
    ret |= (1 << (l-i-1)) * ((mask & (1 << i)) > 0);
  }
  return ret;
}

int merg(int M, int m, int l) {
  int mask = (1 << l) - 1;
  return (M & mask) == (m & mask);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str[i]);
    int l = strlen(str[i]);
    for (int j = 0; j < l; j++) {
      comp[i] |= (1 << j) * (str[i][j] - '0');
    }
    comp[i] |= (1 << l);
    len[i] = l;
  }
  for (int i = 0; i < 1<<17; i++) {
    cost[i] = -1;
  }
  Q.push(pair<int,int>(0, 1));
  while (!Q.empty()) {
    int v = Q.top().second;
    int c = -Q.top().first;
    Q.pop();
    if (cost[v] != -1) continue;
    cost[v] = c;
    int L = getLen(v);
    int Ma = v ^ (1 << L);
    for (int i = 0; i < n; i++) {
      int l = len[i];
      int ma = comp[i] ^ (1 << l);
      if (L + l <= 16) {
        int nmask = Ma | (ma << (L));
        nmask |= (1 << (L + l));
        if (cost[nmask] == -1) {
          Q.push(pair<int,int>(-(c + l), nmask));
        }
      }
      if (L >= l && merg(Ma, ma, l)) {
        int nmask = Ma >> l;
        nmask |= (1 << (L-l));
        if (cost[nmask] == -1) {
          Q.push(pair<int,int>(-(c), nmask));
        }
      }
      if (l >= L && merg(Ma, ma, L)) {
        int nmask = ma >> L;
        nmask |= (1 << (l-L));
        if (cost[nmask] == -1) {
          Q.push(pair<int,int>(-(c + (l-L)), nmask));
        }
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int a = i, b = j;
      if (len[i] < len[j]) {
        a = j;
        b = i;
      }
      int val = 1;
      for (int k = 0; k < len[b]; k++) {
        if (str[a][len[a]-1 - k] != str[b][len[b]-1 - k]) {
          val = 0;
          break;
        }
      }
      if (val == 1) {
        int mask = 0, car = 1;
        for (int k = 0; k < len[a] - len[b]; k++) {
          mask |= car * (str[a][k] - '0');
          car *= 2;
        }
        mask |= car;
        if (cost[mask] != -1) {
          ans = min(ans, cost[mask] + len[b]);
        }
      }
    }
  }
  if (ans < INF) printf("%d\n", ans);
  else printf("0\n");
  return 0;
}
