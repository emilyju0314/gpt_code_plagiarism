#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
vector<int> up, down;
int main() {
  int T, n;
  char ch;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    up.clear();
    down.clear();
    for (int i = 1; i < n; i += 2) {
      printf("? %d %d\n", i, i + 1);
      fflush(stdout);
      cin >> ch;
      if (ch == '<')
        down.push_back(i), up.push_back(i + 1);
      else
        down.push_back(i + 1), up.push_back(i);
    }
    if (n & 1) down.push_back(n), up.push_back(n);
    int Min = down[0], Max = up[0];
    for (int i = 1; i < down.size(); i++) {
      printf("? %d %d\n", Min, down[i]);
      fflush(stdout);
      cin >> ch;
      if (ch == '>') Min = down[i];
    }
    for (int i = 1; i < up.size(); i++) {
      printf("? %d %d\n", Max, up[i]);
      fflush(stdout);
      cin >> ch;
      if (ch == '<') Max = up[i];
    }
    printf("! %d %d\n", Min, Max);
    fflush(stdout);
  }
}
