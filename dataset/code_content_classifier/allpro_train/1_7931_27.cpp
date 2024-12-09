#include <bits/stdc++.h>
using namespace std;
int level;
char *temp;
char str[1000005], name[1000005];
vector<string> v[1000005];
void bt(int x) {
  int child;
  sscanf(temp, "%s", name);
  temp = strtok(NULL, ",");
  sscanf(temp, "%d", &child);
  temp = strtok(NULL, ",");
  v[x].push_back(name);
  for (int i = 0; i < child; i++) bt(x + 1);
  level = max(x, level);
}
int main() {
  level = 0;
  gets(str);
  temp = strtok(str, ",");
  while (temp != NULL) {
    bt(1);
  }
  printf("%d\n", level);
  for (int i = 1; i <= level; i++) {
    for (int j = 0; j < (int)v[i].size(); j++) {
      if (j > 0) putchar(' ');
      printf("%s", v[i][j].c_str());
    }
    printf("\n");
  }
  return 0;
}
