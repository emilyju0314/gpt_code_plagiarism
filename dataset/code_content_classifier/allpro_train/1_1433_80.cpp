#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
int N, M, S[MAX_N];
vector<int> tours[MAX_N];
vector<int> end_with[2];
vector<int> parity_last[2][2];
void init() {
  char _S[MAX_N];
  scanf("%s", _S + 1);
  N = strlen(_S + 1);
  for (int i = 1; i <= N; i++) S[i] = _S[i] == 'R';
}
void partition() {
  for (int i = 1; i <= N; i++) {
    if (end_with[S[i] ^ 1].empty()) {
      end_with[S[i] ^ 1].push_back(++M);
    }
    int t = end_with[S[i] ^ 1].back();
    end_with[S[i] ^ 1].pop_back();
    tours[t].push_back(i);
    end_with[S[i]].push_back(t);
  }
  for (int i = 1; i <= M; i++) {
    parity_last[tours[i].size() & 1][S[tours[i].back()]].push_back(i);
  }
}
void adjust() {
  if (M == 1) return;
  if (!parity_last[1][0].empty() || !parity_last[1][1].empty()) return;
  if (parity_last[0][0].empty() || parity_last[0][1].empty()) return;
  int a = parity_last[0][0].back(), b = parity_last[0][1].back();
  parity_last[0][0].pop_back();
  parity_last[0][1].pop_back();
  if (tours[a].front() < tours[b].front()) {
    tours[b].insert(tours[b].begin(), tours[a].front());
    tours[a].erase(tours[a].begin());
  } else {
    tours[a].insert(tours[a].begin(), tours[b].front());
    tours[b].erase(tours[b].begin());
  }
  parity_last[1][0].push_back(a);
  parity_last[1][1].push_back(b);
}
void print(vector<int> v) {
  for (int i : v) {
    printf("%d ", i);
  }
}
void construct() {
  int curr = -1;
  if (parity_last[1][0].size() != parity_last[1][1].size()) {
    curr = parity_last[1][1].size() > parity_last[1][0].size();
  } else {
    curr = parity_last[0][0].size() > parity_last[0][1].size();
  }
  printf("%d\n", M - 1);
  while (!parity_last[0][curr ^ 1].empty()) {
    print(tours[parity_last[0][curr ^ 1].back()]);
    parity_last[0][curr ^ 1].pop_back();
  }
  while (!parity_last[1][curr].empty()) {
    print(tours[parity_last[1][curr].back()]);
    parity_last[1][curr].pop_back();
    while (!parity_last[0][curr].empty()) {
      print(tours[parity_last[0][curr].back()]);
      parity_last[0][curr].pop_back();
    }
    curr ^= 1;
  }
  printf("\n");
}
int main() {
  init();
  partition();
  adjust();
  construct();
}
