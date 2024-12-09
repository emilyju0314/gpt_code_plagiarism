#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
int getResult(int N, int blockSize) {
  int fullBlocks = N / (blockSize + 1);
  return (fullBlocks - 1) * blockSize +
         max(0, N - fullBlocks * (blockSize + 1) - 1);
}
int main() {
  int N;
  cin >> N;
  vector<int> targets;
  set<int> active;
  int bestBlockSize = 1;
  int aim = getResult(N, 1);
  while (getResult(N, bestBlockSize + 1) >= aim) {
    aim = getResult(N, ++bestBlockSize);
  }
  for (__typeof__(10 + 1) i = (1) - ((1) > (10 + 1));
       i != ((10 + 1) - ((1) > (10 + 1))); i += 1 - 2 * ((1) > (10 + 1)))
    ;
  ;
  for (__typeof__(N) i = (0) - ((0) > (N)); i != ((N) - ((0) > (N)));
       i += 1 - 2 * ((0) > (N)))
    if (i % (bestBlockSize + 1) != 0) {
      targets.push_back(i + 1);
    }
  while (aim > int((active).size())) {
    vector<int> todo;
    for (auto it : targets)
      if (active.find(it) == active.end()) todo.push_back(it);
    cout << int((todo).size());
    for (auto it : todo) cout << " " << it;
    cout << endl << flush;
    for (auto it : todo) active.insert(it);
    int r;
    cin >> r;
    --r;
    for (__typeof__(int((todo).size())) k = (0) - ((0) > (int((todo).size())));
         k != ((int((todo).size())) - ((0) > (int((todo).size()))));
         k += 1 - 2 * ((0) > (int((todo).size())))) {
      int p = ((r + k) % N) + 1;
      if (active.find(p) != active.end()) active.erase(p);
    }
  }
  cout << 0 << endl;
  return 0;
}
