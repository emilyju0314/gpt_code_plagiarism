#include <bits/stdc++.h>
using namespace std;
int n, m;
char arr[1000][1000];
int indexof(char ch, int k) {
  for (int i = 0; i < m; i++) {
    if (arr[k][i] == ch) return i;
  }
  return -1;
}
int main() {
  cin >> n >> m;
  char ch;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int indexG = indexof('G', i);
    int indexS = indexof('S', i);
    if (indexG > indexS) {
      cout << -1;
      return 0;
    }
    v.push_back(indexS - indexG);
  }
  sort(v.begin(), v.end());
  int count = 1;
  for (int i = 1; i < v.size(); i++)
    if (v[i - 1] != v[i]) count++;
  cout << count;
  return 0;
}
