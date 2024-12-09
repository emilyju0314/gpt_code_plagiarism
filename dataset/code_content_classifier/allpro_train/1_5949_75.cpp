#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <algorithm>

typedef long long ll;

using namespace std;

const int v=100005;
vector<int> to[v*2];
bool visited[v*2];
vector<int> cnt;

void dfs(int i)
{
  if (visited[i]) return;
  visited[i] = true;
  cnt[i/v]++;
  for (int u : to[i])
  {
    dfs(u);
  }
}
int main()
{
  int N;
  cin >> N;
  for (int i=0;i<N;i++)
  {
    int x,y;
    cin >> x >> y;
    y+=v;
    to[x].push_back(y);
    to[y].push_back(x);
  }
  ll ans = 0;
  for (int i=0;i<v*2;i++)
  {
    if (visited[i]) continue;
    cnt = vector<int>(2, 0);
    dfs(i);
    ans += (ll)cnt[0]*cnt[1];
  }
  ans -= N;
  printf("%lld\n", ans);
  return 0;
}
