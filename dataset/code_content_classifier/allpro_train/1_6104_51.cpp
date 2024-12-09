#include <bits/stdc++.h>
int setBit(int N, int pos) { return N = N | (1 << pos); }
int resetBit(int N, int pos) { return N = N & ~(1 << pos); }
bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
using namespace std;
const long long int MAX = 1005;
long long int n, arr[MAX], key, TC, visit[MAX];
unordered_map<long long int, long long int> mapp;
vector<long long int> v[MAX];
int main() {
  long long int i, j, k, ans = 0;
  scanf("%I64d", &n);
  for (i = 0; i < n; i++) {
    scanf("%I64d", &arr[i]);
    if (mapp.find(arr[i]) == mapp.end()) mapp[arr[i]] = key++;
    v[mapp[arr[i]]].push_back(i);
  }
  if (mapp.find(0) != mapp.end()) ans = (int)v[mapp[0]].size();
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j || (arr[i] == 0 && arr[j] == 0)) continue;
      long long int x = i, y = j, cnt = 2;
      TC++;
      visit[i] = visit[j] = TC;
      while (true) {
        bool done = false;
        long long int z = arr[x] + arr[y];
        if (mapp.find(z) == mapp.end()) break;
        long long int now = mapp[z];
        long long int siz = (int)v[now].size();
        for (k = 0; k < siz; k++) {
          if (visit[v[now][k]] != TC) {
            visit[v[now][k]] = TC;
            swap(x, y);
            y = v[now][k];
            cnt++;
            done = true;
            break;
          }
        }
        if (!done) break;
      }
      ans = max(ans, cnt);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
