#include <bits/stdc++.h>
using namespace std;
set<int> in[100001];
set<int> out[100001];
bool visited[100001];
int N, M;
void delNode(int n) {
  if (!out[n].empty()) return;
  for (int tmp : in[n]) {
    out[tmp].erase(n);
    delNode(tmp);
  }
  in[n].clear();
}
void reduce() {
  vector<int> ones;
  for (int n = 0; n < N; n++) {
    if (out[n].size() == 1) {
      ones.push_back(n);
      visited[n] = true;
    }
  }
  while (ones.size() > 0) {
    int curr = ones.back();
    ones.pop_back();
    auto &cO = out[curr];
    int next = *cO.begin();
    if (curr == next) {
      continue;
    }
    auto &cI = in[curr], &nI = in[next];
    nI.erase(curr);
    nI.insert(cI.begin(), cI.end());
    for (int prev : in[curr]) {
      auto &pO = out[prev];
      pO.erase(curr);
      pO.insert(next);
      if (pO.size() == 1 && !visited[prev]) {
        ones.push_back(prev);
        visited[prev] = true;
      }
    }
    out[curr].clear();
    in[curr].clear();
  }
}
int main() {
  ::std::ios::sync_with_stdio(false);
  ::std::cin.tie(0);
  ::std::cout.tie(0);
  scanf("%d %d", &N, &M);
  int a, b;
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &a, &b);
    a--;
    b--;
    out[a].insert(b);
    in[b].insert(a);
  }
  for (int n = 0; n < N; n++) {
    if (out[n].empty()) {
      delNode(n);
    }
  }
  reduce();
  int answer = -1;
  bool flag = false;
  for (int n = 0; n < N; n++) {
    if (!out[n].empty()) {
      if (answer == -1 && !flag) {
        flag = true;
        answer = n + 1;
      } else {
        answer = -1;
        break;
      }
    }
  }
  printf("%d\n", answer);
  return 0;
}
