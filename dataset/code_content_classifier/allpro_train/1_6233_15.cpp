#include <bits/stdc++.h>
using namespace std;
char ch, step1[5000], step2[5000];
int n, now_x, now_y, pre_x, pre_y, ans1, ans2;
bool flag, wal;
int read() {
  int tot = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    tot = tot * 10 + c - '0';
    c = getchar();
  }
  return tot * fh;
}
int main() {
  n = read();
  now_x = 1;
  now_y = 1;
  wal = true;
  while (wal) {
    wal = false;
    flag = false;
    if (now_x + 1 <= n) {
      if (abs(n - (now_x + 1)) + abs(n - now_y) >= n - 1) {
        cout << "? " << now_x + 1 << ' ' << now_y << ' ' << n << ' ' << n
             << endl;
        ch = getchar();
        while (ch >= 'A' && ch <= 'Z') {
          if (ch == 'Y') {
            flag = true;
            wal = true;
            ans1++;
            step1[ans1] = 'D';
            now_x = now_x + 1;
          }
          ch = getchar();
        }
      }
    }
    if (!flag && now_y + 1 <= n) {
      if (abs(n - now_x) + abs(n - (now_y + 1)) >= n - 1) {
        cout << "? " << now_x << ' ' << now_y + 1 << ' ' << n << ' ' << n
             << endl;
        ch = getchar();
        while (ch >= 'A' && ch <= 'Z') {
          if (ch == 'Y') {
            flag = true;
            wal = true;
            ans1++;
            step1[ans1] = 'R';
            now_y = now_y + 1;
          }
          ch = getchar();
        }
      }
    }
  }
  pre_x = n;
  pre_y = n;
  wal = true;
  while (wal) {
    wal = false;
    flag = false;
    if (pre_y - 1 >= 1) {
      if (abs(pre_y - 1 - 1) + abs(pre_x - 1) >= n - 1) {
        cout << "? 1 1 " << pre_x << ' ' << pre_y - 1 << endl;
        ch = getchar();
        while (ch >= 'A' && ch <= 'Z') {
          if (ch == 'Y') {
            flag = true;
            wal = true;
            ans2++;
            step2[ans2] = 'R';
            pre_y = pre_y - 1;
          }
          ch = getchar();
        }
      }
    }
    if (!flag && pre_x - 1 >= 1) {
      if (abs(pre_y - 1) + abs(pre_x - 1 - 1) >= n - 1) {
        cout << "? 1 1 " << pre_x - 1 << ' ' << pre_y << endl;
        ch = getchar();
        while (ch >= 'A' && ch <= 'Z') {
          if (ch == 'Y') {
            flag = true;
            wal = true;
            ans2++;
            step2[ans2] = 'D';
            pre_x = pre_x - 1;
          }
          ch = getchar();
        }
      }
    }
    if (now_x == pre_x && now_y == pre_y) {
      cout << "! ";
      for (int i = 1; i <= ans1; i++) cout << step1[i];
      for (int i = ans2; i >= 1; i--) cout << step2[i];
      cout << endl;
      return 0;
    }
  }
  return 0;
}
