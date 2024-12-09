#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
int n;
string s1[maxn], s2[maxn], s3[maxn];
int l1[maxn], l2[maxn], l3[maxn];
char s[maxn];
int cnt[55];
int main() {
  scanf("%d", &n);
  if (n == 1) {
    printf("? 1 1\n");
    fflush(stdout);
    string tmp;
    cin >> tmp;
    cout << "! " << tmp << endl;
    fflush(stdout);
  } else {
    int len1 = n / 2;
    int len2 = n / 2 + 1;
    printf("? 1 %d\n", len1);
    fflush(stdout);
    int num1 = (len1 * (len1 + 1)) / 2;
    for (int i = 1; i <= num1; i++) {
      cin >> s1[i];
      l1[i] = s1[i].length();
    }
    printf("? 1 %d\n", len2);
    fflush(stdout);
    int num2 = (len2 * (len2 + 1)) / 2;
    for (int i = 1; i <= num2; i++) {
      cin >> s2[i];
      l2[i] = s2[i].length();
    }
    for (int i = len2; i >= 1; i--) {
      int cur = len2 - i + 1;
      memset(cnt, 0, sizeof(cnt));
      for (int j = 1; j <= num2; j++) {
        if (l2[j] == cur) {
          for (int k = 0; k < cur; k++) cnt[s2[j][k] - 'a']++;
        }
      }
      for (int j = 1; j <= num1; j++) {
        if (l1[j] == cur) {
          for (int k = 0; k < cur; k++) cnt[s1[j][k] - 'a']--;
        }
      }
      for (int j = i + 1; j <= len2; j++) {
        cnt[s[j] - 'a']--;
      }
      for (int j = 0; j < 26; j++) {
        if (cnt[j]) s[i] = j + 'a';
      }
    }
    printf("? 1 %d\n", n);
    fflush(stdout);
    int num3 = ((n + 1) * n) / 2;
    for (int i = 1; i <= num3; i++) {
      cin >> s3[i];
      l3[i] = s3[i].length();
    }
    for (int i = n; i >= len2 + 1; i--) {
      int cur = n - i + 1;
      memset(cnt, 0, sizeof(cnt));
      for (int j = 1; j <= num3; j++) {
        if (l3[j] == cur) {
          for (int k = 0; k < cur; k++) cnt[s3[j][k] - 'a']++;
        }
        if (l3[j] == cur + 1) {
          for (int k = 0; k <= cur; k++) cnt[s3[j][k] - 'a']--;
        }
        if (l3[j] == 1) cnt[s3[j][0] - 'a']++;
      }
      for (int j = 1; j <= cur; j++) cnt[s[j] - 'a']--;
      for (int j = n; j > i; j--) cnt[s[j] - 'a']--;
      for (int j = 0; j < 26; j++) {
        if (cnt[j]) s[i] = j + 'a';
      }
    }
    printf("! ");
    for (int i = 1; i <= n; i++) printf("%c", s[i]);
    printf("\n");
    fflush(stdout);
  }
  return 0;
}
