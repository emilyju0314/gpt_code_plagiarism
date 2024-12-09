#include <bits/stdc++.h>
using namespace std;
void scanStr(char *str) {
  long long int i = 1;
  char ch;
  for (ch = getchar(); ch != '\n' && ch != ' '; ch = getchar()) str[i++] = ch;
  str[i] = '\0';
  return;
}
inline void fastOut(long long int n) {
  if (n < 10) {
    putchar(n + '0');
    return;
  }
  fastOut(n / 10);
  putchar(n % 10 + '0');
  return;
}
inline long long int scan() {
  long long int n = 0;
  char c;
  for (c = getchar(); c == ' ' || c == '\n' || c == '\t'; c = getchar())
    ;
  for (; c > 0x2f && c < 0x3a; c = getchar()) n = (n * 10) + (c & 0x0f);
  return n;
}
long long int arr[1000010], sum[1000010], L;
long long int binarySearch(long long int l, long long int r, long long int t,
                           long long int m) {
  if (arr[l] > t) {
    return -1;
  }
  if (l == r) {
    return r;
  }
  if ((r - l) == 1) {
    if ((arr[r] <= t && (sum[r] - sum[L - 1]) <= m * t)) {
      return r;
    } else {
      return l;
    }
  }
  long long int mid = (l + r) / 2;
  if (arr[mid] <= t && (sum[mid] - sum[L - 1]) <= m * t) {
    return binarySearch(mid, r, t, m);
  } else {
    return binarySearch(l, mid - 1, t, m);
  }
}
int main() {
  long long int A, B, n, i, l, t, m;
  A = scan();
  B = scan();
  n = scan();
  for (i = 1; i <= 1000000; i++) {
    arr[i] = A + B * (i - 1);
    sum[i] = sum[i - 1] + arr[i];
  }
  while (n--) {
    L = scan();
    t = scan();
    m = scan();
    cout << binarySearch(L, 1000000, t, m) << endl;
  }
  return 0;
}
