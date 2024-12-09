#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pairInt;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[]) {
  int N, K;

  scanf("%d%d", &N, &K);

  set<int> not_replyed;
  set<int> not_replying;
  multimap<int, int> replying;

  FOR1(i, 1, N + 1) { not_replyed.insert(i); }

  FOR1(i, 1, N + 1) {
    int a;
    scanf("%d", &a);
    if (a != 0) {
      replying.insert(make_pair(i, a));
      not_replyed.erase(a);
    } else {
      not_replying.insert(i);
    }
  }

  set<int> displayed(not_replyed);
  set<int> temp(not_replyed);
  FOR(i, K - 1) {
    set<int> temp2;
    for (auto x : temp) {
      using iterator = decltype(replying)::iterator;
      pair<iterator, iterator> ret = replying.equal_range(x);
      for (auto it = ret.first; it != ret.second; it++) {
        if (displayed.find(it->second) == displayed.end()) {
          temp2.insert(it->second);
          displayed.insert(it->second);
        }
      }
    }
    temp = move(temp2);
    // printf("displayed%d:{", i);
    // for (auto x : displayed) {
    //   printf("%d, ", x);
    // }
    // printf("}\n");
  }
  displayed.insert(not_replying.begin(), not_replying.end());

  printf("%lu\n", displayed.size());

  return 0;
}