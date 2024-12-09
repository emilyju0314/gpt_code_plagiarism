#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  scanf("%d", &t);
  string str1, str2;
  while (t--) {
    bool isPossible = false;
    cin >> str1;
    cin >> str2;
    unordered_map<char, char> map;
    for (char i : str1) {
      map.insert(make_pair(i, i));
    }
    for (char i : str2) {
      if (map[i] == i) {
        isPossible = true;
        break;
      }
    }
    if (isPossible)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
