#include <bits/stdc++.h>
using namespace std;
char str[3010][3010], pat[3010][3010];
int ans[1010][1010];
void draw(int hei, int w) {
  ans[hei][0] = 1;
  for (int i = 1; i < w; i++)
    ans[hei][i] =
        (pat[hei * 2][i - 1] == 'E') ? ans[hei][i - 1] : (ans[hei][i - 1] ^ 1);
}
void output(int h, int w, bool re) {
  int i, j;
  cout << "YES" << endl;
  if (!re) {
    for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
        if (j) cout << " ";
        cout << ans[i][j] + 1;
      }
      cout << endl;
    }
  } else {
    for (i = 0; i < w; i++) {
      for (j = 0; j < h; j++) {
        if (j) cout << " ";
        cout << ans[j][i] + 1;
      }
      cout << endl;
    }
  }
}
int main() {
  int i, j;
  int clr;
  int h, w;
  int Q = 0;
  int cnt;
  cin >> h >> w >> clr;
  for (i = 0; i < 2 * h - 1; i++) {
    cin >> str[i];
    Q += strlen(str[i]);
  }
  if (clr == 1) {
    cnt = 0;
    for (i = 0; i < 2 * h - 1; i++)
      for (j = 0; str[i][j]; j++) cnt += (str[i][j] == 'E');
    if (cnt * 4 < Q * 3)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
          if (j) cout << " ";
          cout << "1";
        }
        cout << endl;
      }
    }
    return 0;
  }
  int needReve = 2;
  while (needReve--) {
    if ((needReve % 2) ^ 1) {
      for (i = 0; i < 2 * w - 1; i++) {
        if (i % 2) {
          for (j = 0; j < h; j++) {
            pat[i][j] = str[2 * j][i / 2];
          }
          pat[i][j] = '\0';
        } else {
          for (j = 0; j < h - 1; j++) {
            pat[i][j] = str[2 * j + 1][i / 2];
          }
          pat[i][j] = '\0';
        }
      }
      swap(w, h);
    } else {
      for (i = 0; i < 2 * h - 1; i++) strcpy(pat[i], str[i]);
    }
    cnt = 0;
    for (i = 0; i < h; i++) {
      draw(i, w);
      cnt += w - 1;
      if (i) {
        int t = 0;
        for (j = 0; j < w; j++)
          t +=
              ((ans[i - 1][j] == ans[i][j]) ^ (pat[(i - 1) * 2 + 1][j] == 'N'));
        if (t + t < w) {
          for (j = 0; j < w; j++) ans[i][j] ^= 1;
          t = 0;
          for (j = 0; j < w; j++)
            t += ((ans[i - 1][j] == ans[i][j]) ^
                  (pat[(i - 1) * 2 + 1][j] == 'N'));
        }
        cnt += t;
      }
    }
    if (cnt * 4 >= 3 * Q) {
      if ((needReve % 2) ^ 1)
        output(h, w, 1);
      else
        output(h, w, 0);
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
