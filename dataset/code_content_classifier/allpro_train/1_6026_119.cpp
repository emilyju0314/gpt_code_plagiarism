#include <bits/stdc++.h>
char map[11][11];
int main() {
  for (int i = 0; i < 10; ++i) {
    scanf("%s", map[i]);
  }
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (map[i][j] == '.') {
        int s = 1;
        s = 1;
        for (int k = j - 1; k >= 0; --k) {
          if (map[i][k] == 'X') {
            ++s;
            if (s == 5) {
              printf("YES\n");
              return 0;
            }
          } else
            break;
        }
        for (int k = j + 1; k < 10; ++k) {
          if (map[i][k] == 'X') {
            ++s;
            if (s == 5) {
              printf("YES\n");
              return 0;
            }
          } else
            break;
        }
        s = 1;
        for (int k = i - 1; k >= 0; --k) {
          if (map[k][j] == 'X') {
            ++s;
            if (s == 5) {
              printf("YES\n");
              return 0;
            }
          } else
            break;
        }
        for (int k = i + 1; k < 10; ++k) {
          if (map[k][j] == 'X') {
            ++s;
            if (s == 5) {
              printf("YES\n");
              return 0;
            }
          } else
            break;
        }
        s = 1;
        for (int k = i - 1, q = j - 1; k >= 0 && q >= 0; --k, --q) {
          if (map[k][q] == 'X') {
            ++s;
            if (s == 5) {
              printf("YES\n");
              return 0;
            }
          } else
            break;
        }
        for (int k = i + 1, q = j + 1; k < 10 && q < 10; ++k, ++q) {
          if (map[k][q] == 'X') {
            ++s;
            if (s == 5) {
              printf("YES\n");
              return 0;
            }
          } else
            break;
        }
        s = 1;
        for (int k = i + 1, q = j - 1; k < 10 && q >= 0; ++k, --q) {
          if (map[k][q] == 'X') {
            ++s;
            if (s == 5) {
              printf("YES\n");
              return 0;
            }
          } else
            break;
        }
        for (int k = i - 1, q = j + 1; k >= 0 && q < 10; --k, ++q) {
          if (map[k][q] == 'X') {
            ++s;
            if (s == 5) {
              printf("YES\n");
              return 0;
            }
          } else
            break;
        }
      }
    }
  }
  printf("NO\n");
  return 0;
}
