#include <bits/stdc++.h>
using namespace std;
const int N = 500055;
int nxt[N];
char s[N], t[N];
int k, slen, tlen, a[N], b[N];
int p1 = -1, p2;
void getNext(char *S, char *T) {
  int j, k;
  j = 0;
  k = -1;
  nxt[0] = -1;
  while (j < tlen)
    if (k == -1 || T[j] == T[k])
      nxt[++j] = ++k;
    else
      k = nxt[k];
}
void KMP(char *S, char *T, int *q) {
  for (int i = 0; i < N; i++) q[i] = 0x3f3f3f3f;
  int i = 0, j = 0;
  getNext(S, T);
  while (i < slen && j < tlen) {
    if (j == -1 || S[i] == T[j]) {
      i++;
      j++;
    } else {
      j = nxt[j];
    }
    int qw = j;
    while (i >= k && qw <= k && qw >= 0 && q[qw] == 0x3f3f3f3f) {
      q[qw] = min(q[qw], i - 1);
      qw = nxt[qw];
    }
    if (j == tlen && p1 == -1) {
      p1 = max(i - k - 1, 0);
      p2 = p1 + k;
      if (p2 + k > slen) {
        p2 = 0;
        if (p2 + k <= p1) {
          swap(p1, p2);
        } else
          p1 = -1;
      }
    }
  }
  if (i >= k && j <= k && j >= 0) {
    q[j] = min(q[j], i - 1);
  }
}
int main() {
  cin >> slen >> tlen >> k;
  scanf("%s", s);
  scanf("%s", t);
  KMP(s, t, a);
  reverse(s, s + slen);
  reverse(t, t + tlen);
  KMP(s, t, b);
  for (int i = 0; i <= k; i++) {
    if (b[i] != 0x3f3f3f3f) b[i] = slen - b[i] - 1;
  }
  for (int i = 0; i <= min(tlen, k); i++) {
    if (a[i] < b[tlen - i] && a[i] != 0x3f3f3f3f && b[tlen - i] != 0x3f3f3f3f) {
      p1 = a[i] - k + 1;
      p2 = b[tlen - i];
    }
  }
  if (p1 != -1) {
    puts("Yes");
    cout << p1 + 1 << " " << p2 + 1;
  } else {
    puts("No");
  }
  return 0;
}
