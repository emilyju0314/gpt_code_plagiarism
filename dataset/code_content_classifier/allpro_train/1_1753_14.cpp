#include <bits/stdc++.h>
int N;
int V[100005];
std::stack<int> stack;
std::vector<std::pair<char, int>> remember;
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> N;
  int counter = 0;
  char ch;
  bool bOk = true;
  for (int i = 0, x; i < 2 * N; ++i) {
    std::cin >> ch;
    if (ch == '+') {
      ++counter;
      remember.push_back({'+', counter});
      stack.push(counter);
    } else {
      std::cin >> x;
      if (stack.empty()) {
        bOk = false;
      }
      if (!bOk) continue;
      int top = stack.top();
      stack.pop();
      V[top] = x;
      remember.push_back({'-', x});
    }
  }
  std::priority_queue<int> pq;
  for (auto &it : remember) {
    if (it.first == '+') {
      pq.push(-V[it.second]);
    } else {
      int x = it.second;
      if (-pq.top() != x) bOk = false;
      pq.pop();
    }
  }
  if (!bOk) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
    for (int i = 1; i <= N; ++i) std::cout << V[i] << ' ';
  }
  return 0;
}
